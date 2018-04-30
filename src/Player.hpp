//
//  Player.hpp
//  Pac-Man
//
//  Created by Brian Wang on 4/25/18.
//

#ifndef Player_hpp
#define Player_hpp

#include "ofMain.h"
#include "Board.hpp"

#include <stdio.h>

class Player {
public:
    // Constructor and methods.
    Player();
    Player(int x, int y);
    void setup();
    void update();
    void reset();
    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();
    void draw();
    
    // Variables.
    //const float scale_variable_x = ofGetWindowWidth() / 30;
    //const float scale_variable_y = ofGetWindowHeight() / 30;
    
    ofImage pacman_left;
    ofImage pacman_up;
    ofImage pacman_right;
    ofImage pacman_down;
    
    int lives;
    
    float spawn_x;
    float spawn_y;
    int pos_x;
    int pos_y;
    float map_x;
    float map_y;
    
    int score;
    
    float speed;
    
    enum direction {up, down, left, right};
    direction current_direction;
    
    bool is_alive;
    bool can_move(direction dir);
};

#endif /* Player_hpp */

