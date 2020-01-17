#include "Gui.h"
#include "Texture.h"
#include "Core.h"

const char* guiShader =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec2 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"attribute vec3 a_Normal;                      \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"uniform mat4 u_Model;                         \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_Position = u_Projection *                \n" \
"    u_Model * vec4(a_Position, 1, 1);         \n" \
"                                              \n" \
"  v_Normal = a_Normal;                        \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
"  v_TexCoord.y = 1 - v_TexCoord.y;                    \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"uniform sampler2D u_Texture;                  \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";

namespace goodengine {

	void Gui::init()
	{
		std::shared_ptr<rend::Context> context = core.lock()->getContext();

		shader = context->createShader();
		shader->parse(guiShader);

		// Create a new empty mesh
		mesh = context->createMesh();

		// Create and set two buffers, a_Position and a_TexCoord
		std::shared_ptr<rend::Buffer> buffer = context->createBuffer();
		buffer->add(glm::vec2(0, 0));
		buffer->add(glm::vec2(0, 1));
		buffer->add(glm::vec2(1, 1));
		buffer->add(glm::vec2(1, 1));
		buffer->add(glm::vec2(1, 0));
		buffer->add(glm::vec2(0, 0));
		mesh->setBuffer("a_Position", buffer);
		mesh->setBuffer("a_TexCoord", buffer);
	}

	void Gui::texture(glm::vec4 _pos, std::shared_ptr<Texture> _texture)
	{
		// Screen Size
		glm::vec2 ss = core.lock()->getScreenSize();

		glm::mat4 model(1.0f);
		model = rend::translate(model, glm::vec3(_pos.x, _pos.y, 0));
		model = rend::scale(model, glm::vec3(_pos.z, _pos.w, 1.0f));

		shader->setUniform("u_Model", model);
		shader->setUniform("u_Projection", glm::ortho(0.0f, ss.x, ss.y, 0.0f));

		mesh->setTexture("u_Texture", _texture->texture);
		shader->setMesh(mesh);
		shader->render();
	}
	// To do button... store _pos and texture in a guiElement/button class, return it
	// Make a bool return "onHover" function here which takes a guiElement object, combine with core mouse inputs
}