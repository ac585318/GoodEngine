#include <AL/al.h>
#include <AL/alc.h>

#include <GoodEngine/Resource.h>

namespace goodengine {

	///
	/// An Audio Resource class for loading ogg audio files / resources.
	///
	class Audio : public Resource
	{
	public:
		///
		/// \brief A destructor
		///
		~Audio();

		///
		/// \brief Load an ogg audio file
		/// \param _path the directory path to the file
		///
		void load(std::string _path);

	private:
		friend class AudioSource;
		ALuint bufferId;
	};

}