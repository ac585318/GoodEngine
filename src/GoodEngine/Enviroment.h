namespace goodengine {

	///
	/// An Enviroment class, contains deltaTime.
	///
	class Enviroment
	{
	public:
		///
		/// \brief Returns deltaTime
		/// \return float deltaTime
		///
		float getDeltaTime() { return deltaTime; }

	private:
		friend class Core;
		float deltaTime;
	};
}