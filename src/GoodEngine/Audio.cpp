#include "Audio.h"
#include "Core.h"

#include "stb_vorbis.h"
#include <iostream>
#include <fstream>

void load_ogg(const std::string& fileName, std::vector<char>& buffer, ALenum &format, ALsizei &freq);

namespace goodengine {

	Audio::~Audio()
	{
		/*
		* Clean up OpenAL data.
		*
		* Note: Do not free the buffer before the source using it has been freed.
		*       Use a std::shared_ptr to hold onto you sound buffer class from source class.
		*
		* Note: Make sure current context has been set to NULL before deleting context.
		*       Make sure context destroyed before closing device.
		*/
		alDeleteBuffers(1, &bufferId);
	}

	void Audio::load(std::string _path)
	{
		// Generally not needed. Translate sources instead
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		// Create OpenAL sound buffer
		
		bufferId = 0;
		alGenBuffers(1, &bufferId);

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;
		load_ogg(_path, bufferData, format, freq);

		alBufferData(bufferId, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);
	}
}

void load_ogg(const std::string& fileName, std::vector<char>& buffer,
	ALenum &format, ALsizei &freq)
{
	int channels = 0;
	int sampleRate = 0;
	short* output = NULL;

	size_t samples = stb_vorbis_decode_filename(
		fileName.c_str(), &channels, &sampleRate, &output);

	if (samples == -1)
	{
		throw std::exception();
	}

	// Record the sample rate required by OpenAL
	freq = sampleRate;

	// Record the format required by OpenAL
	if (channels == 1)
	{
		format = AL_FORMAT_MONO16;
	}
	else
	{
		format = AL_FORMAT_STEREO16;

		// Force format to be mono (Useful for positional audio)
		// format = AL_FORMAT_MONO16;
		// freq *= 2;
	}

	// Allocate enough space based on short (two chars) multipled by the number of
	// channels and length of clip
	buffer.resize(sizeof(*output) * channels * samples);
	memcpy(&buffer.at(0), output, buffer.size());

	// Clean up the read data
	free(output);
}