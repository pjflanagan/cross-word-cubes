#include <vector>
#include <iostream>
#include <deque>
#include <sstream>
#include <fstream>


#include "../Scores.cpp"
#include "Cube.cpp"


int main(int argc, char *argv[]){

	std::ios_base::sync_with_stdio(false);
	
	std::ostringstream os; //os << scores['z'] << "\n";
	
	//initialize the scorecard
	Scores scores = Scores();

	//initialize cubes listed in the cubes.txt
	std::vector<Cube> cubes;

	//make the first 100 thousand of the 6^14 options for rolls 
	//and save in a text file to be used later
	//use a priority queue of rolls and once you get to
	//like 10 million save the first million

	//print out the rolls
	std::cout << os.str() << std::flush;
	
}