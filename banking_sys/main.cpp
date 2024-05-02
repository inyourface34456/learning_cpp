#include "account/account.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string, std::cin, std::vector;

void account_loop(Account* active, vector<Account*> accounts);

void start(vector<Account*> accounts) {
  string choice;  
start:
  cout << "Options:\n[N]ew accout\n[L]ogin\n[E]xit\n>>> ";
  cin >> choice;
  Account active = Account("", "");

  if (choice == "N") {
    string ID;
    string password;
    cout << "What is the accout ID? ";
    cin >> ID;
    cout << "What is that password? ";
    cin >> password;
    active.set_id(ID);
    active.set_password(password);
    accounts.push_back(&active);
  } else if (choice == "L") {
		string ID;
    string password;

		cout << "What is the ID of the account? ";  
		cin >> ID;
    cout << "What is the password of the account? ";
    cin >> password;

		for (Account* account: accounts) {
      if (account->matches(ID) && account->confirm_password(password)) {
				active = *account;
        break;
			}
      cout << "Incorrect Password!\n";
      goto start;
		}
  } else if (choice=="E") {
    cout << "Goodbye!";
    exit(0);
  } else {
    cout << "Invalid choice!"
         << "\n";
    goto start;
  }

  account_loop(&active, accounts);
}

void account_loop(Account* active, vector<Account*> accounts) {
  string choice;

  while (choice!="exit") {
    cout << "What would you like to do?\n[D]posit\n[W]ithdraw\n[C]lose\n[Q]uary balence\n[L]og Out\nChange [P]assword\n>>> ";
    cin >> choice;

    if (choice == "D") {
      float amount;
      string buffer;
      cout << "How much? ";
      cin >> buffer;
      amount = atof(buffer.c_str());
      active->deposit(amount);
    } else if (choice == "W") {
      float amount;
      string buffer;
      cout << "How much? ";
      cin >> buffer;
      amount = atof(buffer.c_str());
      active->withdraw(amount);
    } else if (choice == "C") {
      cout << "Thanks for banking with us!\n";
      active->close();
      // TODO: remove account form list
      start(accounts);
    } else if (choice == "Q") {
      cout << "Balence: " << active->get_bal() << "$\n";
    } else if (choice == "L") {
      cout << "See you!\n";
      start(accounts);
    } else if (choice == "C") {
      string new_password;
      cout << "What is the new password? ";
      cin >> new_password;
      
    }
  }
}

int main(int argc, char *argv[]) {
  string choice;
  vector<Account *> accounts;
  start(accounts);
}


