//
//  TheView.m
//  CodeTree
//
//  Created by daniel on 9/20/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
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

-(void)keyDown:(NSEvent *)theEvent
{
	CodeTreeAppDelegate* d = NSApplication.sharedApplication.delegate;
	
	if ([theEvent keyCode] == kVK_ANSI_LeftBracket)
	{
		[d.theLevelIndicator setIntValue:[d.theLevelIndicator intValue] + 1];
		
		NSLog(@"\n open \n");		
	}
	else if ([theEvent keyCode] == kVK_ANSI_RightBracket)
	{
		[d.theLevelIndicator setIntValue:[d.theLevelIndicator intValue] - 1];
		
		NSLog(@"\n close \n");		
	}
	
	[super keyDown:theEvent];
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
