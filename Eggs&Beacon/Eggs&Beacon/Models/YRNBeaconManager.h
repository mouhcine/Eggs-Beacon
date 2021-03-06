//
//  YRNBeaconManager.h
//  Eggs&Beacon
//
//  Created by Marco on 08/12/13.
//  Copyright (c) 2013 Yron Lab. All rights reserved.
//

@import CoreLocation;
@import CoreBluetooth;

#import "CLBeaconRegion+YRNBeaconManager.h"

@class YRNBeaconManager;

/**
 *  The `YRNBeaconManagerDelegate` protocol defines the methods used to receive beacon ranging and region entering 
 *  or exit updates from a `YRNBeaconManager` object.
 */
@protocol YRNBeaconManagerDelegate <NSObject>

@optional

/**
 *  Tells the delegate that the user entered the specified beacon region.
 *
 *  @param manager The beacon manager object reporting the event.
 *  @param region  The beacon region that was entered.
 */
- (void)beaconManager:(YRNBeaconManager *)manager didEnterRegion:(CLBeaconRegion *)region;

/**
 *  Tells the delegate that the user left the specified beacon region.
 *
 *  @param manager The beacon manager object reporting the event.
 *  @param region  The beacon region that was left.
 */
- (void)beaconManager:(YRNBeaconManager *)manager didExitRegion:(CLBeaconRegion *)region;

/**
 *  Tells the delegate that one or more beacons are in range.
 *
 *  @param manager The beacon manager object reporting the event.
 *  @param beacons An array of CLBeacon objects representing the beacons currently in range.
 *  @param region  The region object containing the parameters that were used to locate the beacons.
 */
- (void)beaconManager:(YRNBeaconManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;

/**
 *  Tells the delegate that the bluetooth state did change.
 *
 *  @param manager The beacon manager object reporting the event.
 *  @param state   The bluetooth state
 */
- (void)beaconManager:(YRNBeaconManager *)manager didUpdateBluetoothState:(CBCentralManagerState)state;

@end

/**
 *  The `YRNBeaconManager` class defines the interface for configuring the delivery of iBeacons ranging and
 *  regions entry and exits events to your application. You can use an instance of this class to monitor specific beacon 
 *  regions to monitor.
 */
@interface YRNBeaconManager : NSObject

/**
 *  The delegate.
 */
@property (nonatomic, weak) id<YRNBeaconManagerDelegate> delegate;

/**
 *  Starts monitoring a beacon region.
 *
 *  @param region A CLBeaconRegion object. This parameter must not be nil.
 *  @param error  If an error occurs, upon return contains an NSError object that describes the problem.
 *
 *  @return YES if the beacon region is registered, NO otherwise.
 */
- (BOOL)registerBeaconRegion:(CLBeaconRegion *)region error:(NSError * __autoreleasing *)error;

/**
 *  Starts monitoring a list of beacon regions.
 *
 *  @param regions An array of CLBeaconRegion objects.
 *  @param error  If an error occurs, upon return contains an NSError object that describes the problem.
 *
 *  @return YES if the beacon regions are registered, NO otherwise.
 */
- (BOOL)registerBeaconRegions:(NSArray *)regions error:(NSError * __autoreleasing *)error;

/**
 *  Returns the current state of bluetooth on the device.
 *
 *  @return The current state of bluetooth on the device.
 */
- (CBCentralManagerState)bluetoothState;

@end
