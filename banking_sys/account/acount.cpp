#include "account.h"

bool Account::matches(string id) {
	return ID==id;
}

void Account::close() {
	balence = 0;
	ID = "";
}
