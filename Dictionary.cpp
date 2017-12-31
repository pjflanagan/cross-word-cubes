#include <unordered_map>
#include <string>

class Dictionary {
	public:
	Dictionary(){
		// reads the dictionary.txt file and makes the scores map
		// ignores words over x letters long (14 for sure but probably 9)
		// add the score made by summing the letters	
	}

	int operator[](const std::string & s) const {
		return dictionary[s];
	}

	private:
	static std::unordered_map<std::string, int> dictionary; //word score

}; 