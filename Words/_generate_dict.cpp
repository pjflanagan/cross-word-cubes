#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>

#include "../Scores.cpp"

bool valid(std::string & word);
int word_score(std::string & word, Scores & scores);


// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char *argv[]){

	std::ios_base::sync_with_stdio(false);
	std::ostringstream os; 
	
	//initialize the scorecard
	Scores scores = Scores();

	//read the dictionary
	std::ifstream dict_file("Words/dictionary_original.txt");
	std::string word;
	while(dict_file >> word){
		if(valid(word)){
			os << word << " " << word_score(word, scores) << "\n";
		}
	}

	//print out the rolls
	std::cout << os.str() << std::flush;

	return 0;
}

//EFFECTS returns true when the word is less than 14 and greater than 1
bool valid(std::string & word){
	return 	word.length() > 1 && //all 1 letter words are valid but do not count for points
			word.length() < 14;
}

//EFFECTS returns the value of the whole word
int word_score(std::string & word, Scores & scores){
	int s = 0;
	for(int i = 0; i < word.length(); ++i){
		s += scores[word[i]];
	}
	return s;
}