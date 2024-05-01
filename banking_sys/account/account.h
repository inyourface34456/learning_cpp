#include <iostream>

using std::string;

class Account {
	private: 
		string ID;
		float balence;

	public: 
		Account(string ID): ID(ID) {}
		float get_bal() { return balence; }
		bool is_overdrawn() { return balence<=0; }
		bool matches(string id);
		void deposit(float amount) { balence += amount; }
		void withdraw(float amount) { balence -= amount; }
		void close();
};
