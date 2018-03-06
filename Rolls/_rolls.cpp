#include <vector>
#include <iostream>
#include <deque>
#include <sstream>
#include <fstream>
#include <algorithm>


#include "../Scores.cpp"
#include "Cube.cpp"


class Roller {
	public:

	Roller(std::ostringstream * os_in, std::vector<Cube> & cubes_in, Scores & scores_in)
		: os(os_in), cubes(cubes_in), scores(scores_in) {
		//initialize a hash table of roll strings to avoid duplicates
		//and a min priority queue to make it so it's top rolls
	}

	void add(std::string & roll_str){

		//alphebetize the roll
		std::sort(roll_str.begin(), roll_str.end()); 

		//if the hash of this is already in the table then
			//return

		//if the score of the roll is greater than the least in
		//our rolls or rolls is shorter than 100 thousand {
		//	add it to the priority queue
		//	add it to the hash table
		//}
	}

	void roll(){
		roll("", 0, 0);
	}

	void roll(std::string roll_str, int cube, int score){
		if(cube == CUBES){
			add(roll_str);
			
			return;
		}

		for(int i = 0; i < SIDES; i++){
			char c = cubes[cube].get_char(i);
			roll(
				roll_str + c, 
				cube + 1, 
				score += scores[c]
			);
		}
	}

	void output(){
		//for each in priority queue of pairs
		//*os << roll_str << " " << score << "\n";
		return;
	}

	private:
	static const int CUBES = 6; //for 6 do top 10000
	static const int SIDES = 6;

	//hash table
	//priority queue
	std::ostringstream * os;
	std::vector<Cube> & cubes;
	Scores & scores;
};

int main(int argc, char *argv[]){

	std::ios_base::sync_with_stdio(false);
	std::ostringstream os; 
	
	//initialize the scorecard
	Scores scores = Scores();

	//initialize cubes listed in the cubes.txt
	std::vector<Cube> cubes;

	//order the cubes by reverse value
	std::ifstream cube_file("Rolls/cubes.txt");
	std::string faces;
	while(cube_file >> faces){
		cubes.push_back(Cube(faces));
		//os << faces << " ";
		//os << cubes.back().get_value() << "\n";
	}

	//create the top rolls
	Roller roller = Roller(&os, cubes, scores);
	roller.roll();
	roller.output();

	//print out the rolls
	std::cout << os.str() << std::flush;

	return 0;
}



/*
function(string, current){
	if on the final cube {
		if the score of the roll is greater than the least in
		our rolls or rolls is shorter than 100 thousand {
			add it to the list
		}
		return
	}
	else for each side of the next cube	{
		add it to the string
	}
}
*/