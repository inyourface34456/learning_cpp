#include "account/account.h"
#include "option/option.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string, std::cin, std::vector;


void account_loop(Account* active);
void start(vector<Account*> accounts);

int main(int argc, char *argv[]) {
  string choice;
  vector<Account *> accounts;
}

void account_loop(Account* active, vector<Account*> accounts) {
  string choice;

  while (choice!="exit") {
    cout << "What would you like to do?\n[D]posit\n[W]ithdraw\n[C]lose";
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
      start(accounts);
    }
  }
}

void start(vector<Account*> accounts) {
  string choice;  
start:
  cout << "Options:\n[N]ew accout\n[L]ogin";
  cin >> choice;
  Option<Account> active = Option<Account>();

  if (choice == "N") {
    string ID;
    cout << "What is the accout ID? ";
    cin >> ID;
    Account temp_acc = Account(ID);
    active.replace(&temp_acc);
    accounts.push_back(&temp_acc);
  } else if (choice == "L") {
		string ID;

		cout << "What is the ID of the account? ";  
		cin >> ID;

		for (Account* account: accounts) {
			if (account->matches(ID)) {
				active.replace(account);
			}
		}
  } else {
    cout << "Invalid choice!"
         << "\n";
    goto start;
  }

  account_loop(active.unwrap());
}
