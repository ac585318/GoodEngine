#include <GoodEngine/Resource.h>
#include <AL/al.h>
#include <AL/alc.h>

namespace goodengine {

	///
	/// An Audio Resource class for loading ogg audio files / resources.
	/// They are members of the AudioSource class.
	///
	class Audio : public Resource
	{
	public:
		///
		/// \brief A destructor
		///
		~Audio();

		///
		/// \brief Load An ogg audio file
		/// \param _path The directory path to the file
		///
		void load(std::string _path);

	private:
		friend class AudioSource;
		ALuint bufferId;
	};
}