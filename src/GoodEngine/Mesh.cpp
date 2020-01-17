#include "Mesh.h"
#include "Core.h"

#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

namespace goodengine {

	Mesh::~Mesh()
	{

	}

	void Mesh::load(std::string _path)
	{
		path = _path;

		mesh = core.lock()->getContext()->createMesh();

		if (mesh)
		{
			std::ifstream f(_path);
			std::string obj;
			std::string line;

			while (!f.eof())
			{
				std::getline(f, line);
				obj += line + "\n";
			}

			mesh->parse(obj);
		}

		// Resources returns this mesh
	}
}