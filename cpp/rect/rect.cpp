#include "rect.h"

rect::rect(int width, int height):
	width(width),
	height(height)
{
}

rect rect::operator+(rect operend) {
	int new_w = width + operend.get_width();
	int new_h = height + operend.get_height();
	return rect(new_w, new_h);
}

bool rect::operator=(rect operend) {
	return operend.get_height()==height&&operend.get_width()==width;
}
