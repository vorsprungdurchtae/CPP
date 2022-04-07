//
//  InterfaceController.m
//  firstgame watchOS App Extension
//
//  Created by Tae Keun Jeong on 04.08.21.
//

#import "InterfaceController.h"
#import "GameController.h"

@interface InterfaceController ()

@property (strong, nonatomic) IBOutlet WKInterfaceSCNScene *scnInterface;
@property (strong, nonatomic) GameController *gameController;

@end

@implementation InterfaceController

- (void)awakeWithContext:(id)context {
    [super awakeWithContext:context];
    
    self.gameController = [[GameController alloc] initWithSceneRenderer:self.scnInterface];
}

- (IBAction)handleTap:(WKTapGestureRecognizer *)gestureRecognize {
    // Highlight the tapped nodes
    CGPoint p = gestureRecognize.locationInObject;
    [self.gameController highlightNodesAtPoint:p];
}

- (void)willActivate {
    // This method is called when watch view controller is about to be visible to user
    [super willActivate];
}

- (void)didDeactivate {
    // This method is called when watch view controller is no longer visible
    [super didDeactivate];
}

@end
