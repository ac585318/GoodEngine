#include <exception>
#include <string>

namespace goodengine {
	///
	/// An exception handling struct.
	/// Used to throw exceptions with messages
	///
	struct Exception : public std::exception
	{
	public:
		///
		/// \brief Sets an exception message
		/// \param std::string containing exception message
		///
		Exception(const std::string& message);

		///
		/// \brief A virtual destructor
		///
		virtual ~Exception() throw();

		///
		/// \brief Returns the exception message passed into the constructor
		/// \return const char* exception message
		virtual const char* what() const throw();

	private:
		std::string message;
	};
}