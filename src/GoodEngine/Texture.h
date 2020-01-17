#include <GoodEngine/Resource.h>

#include <rend/rend.h>
#include <vector>

namespace goodengine {

	class MeshRenderer;

	///
	/// A Texture Resource class for loading PNG image files / resources.
	/// They are members of the MeshRenderer and Gui classes.
	///
	class Texture : public Resource
	{
	public:
		///
		/// \brief A destructor
		///
		~Texture();

		///
		/// \brief Load a PNG image file
		/// \param _path the directory path to the file
		///
		void load(std::string _path);

	private:
		friend class MeshRenderer;
		friend class Gui;
		std::shared_ptr<rend::Texture> texture;
	};
}