#pragma once

#include <GL/glew.h>
#include <exception>
#include <iostream>

#include <rend/rend.h>
#include <GoodEngine/Component.h>

namespace goodengine {

	class Mesh;
	class Texture;

	class MeshRenderer : public Component
	{
	public:
		friend class Core;

		void setMesh(std::shared_ptr<Mesh> mesh);
		void setTexture(std::string name, std::shared_ptr<Texture> tex);

		void onInit();
		void onTick();
		void onDisplay();

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Texture> texture;
	};

}

// old triangle renderer
/*

#include <GL/glew.h>
#include <exception>
#include <iostream>

#include <GoodEngine/Component.h>

namespace goodengine {

	class MeshRenderer : public Component
	{
	public:
		void onTick();
		void onDisplay();

	private:
		GLuint positionsVboId;
		GLuint colorsVboId;
		GLuint vaoId;

		GLuint vertexShaderId;
		GLint success;
		GLuint fragmentShaderId;
		GLuint programId;
	};

}

*/