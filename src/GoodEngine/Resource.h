#pragma once

#include <string>
#include <memory>

namespace goodengine {

	class Resources;
	class Core;

	class Resource
	{
	protected:
		//empty virtual load func

		friend class Resources;
		//std::weak_ptr<Resources> resources;
		std::weak_ptr<Core> core;
		std::string path;
	};

}