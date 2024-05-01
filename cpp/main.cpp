#include <iostream>
#include "rect/rect.h"

using std::string, std::cout;

int main() {
	rect new_rect = rect(10, 20);

	cout << new_rect.area() << "\n";
}
