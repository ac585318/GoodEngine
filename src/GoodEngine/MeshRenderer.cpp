#include "MeshRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Core.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"

const char* src =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"attribute vec3 a_Normal;                      \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"uniform mat4 u_View;                         \n" \
"uniform mat4 u_Model;                         \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_Position = u_Projection * u_View *       \n" \
"    u_Model * vec4(a_Position, 1);            \n" \
"                                              \n" \
"  v_Normal = a_Normal;                        \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
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

	void MeshRenderer::setMesh(std::shared_ptr<Mesh> _mesh)
	{
		this->mesh = _mesh;
	}

	void MeshRenderer::setTexture(std::string _name, std::shared_ptr<Texture> _tex)
	{
		// _name currently can only be "u_Texture", from src fragment shader

		this->texture = _tex;

		if (mesh)
		{
			mesh->mesh->setTexture(_name, texture->texture);
		}
	}

	void MeshRenderer::onInit()
	{
		shader = getGameObject()->getCore()->getContext()->createShader();
		shader->parse(src);

		// set an empty mesh?
	}

	void MeshRenderer::onTick()
	{
		// Could all go into onDisplay
		if (getCore()->getActiveCam())
		{
			shader->setUniform("u_Projection", getCore()->getActiveCam()->getProjection());
			shader->setUniform("u_View", getCore()->getActiveCam()->getView());
			shader->setUniform("u_Model",
				getGameObject()->getComponent<Transform>()->getModel()
			);
		}
		else
		{
			// Get and use the position and rotation of this MeshRender
			glm::vec3 pos = getGameObject()->getComponent<Transform>()->getPosition();
			glm::vec3 rot = getGameObject()->getComponent<Transform>()->getRotation();
			// Pushes everything 10 units away from the camera/window
			pos.z -= 10;
			shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), getCore()->getScreenSize().x / getCore()->getScreenSize().y, 0.1f, 100.0f));
			shader->setUniform("u_View", glm::mat4(1.0f));
			shader->setUniform("u_Model",
				glm::translate(glm::mat4(1.0f), pos) *
				glm::rotate(glm::mat4(1.0f), glm::radians(rot.x), glm::vec3(1, 0, 0))*
				glm::rotate(glm::mat4(1.0f), glm::radians(rot.y), glm::vec3(0, 1, 0))*
				glm::rotate(glm::mat4(1.0f), glm::radians(rot.z), glm::vec3(0, 0, 1))
			);
		}
	}

	void MeshRenderer::onDisplay()
	{
		// Should there be a try error check here?
		shader->setMesh(mesh->mesh);
		shader->render();
	}
}