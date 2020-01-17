#include <memory>
#include <vector>
#include <iostream>
#include <rend/rend.h>

#include "GoodEngine/Resource.h"

namespace goodengine {

	class Resource;

	///
	/// A class that stores and manages all Resource type objects.
	/// Should be used to create and add/load resources to your project.
	///
	class Resources
	{
	public:
		///
		/// \brief Load and store a specified Resource type object
		///
		/// Use this to add child classes of Resource to the resources
		///
		/// \param _path the directory path to the file
		/// \return A reference to the specified Resource class or child type object
		///
		template <typename T>
		std::shared_ptr<T> load(std::string _path)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			resources.push_back(rtn);

			rtn->core = core;
			rtn->load(_path);

			return rtn;
		}

		///
		/// \brief Create and store a specified Resource type object
		///
		/// Use this to add child classes of Resource to the resources
		/// without loading or specifying a path
		///
		/// \return A reference to the specified Resource class or child type object
		///
		template <typename T>
		std::shared_ptr<T> create()	//create empty
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			resources.push_back(rtn);
			return rtn;
		}

	private:
		friend class Core;
		std::weak_ptr<Core> core;
		std::shared_ptr<rend::Context> context;
		std::vector<std::shared_ptr<Resource>> resources;
	};
}