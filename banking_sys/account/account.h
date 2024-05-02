#include <iostream>

using std::string;

class Account {
	private: 
		string ID, password;
		float balence;

	public: 
		Account(string ID, string password): ID(ID), password(password), balence(0.0) {}
		float get_bal() { return balence; }
		bool matches(string id);
		void deposit(float amount) { balence += amount; }
		void withdraw(float amount) { balence -= amount; }
		void close();
		void set_id(string new_id) { ID = new_id; };
		bool confirm_password(string diff_password) { return password==diff_password; }
		void set_password(string new_pwd) { password = new_pwd; }
};
