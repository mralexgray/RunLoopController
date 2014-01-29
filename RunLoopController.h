#import <Foundation/Foundation.h>

@interface RunLoopController : NSObject <NSMachPortDelegate> {
    NSMachPort *_terminatePort;
    BOOL _terminate;
}

/**
 * Get the number of registered instances.
 *
 * This value can be used to decide to terminate the main thread when no
 * more worker threads exist.
 *
 * @return The number of registered instances.
 */
+ (NSInteger)instanceCount;

/**
 * Run the current run loop.  This is a shortcut for:
 * calling runMode:NSDefaultRunLoopModebeforeDate:[NSDate distantFuture]
 *
 * @return NO if the run loop was asked to terminate, or an error occurred. YES if
 * the run loop finished for another reason.
 */
- (BOOL)run;

/**
 * Run the current run loop.
 *
 * @param mode As per [NSRunLoop runMode:limitDate:].
 * @param limitDate As per [NSRunLoop runMode:limitDate:].
 *
 * @return NO if the run loop was asked to terminate, or an error occurred. YES if
 * the run loop finished for another reason.
 */
- (BOOL)runMode:(NSString *)mode
     beforeDate:(NSDate *)limitDate;

/**
 * Signal the run loop to terminate.
 */
- (void)terminate;

/**
 * Determine if the run loop was terminated via this controller
 *
 * @return YES if the run loop should terminate, else NO.
 */
- (BOOL)shouldTerminate;

@end
