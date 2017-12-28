#ifndef LETTER_H
#define LETTER_H

#include <map>

class Letter {
	public:
	// REQUIRES c is a lowercase letter of the wildcard
	Letter(char c, int v);
	char character;
	int value;
};

#endif