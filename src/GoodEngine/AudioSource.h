#include <AL/al.h>
#include <AL/alc.h>

#include <GoodEngine/Component.h>

namespace goodengine {

	class Audio;

	///
	/// Uses an Audio Resource to play sound.
	///
	class AudioSource : public Component
	{
	public:
		///
		/// \brief A destructor
		///
		~AudioSource();

		///
		/// \brief Set if this object should self-destruct after playing an Audio file
		/// \param _b a boolean. True to self-destruct. True by default
		///
		void setAutoRemove(bool _b) { autoRemove = _b; }

		///
		/// \brief Set the Audio Resource to be used
		///
		/// Set the Audio to be played
		///
		/// \param _audio a Audio object. Requires a set path to an audio file
		///
		void setAudio(std::shared_ptr<Audio> _audio);

	private:
		//friend class Core;	// Doesn't need audioContext?
		friend class goodengine::GameObject;
		void onInit();
		void onInit(std::shared_ptr<Audio> _audio);
		void onTick();

		bool autoRemove;
		ALuint sourceId;
		std::shared_ptr<Audio> audio;
	};

}