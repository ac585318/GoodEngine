#include "AudioSource.h"

#include "Audio.h"
#include <iostream>

namespace goodengine {

	AudioSource::~AudioSource()
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
		alDeleteSources(1, &sourceId);
	}

	void AudioSource::setAudio(std::shared_ptr<Audio> _audio)
	{
		this->audio = _audio;

		/*
		* Create OpenAL sound source
		*/
		this->sourceId = 0;
		alGenSources(1, &sourceId);

		alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sourceId, AL_BUFFER, audio->bufferId);
		alSourcePlay(sourceId);
	}

	void AudioSource::onInit()
	{
		this->autoRemove = true;
		this->sourceId = 0;
	}

	// Is this function needed?
	void AudioSource::onInit(std::shared_ptr<Audio> _audio)
	{
		this->autoRemove = true;
		this->sourceId = 0;
		setAudio(_audio);
	}

	void AudioSource::onTick()
	{
		ALint state = 0;
		alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)	// Does not return true if there is no sound set
		{
			// Set self for destruction
			if (autoRemove)
			{
				alive = false;
			}
		}
	}


}