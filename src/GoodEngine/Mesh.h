#include <vector>
#include <rend/rend.h>

#include <GoodEngine/Resource.h>

namespace goodengine {

	class MeshRenderer;

	///
	/// A Mesh class for loading 3D models and meshes from OBJ files
	///
	class Mesh : public Resource
	{
	public:
		///
		/// \brief A destructor
		///
		~Mesh();

		///
		/// \brief Load a mesh using a file directory
		///
		/// Must be an OBJ file
		///
		/// \param _path std::string of the file directory path
		///
		void load(std::string _path);
	private:
		friend class MeshRenderer;
		std::shared_ptr<rend::Mesh> mesh;
	};

}