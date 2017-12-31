# Cross Word Cubes

## Rules

Cross Word Cubes is a scrabble game played with 14 dice with letters on each face.
Players take turns rolling the dice and then attempting to arange a group of crossed
words from the roll. Letters that occur at the intersection of two words count for double.

With a setup like this, there is a single highest scoring roll and arangement 
possible within the game. This program is an attempt at finding that high score.

## Process
1. Create all unique combinations of rolls from the 14 dice. 
To save time we will only be testing the highest scoring rolls.
2. Test possible arangements of cubes for each roll
Unsure how to do this but most likeley will be finding sets of valid words
within the roll and then aranging those sets at valid intersections.