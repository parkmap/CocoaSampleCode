/*
	File:			VendorSpecificType00.cpp
	
	Description:	This sample demonstrates how to subclass the IOSCSIPeripheralDeviceType00 driver
					to add custom vendor-specific functionality. It also shows how to set up a simple
					interface from user space code using I/O Registry properties.
                
	Copyright:		� Copyright 2002-2006 Apple Computer, Inc. All rights reserved.
	
	Disclaimer:		IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
					("Apple") in consideration of your agreement to the following terms, and your
					use, installation, modification or redistribution of this Apple software
					constitutes acceptance of these terms.  If you do not agree with these terms,
					please do not use, install, modify or redistribute this Apple software.

					In consideration of your agreement to abide by the following terms, and subject
					to these terms, Apple grants you a personal, non-exclusive license, under Apple’s
					copyrights in this original Apple software (the "Apple Software"), to use,
					reproduce, modify and redistribute the Apple Software, with or without
					modifications, in source and/or binary forms; provided that if you redistribute
					the Apple Software in its entirety and without modifications, you must retain
					this notice and the following text and disclaimers in all such redistributions of
					the Apple Software.  Neither the name, trademarks, service marks or logos of
					Apple Computer, Inc. may be used to endorse or promote products derived from the
					Apple Software without specific prior written permission from Apple.  Except as
					expressly stated in this notice, no other rights or licenses, express or implied,
					are granted by Apple herein, including but not limited to any patent rights that
					may be infringed by your derivative works or by other works in which the Apple
					Software may be incorporated.

					The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
					WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
					WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
					PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
					COMBINATION WITH YOUR PRODUCTS.

					IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
					CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
					GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
					ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
					OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
					(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
					ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
				
	Change History (most recent first):
        
            1.1		08/31/2006			Updated to produce a universal binary. Now requires Xcode 2.2.1 or
										later to build.

            1.0	 	08/15/2002			New sample.
        
*/

#include "VendorSpecificType00.h"
#include <IOKit/storage/IOBlockStorageDriver.h>

#ifdef DEBUG
#define DEBUG_LOG IOLog
#else
#define DEBUG_LOG(...)
#endif

#define super IOSCSIPeripheralDeviceType00
OSDefineMetaClassAndStructors(com_apple_dts_driver_VendorSpecificType00, IOSCSIPeripheralDeviceType00)

// This function will be called when the user process calls IORegistryEntrySetCFProperties on
// this driver. You can add your custom functionality to this function.
IOReturn com_apple_dts_driver_VendorSpecificType00::setProperties(OSObject* properties)
{
    OSDictionary*	dict;
    OSNumber*		number;

    dict = OSDynamicCast(OSDictionary, properties);
    if (!dict) {
        return kIOReturnBadArgument;
    }
    
    number = OSDynamicCast(OSNumber, dict->getObject(kMyPropertyKey));
    if (number) {
        UInt32 value
#ifndef DEBUG
			__attribute__ ((unused)) // Avoid compiler warning for unused variable when building Release configuration.
#endif
			= number->unsigned32BitValue();
        
		DEBUG_LOG("%s[%p]::%s(%p) got value %lu\n", getName(), this, __FUNCTION__, properties, value);
        return kIOReturnSuccess;
    }
    else {
        return super::setProperties(properties);
	}
}

// Padding for future binary compatibility.
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 0);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 1);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 2);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 3);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 4);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 5);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 6);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 7);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 8);
OSMetaClassDefineReservedUnused(com_apple_dts_driver_VendorSpecificType00, 9);
