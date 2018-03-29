#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>

#include "Dictionary.cpp"
#include "Grid.cpp"



// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char *argv[]){
	std::ios_base::sync_with_stdio(false);
	//std::ostringstream os; 

	Dictionary dict = Dictionary();

	// get the rolls string as a stack
	std::ifstream roll_file("Solve/rolls-6.txt");
	std::deque<std::string> rolls;
	std::string roll; 
	int value;
	while(roll_file >> roll >> value){
		rolls.push_front(roll);
	}

	//create the grid 
	Grid grid = Grid(dict);

	// generate solutions for each roll
	for(int i = 0; i < 1; ++i){ //rolls.size(); ++i){
		grid.solve(rolls[i]);
	}

	//print 
	//std::cout << os.str() << std::flush;

	return 0;
}