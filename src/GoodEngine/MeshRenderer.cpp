#include "MeshRenderer.h"

#include "GameObject.h"
#include "Core.h"
#include "Mesh.h"
#include "Texture.h"

const char* src =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
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

	void MeshRenderer::setMesh(std::shared_ptr<Mesh> mesh)
	{
		this->mesh = mesh;
	}

	void MeshRenderer::setTexture(std::string name, std::shared_ptr<Texture> tex)
	{
		this->texture = tex;

		if (mesh)
		{
			mesh->mesh->setTexture(name, texture->texture);
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
		glm::vec3 pos = getGameObject()->getComponent<Transform>()->getPosition();
		// Pushes them 10 units away from the camera/window
		pos.z -= 10;

		shader->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));

		shader->setUniform("u_Model",
			glm::translate(glm::mat4(1.0f), pos) *
			glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0, 1, 0))
		);
	}

	void MeshRenderer::onDisplay()
	{
		// Should there be a try error check here?
		shader->setMesh(mesh->mesh);
		shader->render();
	}

}

// old triangle renderer
/*

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

const GLfloat positions[] = {
	0.0f, 0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f
};

const GLfloat colors[] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

const GLchar *vertexShaderSrc =
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = vec4(in_Position, 1.0);" \
"  ex_Color = in_Color;" \
"}" \
"";

const GLchar *fragmentShaderSrc =
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"";

namespace goodengine {

	void MeshRenderer::onTick()
	{
		positionsVboId = 0;

		// Create a new VBO on the GPU and bind it
		glGenBuffers(1, &positionsVboId);

		if (!positionsVboId)
		{
			throw std::exception();
		}

		glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

		// Upload a copy of the data from memory into the new VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

		// Reset the state
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		colorsVboId = 0;

		// Create a colors VBO on the GPU and bind it
		glGenBuffers(1, &colorsVboId);

		if (!colorsVboId)
		{
			throw std::exception();
		}

		glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

		// Upload a copy of the data from memory into the new VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

		// Reset the state
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		vaoId = 0;

		// Create a new VAO on the GPU and bind it
		glGenVertexArrays(1, &vaoId);

		if (!vaoId)
		{
			throw std::exception();
		}

		glBindVertexArray(vaoId);

		// Bind the position VBO, assign it to position 0 on the bound VAO and flag it to be used
		glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
		glEnableVertexAttribArray(0);

		// Bind the color VBO, assign it to position 1 on the bound VAO and flag it to be used
		glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
		glEnableVertexAttribArray(1);

		// Reset the state
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
		glCompileShader(vertexShaderId);
		success = 0;
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
		glCompileShader(fragmentShaderId);
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		programId = glCreateProgram();
		glAttachShader(programId, vertexShaderId);
		glAttachShader(programId, fragmentShaderId);
		glBindAttribLocation(programId, 0, "in_Position");
		glBindAttribLocation(programId, 1, "in_Color");

		if (glGetError() != GL_NO_ERROR)
		{
			throw std::exception();
		}

		glLinkProgram(programId);
		glGetProgramiv(programId, GL_LINK_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		glDetachShader(programId, vertexShaderId);
		glDeleteShader(vertexShaderId);
		glDetachShader(programId, fragmentShaderId);
		glDeleteShader(fragmentShaderId);

	}

	void MeshRenderer::onDisplay()
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(programId);
		glBindVertexArray(vaoId);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);
	}

}

*/