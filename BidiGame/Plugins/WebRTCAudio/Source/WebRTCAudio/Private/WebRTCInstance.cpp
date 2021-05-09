// Copyright TensorWorks, Pty Ltd. All Rights Reserved. Licensed under the MIT license.


#include "WebRTCInstance.h"


FWebRTCInstance::FWebRTCInstance()
{
    //ToDo: Create PeerConnectionFactory etc to start WebRTC in UE.

	// For each received audio track, set a sink on that audio track
	// The audio sink can output raw audio data to UE or wherever
	// See AudioTrackSinkInterface OnData()

    this->PeerConnectionFactory = webrtc::CreatePeerConnectionFactory(
		nullptr, // network_thread
		nullptr, // worker_thread
		nullptr, // signal_thread
		nullptr, // audio device module, could be like as FAudioCapturer or FAudioRenderer
		webrtc::CreateAudioEncoderFactory<webrtc::AudioEncoderOpus>(),
		webrtc::CreateAudioDecoderFactory<webrtc::AudioDecoderOpus>(),
		nullptr, // video encoder factory
		nullptr, //video decoder factory
		nullptr, // audio_mixer
		nullptr); // audio_processing

}

FWebRTCInstance::~FWebRTCInstance()
{
}
