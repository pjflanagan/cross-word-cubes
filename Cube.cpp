#include "Scores.cpp"

class Cube {
	public:
	static const int SIDES = 6;
	static Scores score;

	// REQUIRES faces is a 6 character string with lowercase characters
	Cube(const std::string &faces_in){

	}
	
	// RETURNS the char representing the up face
	char get_char() const{
		return faces[up];
	}

	// RETURNS the value of the up face
	int get_val() const{
		return score[faces[up]];
	}

	//roll_forward

	//reset

	private: 
	char faces[6];
	int up; //index of the up face
};

Scores Cube::score = Scores();

//operator++ calls roll_forward then reset
