#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>

#include "Dictionary.cpp"



// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char *argv[]){
	std::ios_base::sync_with_stdio(false);
	std::ostringstream os; 

	Dictionary dict = Dictionary();


	os << dict.get_value("jealous") << "\n";
	os << dict["bar"] << "\n";
	os << dict.alphabetize("house") << "\n";
	std::vector<std::string> * vec_ptr = dict.find_anagrams("shoe");
	for(int i = 0; i < (*vec_ptr).size(); ++i)
		os << (*vec_ptr)[i] << "\n";

	//print out the rolls
	std::cout << os.str() << std::flush;

	return 0;
}