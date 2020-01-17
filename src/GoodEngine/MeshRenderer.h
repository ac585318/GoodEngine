#include <GoodEngine/Component.h>

#include <rend/rend.h>
#include <GL/glew.h>
#include <exception>
#include <iostream>

namespace goodengine {

	class Mesh;
	class Texture;

	///
	/// A mesh renderer class for rendering textured Mesh objects to the screen.
	/// Requires both a Mesh and a Texture.
	/// Uses a built-in shader.
	///
	class MeshRenderer : public Component
	{
	public:
		///
		/// \brief Set a mesh to render
		/// \param _mesh Mesh object set to render, from this MeshRenderer
		///
		void setMesh(std::shared_ptr<Mesh> _mesh);

		///
		/// \brief Set a texture to render to the mesh
		/// \param _name std::string of the internal uniform sampler2D name. Needs to be set to "u_Texture"
		/// \param _tex Texture object set to draw to a Mesh object
		///
		void setTexture(std::string _name, std::shared_ptr<Texture> _tex);

	private:
		friend class goodengine::GameObject;
		void onInit();
		void onTick();
		void onDisplay();

		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Texture> texture;
	};
}