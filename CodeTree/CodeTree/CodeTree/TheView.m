//
//  TheView.m
//  CodeTree
//
//  Created by daniel on 9/20/13.
//  Copyright 2013 Daniel Randall. All rights reserved.
//

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

// currently accepting only "{" and "}" as input:
-(void)keyDown:(NSEvent *)theEvent
{
	CodeTreeAppDelegate* appDelegate = NSApplication.sharedApplication.delegate;
	
	unsigned short keyCode = [theEvent keyCode];
	NSUInteger modifierFlags = [theEvent modifierFlags];

	if (modifierFlags & NSShiftKeyMask)
	{
		if (keyCode == kVK_ANSI_LeftBracket)
		{
			[appDelegate.theLevelIndicator setIntValue:[appDelegate.theLevelIndicator intValue] + 1];
			
			[appDelegate.theText setStringValue:[NSString stringWithFormat:@"%@%@", appDelegate.theText.stringValue, @"\n{\n\t"]];
		}
		else if (keyCode == kVK_ANSI_RightBracket)
		{
			[appDelegate.theLevelIndicator setIntValue:[appDelegate.theLevelIndicator intValue] - 1];
			
			[appDelegate.theText setStringValue:[NSString stringWithFormat:@"%@%@", appDelegate.theText.stringValue, @"\n}\n"]];
		}
		else
		{
			[self interpretKeyEvents:[NSArray arrayWithObject:theEvent]];
		}
	}
	else if (keyCode == kVK_Return)
	{
		[appDelegate.theText setStringValue:[NSString stringWithFormat:@"%@%@", appDelegate.theText.stringValue, @"\n"]];
	}
	else
	{
		[self interpretKeyEvents:[NSArray arrayWithObject:theEvent]];
	}

	// calling this superclass method makes annoying sounds; so not doing it:
	//[super keyDown:theEvent];
}

// render the indentation:
-(void)insertIndent
{
	CodeTreeAppDelegate* d = NSApplication.sharedApplication.delegate;


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
	CodeTreeAppDelegate* d = NSApplication.sharedApplication.delegate;

  [d.theText setStringValue:[NSString stringWithFormat:@"%@%@", d.theText.stringValue, string]];
}

@end
