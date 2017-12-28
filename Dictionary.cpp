#include <unordered_map>
#include <string>

class Dictionary {
	public:
	Dictionary(){
		// reads the words.txt file and makes the scores map
		// add the score made by summing the letters	
	}

	int operator[](const std::string & s) const {
		return dictionary[s];
	}

	private:
	static std::unordered_map<std::string, int> dictionary; //word score

}; 