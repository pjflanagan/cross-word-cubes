#ifndef CUBE_H
#define CUBE_H

#include "Letter.h"
#include <iostream>
#include <string>

class Cube {
	public:
	// the letters and their values
	#pragma region "Letters"
	static const Letter A;
	static const Letter B;
	static const Letter C;
	static const Letter D;
	static const Letter E;
	static const Letter F;
	static const Letter G;
	static const Letter H;
	static const Letter I;
	static const Letter J;
	static const Letter K;
	static const Letter L;
	static const Letter M;
	static const Letter N;
	static const Letter O;
	static const Letter P;
	static const Letter Q;
	static const Letter R;
	static const Letter S;
	static const Letter T;
	static const Letter U;
	static const Letter V;
	static const Letter W;
	static const Letter X;
	static const Letter Y;
	static const Letter Z;
	#pragma endregion

	// REQUIRES faces is a 6 character string with lowercase characters
	Cube(const std::string &faces_in);

	// RETURNS a Letter representing the up face
	Letter get_up() const;
	
	// RETURNS the char representing the up face
	char get_up_char() const;

	// RETURNS the value of the up face
	int get_up_val() const;

	private: 
	Letter faces[6];
	int up;
	static std::map<char, Letter> refrence;
	static const int SIDES;
};

#endif