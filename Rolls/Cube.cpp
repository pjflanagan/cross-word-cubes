#ifndef CUBE_CPP
#define CUBE_CPP

#include <vector>
#include <string>

#include "../Scores.cpp"


class Cube {
	public:
	static const int SIDES = 6;

	Cube(){};

	// REQUIRES faces is a 6 character string with lowercase characters
	Cube(const std::string &faces_in){
		scores = Scores();
		int v = 0;
		for(int i = 0; i < SIDES; ++i){
			v += scores[faces_in.at(i)];
			faces[i] = faces_in.at(i);
		}
		value = v;
	}
	
	// RETURNS the char representing the up face
	char get_char(int face) const{
		return faces[face];
	}

	// RETURNS the value of the whole cube
	int get_value() const {
		return value;
	}

	private: 
	Scores scores;
	char faces[6];
	int value; //total value of the cube
};

#endif




/*
// MODIFIES the cube to move to the next face
void roll_forward() {
	up = (up == 5) ? 0 : up + 1;
}

// MODIFIES the cube to move to the next face
Cube & operator++(){
	roll_forward();
	return *this;
}

// MODIFIES the cube to move to the next face
Cube operator++(int){
	Cube result(*this);
	++(*this);
	return result;
}*/