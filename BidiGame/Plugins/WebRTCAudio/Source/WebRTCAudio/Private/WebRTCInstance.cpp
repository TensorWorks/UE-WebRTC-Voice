// Copyright TensorWorks, Pty Ltd. All Rights Reserved. Licensed under the MIT license.


#include "WebRTCInstance.h"


FWebRTCInstance::FWebRTCInstance()
{
    //ToDo: Create PeerConnectionFactory etc to start WebRTC in UE.

    // this->PeerConnectionFactory = webrtc::CreatePeerConnectionFactory(
	// 	nullptr, // network_thread
	// 	nullptr, // worker_thread
	// 	nullptr, // signal_thread
	// 	new rtc::RefCountedObject<FPixelStreamingAudioDeviceModule>(), // audio device manager //ToDo capture UE audio submix.
	// 	webrtc::CreateAudioEncoderFactory<webrtc::AudioEncoderOpus>(),
	// 	webrtc::CreateAudioDecoderFactory<webrtc::AudioDecoderOpus>(),
	// 	nullptr, // video encoder factory
	// 	nullptr, //video decoder factory
	// 	nullptr, // audio_mixer
	// 	nullptr); // audio_processing

}

FWebRTCInstance::~FWebRTCInstance()
{
}
