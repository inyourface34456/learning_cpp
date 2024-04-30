#include <iostream>
#include <vector>

using std::string, std::cout;

struct myStruct {
	string data;
	private: myStruct* next;

	public: myStruct(string data, myStruct* next, const bool isFirst, const bool isLast): 
		data(data), next(next)
	{};

	public: myStruct* next_elem() {
		return next;
	}
};

int main() {
	myStruct test = myStruct("testing, lol", NULL, true, false);
	cout << test.data << "\n";
}
