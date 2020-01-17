#pragma once
#ifndef GOODENGINE_RESOURCE_H
#define GOODENGINE_RESOURCE_H

#include <string>
#include <memory>

namespace goodengine {

	class Resources;
	class Core;

	///
	/// A base class for resources and assets. Resource objects are members of the Resources class.
	/// This class should be inherited from to add new types of data files and resources.
	/// Loading a Resource object is handled by the Resources class.
	///
	class Resource
	{
	protected:
		//empty virtual load func

		friend class Resources;
		std::weak_ptr<Core> core;	///< weak pointer reference to the Core object
		std::string path;			///< std::string containing the file directory to the resource
	};
}

#endif