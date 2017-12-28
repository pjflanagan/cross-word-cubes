#include <map>

class Scores {
	public:
	Scores(){
		//reads the scores.txt file and makes the scores map
	}

	int operator[](const char c) const {
		return scores[c];
	}

	private:
	static std::map<char, int> scores;

}; 