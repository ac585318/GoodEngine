#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include <GoodEngine/Resource.h>

namespace goodengine {

	class Audio : public Resource
	{
	public:
		~Audio();

		void load(std::string _path);
	private:
		friend class AudioSource;
		ALuint bufferId;
	};

}