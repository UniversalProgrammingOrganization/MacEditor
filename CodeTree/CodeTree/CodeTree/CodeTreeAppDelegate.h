//
//  CodeTreeAppDelegate.h
//  CodeTree
//
//  Created by daniel on 9/20/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "TheView.h"

@interface CodeTreeAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *window;
    NSPersistentStoreCoordinator *__persistentStoreCoordinator;
    NSManagedObjectModel *__managedObjectModel;
    NSManagedObjectContext *__managedObjectContext;
		TheView *_theView;
	NSLevelIndicator *_theLevelIndicator;
}

@property (assign) IBOutlet NSWindow *window;

@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (assign) IBOutlet TheView *theView;
@property (assign) IBOutlet NSLevelIndicator* theLevelIndicator;

- (IBAction)saveAction:sender;

@end
