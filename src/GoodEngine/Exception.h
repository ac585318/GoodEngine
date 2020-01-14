#include <exception>
#include <string>

namespace goodengine {
	///
	/// An exception handling struct.
	///
	struct Exception : public std::exception
	{
	public:
		///
		/// \brief Sets an error message
		///
		Exception(const std::string& message);

		///
		/// \brief A virtual destructor
		///
		virtual ~Exception() throw();

		///
		/// \brief Returns the error message passed into the constructor
		/// \return const char* exception message
		virtual const char* what() const throw();

	private:
		std::string message;
	};

}