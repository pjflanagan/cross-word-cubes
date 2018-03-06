#include <unordered_map>
#include <string>

#include "../Scores.cpp"

class Dictionary {
	public:
	Dictionary(){
		// reads the dictionary.txt file and makes the scores map
		
	}

	//REQUIRES s is a string
	//EFFECTS returns true when string is in the dictionary
	bool in(const std::string & s) const {
		std::unordered_map<std::string, int>::iterator it = dictionary.find(s);
		return it != dictionary.end();

	}

	//REQUIRES s is a string in the dictionary
	//EFFECTS returns the value of the string s
	int operator[](const std::string & s) const {
		return dictionary[s];
	}

	private:
	static std::unordered_map<std::string, int> dictionary; //word, score
	Scores scores;

}; 