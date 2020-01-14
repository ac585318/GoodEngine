#include <memory>
#include <GL/glew.h>

#include <rend/rend.h>

namespace goodengine {

	class Core;
	class Mesh;
	class Texture;

	///
	/// Draws a Texture to the screen as a GUI (Graphical User Interface).
	/// GUI renders after and on top of Camera components and objects.
	///
	class Gui
	{
	public:
		///
		/// \brief Draw an image / Texture to the GUI
		/// \param _pos a vector for the X, Y, Width and Height values
		/// \param _texture a Texture object. Requires a set path to an image file
		///
		void texture(glm::vec4 _pos, std::shared_ptr<Texture> _texture);
	private:
		friend class Core;
		std::weak_ptr<Core> core;
		void init();

		std::shared_ptr<rend::Mesh> mesh;
		std::shared_ptr<rend::mat4> mat;
		std::shared_ptr<rend::Shader> shader;
	};

}