#include <vector>

class rect {
	private:
		int width;
		int height;

	public:
		rect(int width, int height);
		int get_width() const { return width; };
		int get_height() const { return height; };
		int area() const { return width*height; };
		rect operator+(rect operend);
		bool operator=(rect operend);
};

template <typename T>
T average(std::vector<T> data) {
	T buffer = T();
	for (T i: data) {
		buffer += i;
	}
}

