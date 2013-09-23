//
//  TheView.m
//  CodeTree
//
//  Created by daniel on 9/20/13.
//  Copyright 2013 Daniel Randall. All rights reserved.
//

#import "TheView.h"
#include <Carbon/Carbon.h>
#import "CodeTreeAppDelegate.h"

@implementation TheView

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
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
	CodeTreeAppDelegate* d = NSApplication.sharedApplication.delegate;
	
	unsigned short keyCode = [theEvent keyCode];
	NSUInteger modifierFlags = [theEvent modifierFlags];

	if (modifierFlags & NSShiftKeyMask)
	{
		if (keyCode == kVK_ANSI_LeftBracket)
		{
			[d.theLevelIndicator setIntValue:[d.theLevelIndicator intValue] + 1];
			
			NSLog(@"\n open \n");		
		}
		else if (keyCode == kVK_ANSI_RightBracket)
		{
			[d.theLevelIndicator setIntValue:[d.theLevelIndicator intValue] - 1];
			
			NSLog(@"\n close \n");		
		}
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



@end
