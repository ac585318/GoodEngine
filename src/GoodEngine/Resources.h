#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <rend/rend.h>

#include "GoodEngine/Resource.h"

namespace goodengine {

	class Resource;

	class Resources
	{
	public:
		friend class Core;

		template <typename T>
		std::shared_ptr<T> load(std::string path)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			resources.push_back(rtn);

			rtn->core = core;
			rtn->load(path);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> create()	//create empty
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			resources.push_back(rtn);
			return rtn;
		}

	private:
		std::weak_ptr<Core> core;
		std::shared_ptr<rend::Context> context;
		std::vector<std::shared_ptr<Resource>> resources;
	};

}