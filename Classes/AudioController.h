/*
 
     File: AudioController.h
 Abstract: This class demonstrates the audio APIs used to capture audio data from the microphone and play it out to the speaker. It also demonstrates how to play system sounds
  Version: 2.0
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc. may
 be used to endorse or promote products derived from the Apple Software
 without specific prior written permission from Apple.  Except as
 expressly stated in this notice, no other rights or licenses, express or
 implied, are granted by Apple herein, including but not limited to any
 patent rights that may be infringed by your derivative works or by other
 works in which the Apple Software may be incorporated.
 
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
 Copyright (C) 2014 Apple Inc. All Rights Reserved.
 
 
 */

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

#import "BufferManager.h"
#import "DCRejectionFilter.h"

//===DBC===//
extern Float32 saveIOData[184320];
extern UInt32 saveCount;
extern UInt32 threeSecCount;
extern UInt32 curScale;
//===DBC===//

@interface AudioController : NSObject {
    
    AudioUnit               _rioUnit;
    BufferManager*          _bufferManager;
    DCRejectionFilter*      _dcRejectionFilter;
    AVAudioPlayer*          _audioPlayer;   // for button pressed sound
    BOOL                    _audioChainIsBeingReconstructed;
}

@property (nonatomic, assign) BOOL muteAudio;
@property (nonatomic, assign) BOOL indoor;
@property (nonatomic, assign) BOOL outdoor;
@property (nonatomic, assign) BOOL playBack;


@property (nonatomic, assign, readonly) BOOL audioChainIsBeingReconstructed;

- (BufferManager*) getBufferManagerInstance;
- (OSStatus)    startIOUnit;
- (OSStatus)    stopIOUnit;
- (void)        playButtonPressedSound;
- (double)      sessionSampleRate;
static void scaleVolumn( Float32* inData, UInt32 inNumFrames,UInt32 scale );
static void saveAudio(Float32* inData, UInt32 inNumFrames);
static void playPastAudio( Float32* inData, UInt32 inNumFrames);
static void playPast3Seconds( Float32* inData, UInt32 inNumFrames);

@end
