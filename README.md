# Cross Word Cubes

My attempt at programmatically finding the highest possible Cross Word Cubes roll and arrangement. 

## Rules
Cross Word Cubes is a Scrabble game played with 14 dice with letters on each face.
Some dice have vowels, all worth 1 point except 'y' which is 4 and others have consonants 
of varried point values with 'z,' 'j,' and 'q' being the hightest in value.
Players take turns rolling the dice and then attempting to arange a group of crossed
words from the roll. Letters that occur at the intersection of two words count for double.
Letters that are not used count against the total score.

With a setup like this, there may be a single highest scoring roll and arangement of 
that roll possible within the game. This program is an attempt at finding that high score.

## Process
1. Create all unique combinations of rolls from the 14 dice. 
To save time we will only be testing the top ten thousand or so highest scoring rolls.
2. Test possible arangements of cubes for each roll.
I'm unsure how to do this but most likeley will be finding sets of valid words
within the roll and then aranging those sets at valid intersections, or brute force
attempting to arrange the cubes into shapes and seeing if they are valid.

## Files
- cubes.txt are the cubes used in the game. Faces are ordered by value but the cubes are in 
no particular order. The cube with 2 h's might be incorrect.
- scores.txt value of each letter used in the game in alphabetical order.
- dictionary_original.txt not included in this repository but is an english dictionary.

## Run
```
g++ Rolls/_rolls.cpp -o roll.exe
./roll.exe > Rolls/roll-#.txt

g++ Words/_generate_dict.cpp -o generate.exe
./generate.exe > Solve/dictionary_values.txt
```