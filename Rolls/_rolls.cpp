#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>

#include "../Scores.cpp"
#include "Cube.cpp"


class Roller {
	public:

	Roller(std::ostringstream * os_in, std::vector<Cube> & cubes_in, Scores & scores_in)
		: os(os_in), cubes(cubes_in), scores(scores_in) {
		//initialize a hash table of roll strings to avoid duplicates
		//and a min priority queue to make it so it's top rolls
	}

	void add(std::string & roll_str, int score){
		//alphebetize the roll
		std::sort(roll_str.begin(), roll_str.end()); 

		//if the value is already in the list then return
		std::map<std::string,int>::iterator it = top_rolls.find(roll_str);
		if(it != top_rolls.end()) 
			return;

		//if rolls is shorter than MAX
		if (roll_queue.size() < MAX){
			insert(roll_str, score);
		}
		//if the score of the roll is greater than the least in our rolls
		else if(score > roll_queue.top().first){
			//pop the top
			roll_queue.pop();
			insert(roll_str, score);
		}
		
	}

	void insert(std::string & roll_str, int score){
		//add it to the priority queue
		roll_queue.push(std::pair<int, std::string>(score, roll_str));
		//add it to the hash table
		top_rolls.insert(std::pair<std::string, int>(roll_str, score));
	}

	void roll(){
		roll("", 0, 0);
	}

	void roll(std::string roll_str, int cube, int score){
		//if this is the last cube
		if(cube == CUBES){
			//attempt to add it 
			add(roll_str, score);
			return;
		}

		//for each side of the next cube
		for(int i = 0; i < SIDES; i++){
			char c = cubes[cube].get_char(i);
			//call the roll function again
			roll(
				roll_str + c, 
				cube + 1, 
				score + scores[c]
			);
		}
	}

	void output(){
		//print each of priority queue of pairs and their values
		while(!roll_queue.empty()){
			*os << roll_queue.top().second << " " << roll_queue.top().first << "\n";
			roll_queue.pop();
		}
		return;
	}

	private:
	static const int CUBES = 10; //for 6 do top 10000
	static const int SIDES = 6;
	static const long MAX = 10000;

	std::map<std::string, int> top_rolls;
	std::priority_queue<
		std::pair<int, std::string>, 
		std::vector<std::pair<int, std::string> >,
		std::greater<std::pair<int, std::string> >
	> roll_queue;

	std::ostringstream * os;
	std::vector<Cube> & cubes;
	Scores & scores;
};


// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
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