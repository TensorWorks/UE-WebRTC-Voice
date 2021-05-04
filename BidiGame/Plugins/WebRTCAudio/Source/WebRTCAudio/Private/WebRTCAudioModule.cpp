// Copyright TensorWorks, Pty Ltd. All Rights Reserved. Licensed under the MIT license.

#include "WebRTCAudioModule.h"

#define LOCTEXT_NAMESPACE "FWebRTCAudioModule"

void FWebRTCAudioModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FWebRTCAudioModule::InitWebRTC);
}

void FWebRTCAudioModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FWebRTCAudioModule::InitWebRTC()
{
	this->WebRTCInstance = MakeUnique<FWebRTCInstance>();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWebRTCAudioModule, WebRTCAudio)