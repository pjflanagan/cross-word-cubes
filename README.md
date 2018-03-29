# Crossword Cubes

![alt text](https://github.com/pjflanagan/cross-word-cubes/raw/master/images/crosswordcubes.jpg "Crossword Cubes by SCRABBLE")

Crossword Cubes is a SCRABBLE game from the 60's played using 14 dice with letters on each face.
This is my attempt at programmatically finding the highest possible Crossword Cubes score. 

## Official Game Rules

### The Object

To compete for the highest score while forming words in crossword fashion.

### The Play

The players take turns placing all 14 cubes in the cup and tossing them. A timer is then set. 
Using the letters that appear on the top of the cubes, players form words
across and down and connected in a continuous crossword pattern. Words of any length
may be used, but they must be words found in a standard dictionary. Proper nouns,
foreign words, abbreviations, and words requiring apostrophes and hyphens are not allowed.
[For the sake of this project, blank faces will be omitted].

### Scoring

Each letter has a score value as indicated by a number on the cube. The score values
of the horizontal words and vertical words are totaled. The letter used where a 
vertical and horizontal word crosses is counted twice in scoring. The total values
of the cubes not used is deducted from the total score.

## Project 

This game has the potential for high scoring rolls, each with a corresponding high scoring arangement. 
This program is an attempt at finding the single highest scoring roll and arangement
possible within the game.

### Process
1. Create all unique combinations of rolls from the 14 dice. 
To save time we will only be testing the top ten thousand or so highest scoring rolls.
2. Test possible arangements of cubes for each roll.
This algorithm will work its way down the list of high scoring rolls and
devise potential words from each roll. It will then intersect those words and check 
that the arangement remains valid.

### Files
- cubes.txt contains the cubes used in the game. Cubes are arranged in descending value order
and faces are ordered by descending value. The last two cubes contain an extra 'a'
rather than a wildcard '*' for the sake of ease.
- scores.txt contains the value of each letter used in the game in alphabetical order.
- dictionary_original.txt is not included in this repository but is an english dictionary 
found on a [Github repository](https://github.com/dwyl/english-words/blob/master/words.txt).

### Run Commands
```
g++ Rolls/_rolls.cpp -o roll.exe
./roll.exe > Rolls/roll.txt

g++ Words/_generate_dict.cpp -o generate.exe
./generate.exe > Solve/dictionary_values.txt
```