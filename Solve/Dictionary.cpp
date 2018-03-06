#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include <unordered_map>
#include <string>
#include <fstream>

class Dictionary {
	public:
	Dictionary(){
		// reads the dictionary file and makes the scores map
		std::ifstream dict_file("dictionary_values.txt");
		dictionary = std::unordered_map<std::string, int>();
		std::string word; 
		int value;
		while(dict_file >> word >> value){
			Dictionary::dictionary.insert(std::pair<std::string,int>(word, value));
		}
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
		return dictionary.at(s);
	}

	private:
	static std::unordered_map<std::string, int> dictionary; //word, score

}; 

#endif