template <typename T>
class Option {
	private: 
		T* some;
		bool isNone;

	public:
		Option(T* data): some(data), isNone(false) {}
		Option(): some((T*) nullptr), isNone(true) {}
		T* unwrap();
		T* unwrap_or(T* value);
		void replace(T* data);
};
