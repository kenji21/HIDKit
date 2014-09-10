//
//  HIDValue.h
//  HIDKit
//
//  Created by Robert Luis Hoover on 9/8/14.
//  Copyright (c) 2014 ars draconis. All rights reserved.
//

#import <Foundation/Foundation.h>
@import IOKit.hid;

@class HIDElement;

/**
	HIDValue defines a value at a given time from an HIDElement. It is used to
	obtain either integer or data element values along with scaled values based
	on physical or calibrated settings.
 */
@interface HIDValue : NSObject

/**
	Creates a new HIDValue with data provided by a NSData object.
	
	@param data An NSData object with the byte data to copy to this object.
	@param element The parent HIDElement of this object.
 
	@returns A new HIDValue object, or nil if it could not be created.
 */
- (instancetype)initWithData:(NSData *)data element:(HIDElement *)element;

/**
	Creates a new HIDValue with data copied from a buffer of bytes.
	
	@param bytes A pointer to a buffer of byte data to copy to this object.
	@param length The length of the data in the buffer.
	@param element The parent HIDElement of this object.
 
	@returns A new HIDValue object, or nil if it could not be created.
 */
- (instancetype)initWithBytes:(const uint8_t *)bytes length:(NSUInteger)length element:(HIDElement *)element;

/**
	Creates a new HIDValue with the data contained in a buffer of bytes. The new
	object will take ownership of the data.
	
	@param bytes A pointer to a buffer of byte data to use in this object.
 	@param length The length of the data in the buffer.
	@param element The parent HIDElement of this object.
 
	@returns A new HIDValue object, or nil if it could not be created.
 */
- (instancetype)initWithBytesNoCopy:(const uint8_t *)bytes length:(NSUInteger)length element:(HIDElement *)element;

/**
	Creates a new HIDValue from a specified integer value.
	
	@param value The integer value to use for the new object.
	@param element The parent HIDElement of this object.
 
	@returns A new HIDValue object, or nil if it could not be created.
 */
- (instancetype)initWithInteger:(NSInteger)value element:(HIDElement *)element;

/// The HIDElement associated with this value.
@property (readonly) HIDElement *element;

/// A pointer to the raw byte data contained in the object.
@property (readonly, nonatomic) const void * bytes;
/// The length of the raw byte data contained in the object.
@property (readonly, nonatomic) NSUInteger length;

/// The timestamp given to the object at the time of its creation.
@property (readonly, nonatomic) uint64_t timeStamp;

/// The representation of the value contained in the object, scaled using the
/// physical bounds of the device.
@property (readonly, nonatomic) CGFloat scaledPhysicalValue;
/// The representation of the value contained in the object, scaled between -1
/// and 1, while taking into account the calibration properties of the element.
@property (readonly, nonatomic) CGFloat scaledCalibratedValue;


@end