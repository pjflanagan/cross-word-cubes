
class Tile {
  public:
  Tile(letter_in) {
    letter = letter_in;
    
  }

  private: 
  char letter;
  Tile * up;
  Tile * down;
  Tile * left;
  Tile * right;
}