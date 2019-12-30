#pragma once

#include <rend/rend.h>
#include <vector>

#include <GoodEngine/Resource.h>

namespace goodengine {

	class MeshRenderer;

	class Texture : public Resource
	{
	public:
		~Texture();

		void load(std::string _path);
	private:
		friend class MeshRenderer;
		std::shared_ptr<rend::Texture> texture;
	};

}