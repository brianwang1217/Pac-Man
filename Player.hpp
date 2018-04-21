//
//  Player.hpp
//  Pac-Man
//
//  Created by Brian Wang on 4/20/18.
//  Copyright © 2018 Brian Wang. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

class Player
{
public:
    // Constructors and methods.
    Player();
    ~Player();
    void init();
    void update();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void stop_player();
    
    // Variables.
    int lives;

    int pos_x;
    int pos_y;
    int speed;
    bool is_alive = false;
    
    enum direction {up, down, left, right, stop};
    bool direction_boolean[4];
    
    // Default direction.
    direction player_direction = up;
    double timer = 0.0;

private:
};

#endif // Player_hpp
