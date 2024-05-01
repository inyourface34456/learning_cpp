#include <assert.h>
#include "option.h"

template <typename T>
T* Option<T>::unwrap() {
	assert(isNone);
	return some;
}

template <typename T>
T* Option<T>::unwrap_or(T* default_value) {
	return isNone?default_value:some;
}

template <typename T>
void Option<T>::replace(T* data) {
	if (isNone) {
		isNone = false;
		some = data;
	} else if (data == nullptr) {
		isNone = true;
		some = nullptr;
	}
	some = data;
}
