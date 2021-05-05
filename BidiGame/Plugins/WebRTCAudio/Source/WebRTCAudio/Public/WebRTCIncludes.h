// Copyright TensorWorks, Pty Ltd. All Rights Reserved. Licensed under the MIT license.

#pragma once

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/AllowWindowsPlatformAtomics.h"

THIRD_PARTY_INCLUDES_START

// WebRTC requires `htonll` to be defined, which depends either on `NTDDI_VERION` value or
// `INCL_EXTRA_HTON_FUNCTIONS` to be defined
#if !defined(INCL_EXTRA_HTON_FUNCTIONS)
#	if defined(UNDEF_INCL_EXTRA_HTON_FUNCTIONS)
#		pragma message(": Error: `UNDEF_INCL_EXTRA_HTON_FUNCTIONS` already defined, use another name")
#	endif
#	define UNDEF_INCL_EXTRA_HTON_FUNCTIONS
#	define INCL_EXTRA_HTON_FUNCTIONS
#endif

// C4582/3: constructor/desctructor is not implicitly called in "api/rtcerror.h", treated as an error by UnrealEngine
// for some unknown reasons we have to disable it inside those Unreal's windows-related includes
// C6323: Use of arithmetic operator on Boolean type(s).
#pragma warning(push)
#pragma warning(disable: 4582 4596 6323)

#include "rtc_base/win32.h"
#include "rtc_base/win32_socket_init.h"
#include "rtc_base/win32_socket_server.h"

// uses Win32 Interlocked* functions
#include "rtc_base/ref_counted_object.h"

#pragma warning(pop)

#if defined(UNDEF_INCL_EXTRA_HTON_FUNCTIONS)
#	undef UNDEF_INCL_EXTRA_HTON_FUNCTIONS
#	undef INCL_EXTRA_HTON_FUNCTIONS
#endif

THIRD_PARTY_INCLUDES_END

#include "Windows/HideWindowsPlatformAtomics.h"
#include "Windows/HideWindowsPlatformTypes.h"

#endif // PLATFORM_WINDOWS

THIRD_PARTY_INCLUDES_START

// C4582: constructor is not implicitly called in "api/rtcerror.h", treated as an error by UnrealEngine
// C6319: Use of the comma-operator in a tested expression causes the left argument to be ignored when it has no side-effects.
// C6323: Use of arithmetic operator on Boolean type(s).
#pragma warning(push)
#pragma warning(disable: 4582 4583 6319 6323)

#include "api/scoped_refptr.h"
#include "api/peer_connection_interface.h"
#include "api/create_peerconnection_factory.h"
#include "api/audio_codecs/audio_decoder_factory_template.h"
#include "api/audio_codecs/audio_encoder_factory_template.h"
#include "api/audio_codecs/opus/audio_decoder_opus.h"
#include "api/audio_codecs/opus/audio_encoder_opus.h"
#include "api/audio_codecs/builtin_audio_encoder_factory.h"

#include "media/engine/internal_decoder_factory.h"
#include "media/engine/internal_encoder_factory.h"


#pragma warning(pop)

 // because WebRTC uses STL
#include <string>
#include <memory>

THIRD_PARTY_INCLUDES_END