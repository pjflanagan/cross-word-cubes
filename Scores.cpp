#ifndef SCORES_CPP
#define SCORES_CPP

#include <map>
#include <fstream>

class Scores {
	public:
	Scores();
	int operator[](const char c) const;

	private:
	int value(const char c) const;
	std::map<char, int> scores;
}; 

Scores::Scores(){
	//reads the scores.txt file and makes the scores map
	std::ifstream score_file("scores.txt");
	scores = std::map<char, int>();
	char character; 
	int value;
	while(score_file >> character >> value){
		Scores::scores.insert(std::pair<char,int>(character, value));
	}
}

int Scores::operator[](const char c) const {
	return scores.at(c);
}

int Scores::value(const char c) const {
	return scores.at(c);
}

#endif