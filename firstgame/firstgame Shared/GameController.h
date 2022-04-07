//
//  GameController.h
//  firstgame Shared
//
//  Created by Tae Keun Jeong on 04.08.21.
//

#import <SceneKit/SceneKit.h>


@interface GameController : NSObject <SCNSceneRendererDelegate>

@property (strong, readonly) SCNScene *scene;
@property (strong, readonly) id <SCNSceneRenderer> sceneRenderer;

- (instancetype)initWithSceneRenderer:(id <SCNSceneRenderer>)sceneRenderer;

- (void)highlightNodesAtPoint:(CGPoint)point;

@end
