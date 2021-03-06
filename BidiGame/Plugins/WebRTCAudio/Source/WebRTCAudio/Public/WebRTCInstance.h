// Copyright TensorWorks, Pty Ltd. All Rights Reserved. Licensed under the MIT license.

#pragma once

#include "CoreMinimal.h"
#include "WebRTCIncludes.h"

/**
 * Creates a WebRTC peer in UE, much the same as how a web browser would do.
 */
class WEBRTCAUDIO_API FWebRTCInstance
{
public:
	FWebRTCInstance();
	~FWebRTCInstance();

private:
	// Functions

private:
	// Members
	rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface> PeerConnectionFactory;

};
