// Copyright TensorWorks, Pty Ltd. All Rights Reserved. Licensed under the MIT license.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "WebRTCInstance.h"

/**
 * This plugin allows WebRTC audio to received in UE, processed, then transmitted using WebRTC.
 */
class FWebRTCAudioModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void InitWebRTC();

private:
	TUniquePtr<FWebRTCInstance> WebRTCInstance;

};
