#pragma once

#include "Mesh.h"

#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

#include "Core.h"

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

		// Resources returns this mesh, no return needed here?
	}

}