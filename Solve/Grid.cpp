#ifndef GRID_CPP
#define GRID_CPP

#include <vector>
#include <deque>
#include <iostream>
#include <fstream>

#include "Dictionary.cpp"

class Grid {
	public:
	Grid(Dictionary & d) : dict(d) {
		best_score = 0;
	}

	void solve(std::string r){
		roll = r;
		int score = 0;
		
		score = 1;

		if(score > best_score){
			best_score = score;
			write();
		}
	}

	//writes the cubes, words, and score to a file solution-<score>-<roll>.txt
	void write(){
		std::ofstream file;
		std::string file_name = "Solve/solutions/s-" + std::to_string(best_score) + "-" + roll + ".txt";

		file.open(file_name);
		file << roll << " " << best_score << "\n";
		for(int i = 0; i < solution_words.size(); ++i){
			file << solution_words[i] << "\n";
		}
		file.close();
	}

	private:

	//checks to see if grid is valid
	bool validate();

	//resets the grid
	void clear();

	Dictionary dict;

	std::string roll;
	std::vector<std::string> solution_words;
	int best_score;
}; 

#endif