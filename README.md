# Cross Word Cubes

My attempt at programmatically finding the highest possible Cross Word Cubes roll and arrangement. 

## Rules

Cross Word Cubes is a scrabble game played with 14 dice with letters on each face.
Players take turns rolling the dice and then attempting to arange a group of crossed
words from the roll. Letters that occur at the intersection of two words count for double.

With a setup like this, there is a single highest scoring roll and arangement 
possible within the game. This program is an attempt at finding that high score.

## Process
1. Create all unique combinations of rolls from the 14 dice. 
To save time we will only be testing the top hundred thousand or so highest scoring rolls.
2. Test possible arangements of cubes for each roll.
I'm unsure how to do this but most likeley will be finding sets of valid words
within the roll and then aranging those sets at valid intersections.

## Files
- cubes.txt are the cubes used in the game. Faces are ordered by value but the cubes are in 
no particular order. The cube with 2 h's might be incorrect.
- scores.txt value of each letter used in the game in alphabetical order.

## Run
```
g++ Rolls/_rolls.cpp -o roll.exe
./roll.exe > Rolls/roll-#.txt

g++ Words/_generate_dict.cpp -o generate.exe
./generate.exe > Solve/dictionary_values.txt
```