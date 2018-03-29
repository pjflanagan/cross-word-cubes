#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class Dictionary {
	public:
	Dictionary(){
		// reads the dictionary file and makes the scores map
		std::ifstream dict_file("Solve/dictionary_values.txt");
		dictionary = std::unordered_map<std::string, int>();
		std::string word; 
		int value;
		while(dict_file >> word >> value){
			Dictionary::dictionary.insert(std::pair<std::string,int>(word, value));
			insert_to_anagram(word);
		}
	}

	//REQUIRES s is a string
	//EFFECTS returns true when string is in the dictionary
	bool in(const std::string & s) const {
		std::unordered_map<std::string, int>::const_iterator it = dictionary.find(s);
		return it != dictionary.end();
	}

	//REQUIRES s is a string
	//EFFECTS returns words that can be made with a set of characters
	std::vector<std::string> * find_anagrams(const std::string s){
		std::string alpha = alphabetize(s);
		std::unordered_map<std::string, std::vector<std::string> >::iterator it = anagram.find(alpha);
		if(it != anagram.end())
			return & anagram.at(alpha);
		return nullptr;
	}

	//REQUIRES s is a string in the dictionary
	//EFFECTS returns the value of the string s
	int get_value(const std::string & s) const {
		if(in(s))
			return dictionary.at(s);
		return -1;
	}
	int operator[](const std::string & s) const {
	 	return get_value(s);
	}

	//REQUIRES s is a string
	//EFFECTS returns a sorted string
	std::string alphabetize(std::string s){
		std::sort(s.begin(), s.end());
		return s;
	}

	private:

	//REQUIRES s is a string
	//EFFECTS inserts a string 
	void insert_to_anagram(const std::string & s){
		std::string alpha = alphabetize(s);
		std::unordered_map<std::string, std::vector<std::string> >::iterator it = anagram.find(alpha);

		if(it != anagram.end())
			anagram.at(alpha).push_back(s);
		else {
			std::vector<std::string> words (1, s);
			anagram.insert(std::pair<std::string, std::vector<std::string> >(alpha, words));
		}
	}

	std::unordered_map<std::string, int> dictionary; //word, score
	std::unordered_map<std::string, std::vector<std::string> > anagram; //alpha, [words]

}; 

#endif