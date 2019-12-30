#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include <GoodEngine/Component.h>

namespace goodengine {

	class Audio;

	class AudioSource : public Component
	{
	public:
		//friend class Core;	// Does it not need audioContext?

		~AudioSource();

		void setAutoRemove(bool _b) { autoRemove = _b; }
		void setAudio(std::shared_ptr<Audio> _audio);

		void onInit();
		void onInit(std::shared_ptr<Audio> _audio);
		void onTick();

	private:
		bool autoRemove;
		ALuint sourceId;
		std::shared_ptr<Audio> audio;
	};

}