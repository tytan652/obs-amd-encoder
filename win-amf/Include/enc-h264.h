/*
MIT License

Copyright (c) 2016 Michael Fabian Dirks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
//////////////////////////////////////////////////////////////////////////
// Includes
//////////////////////////////////////////////////////////////////////////
// System
#include <exception>
#include <stdexcept>
#include <vector>

// Plugin
#include "win-amf.h"

// AMF
#include "AMD-Media-SDK/1.1/inc/ErrorCodes.h"
#include "AMD-Media-SDK/1.1/inc/amf/components/Component.h"
#include "AMD-Media-SDK/1.1/inc/amf/components/VideoEncoderVCE.h"

//////////////////////////////////////////////////////////////////////////
// Defines
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////
namespace AMFEncoder {
	/**
	 * Class for the actual AMF Encoder.
	 * 
	 */
	class H264 {
		public:
		H264();
		~H264();


		void Startup(H264_Usage Usage, H264_Quality_Preset QualityPreset,
			std::pair<uint32_t, uint32_t>& framesize, std::pair<int,int>& framerate,
			int profile, int profileLevel, int maxOfLTRFrames, int scanType);
		void Shutdown();

		void SubmitFrame(struct encoder_frame* &frame);
		void GetFrame(struct encoder_packet* &packet, bool* &received);

	};

	enum H264_Usage {
		H264_USAGE_TRANSCODING,
		H264_USAGE_ULTRA_LOW_LATENCY,
		H264_USAGE_LOW_LATENCY,
		H264_USAGE_WEBCAM,
	};

	enum H264_Quality_Preset {
		H264_QUALITY_PRESET_SPEED,
		H264_QUALITY_PRESET_BALANCED,
		H264_QUALITY_PRESET_QUALITY
	};

	enum H264_Profile {
		H264_PROFILE_BASELINE,
		H264_PROFILE_MAIN,
		H264_PROFILE_HIGH,
	};

	enum H264_Profile_Level {
		H264_PROFILE_LEVEL_1,
		H264_PROFILE_LEVEL_11,
		H264_PROFILE_LEVEL_12,
		H264_PROFILE_LEVEL_13,
		H264_PROFILE_LEVEL_2,
		H264_PROFILE_LEVEL_21,
		H264_PROFILE_LEVEL_22,
		H264_PROFILE_LEVEL_3,
		H264_PROFILE_LEVEL_31,
		H264_PROFILE_LEVEL_32,
		H264_PROFILE_LEVEL_4,
		H264_PROFILE_LEVEL_41,
		H264_PROFILE_LEVEL_42,
		H264_PROFILE_LEVEL_5,
		H264_PROFILE_LEVEL_51,
		H264_PROFILE_LEVEL_52,
	};
}