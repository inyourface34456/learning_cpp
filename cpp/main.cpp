#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	std::cout << argc << "\n";
	std::cout << argv << "\n";
	std::vector<int> test = {10, 20, 30, 40};
	
	for (int i: test) {
		std::cout << i << "\n";
	}
}
