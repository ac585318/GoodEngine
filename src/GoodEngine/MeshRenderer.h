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