//
//  Game.h
//  Project 1
//
//  Created by Nick Chung on 1/6/21.
//

#ifndef Game_h
#define Game_h

class City;
class History;

class Game {
  public:
    // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();

    // Mutators
    void play();

private:
    City* m_city;
};

#endif /* Game_h */
