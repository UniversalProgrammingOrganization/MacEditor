/*
Copyright (c) 2013, Daniel Randall
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

* Neither the name of the Universal Programming Organization nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import "CodeTreeAppDelegate.h"
#import "TheView.h"
#include <Carbon/Carbon.h>
#import "CodeTreeAppDelegate.h"

@implementation TheView

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];

		if (self)
		{

    }
    
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

- (void)drawRect:(NSRect)dirtyRect
{
    // Drawing code here.
}

-(void)awakeFromNib
{
	appDelegate = NSApplication.sharedApplication.delegate;
}

// render the indentation:
-(void)insertIndents
{
	[appDelegate.theText setStringValue:
	 [NSString stringWithFormat:
		@"%@%@", appDelegate.theText.stringValue, @"\n"]];
	
	for (int i = 0; i < [appDelegate.theLevelIndicator intValue]; i++)
	{
		[appDelegate.theText setStringValue:
		 [NSString stringWithFormat:
			@"%@%@", appDelegate.theText.stringValue, @"\t"]];
	}
}

// currently accepting only "{" and "}" as input:
-(void)keyDown:(NSEvent *)theEvent
{
	unsigned short keyCode = [theEvent keyCode];
	NSUInteger modifierFlags = [theEvent modifierFlags];

	if (modifierFlags & NSShiftKeyMask)
	{
		if (keyCode == kVK_ANSI_LeftBracket)
		{
			[self insertIndents];		
			
			[appDelegate.theLevelIndicator setIntValue:
				[appDelegate.theLevelIndicator intValue] + 1];
			
			[appDelegate.theText setStringValue:
				[NSString stringWithFormat:
					@"%@%@", appDelegate.theText.stringValue, @"{"]];
			
			[self insertIndents];		
		}
		else if (keyCode == kVK_ANSI_RightBracket)
		{
			[appDelegate.theLevelIndicator setIntValue:
			 [appDelegate.theLevelIndicator intValue] - 1];

			[self insertIndents];		

			[appDelegate.theText setStringValue:
			 [NSString stringWithFormat:
				@"%@%@", appDelegate.theText.stringValue, @"}"]];
			
			[self insertIndents];		
		}
		else
		{
			[self interpretKeyEvents:[NSArray arrayWithObject:theEvent]];
		}
	}
	else if (keyCode == kVK_Return)
	{
		[self insertIndents];		
	}
	else
	{
		[self interpretKeyEvents:[NSArray arrayWithObject:theEvent]];
	}

	// calling this superclass method makes annoying sounds; so not doing it:
	//[super keyDown:theEvent];
}

-(BOOL)canBecomeKeyView
{
	return true;
}

- (BOOL)acceptsFirstResponder 
{
	return true;
}

- (void)insertText:(id)string
{
  [appDelegate.theText setStringValue:
		[NSString stringWithFormat:
			@"%@%@", appDelegate.theText.stringValue, string]];
}

@end
