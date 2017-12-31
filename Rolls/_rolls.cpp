#include <vector>
#include <iostream>
#include <deque>
#include <sstream>
#include <utilitiy>


#include "Scores.cpp"
#include "Cube.cpp"


int main(int argc, char *argv[]){

	ios_base::sync_with_stdio(false);

	ostringstream os; 

	//initialize cubes listed in the cubes.txt
	std::vector<Cube> cubes;

	//make the first million of the 6^14 options for rolls 
	//and save in a text file to be used later
	//use a priority queue of rolls and once you get to
	//like 10 million save the first million

}