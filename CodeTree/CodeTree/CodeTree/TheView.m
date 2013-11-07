/*
CodeTree - A whitespace-agnostic, context-oriented code editor
Copyright (C) 2013  Daniel Randall

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
