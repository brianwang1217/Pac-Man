//
//  Ghost.hpp
//  Pac-Man
//
//  Created by Brian Wang on 4/20/18.
//  Copyright © 2018 Brian Wang. All rights reserved.
//

#ifndef Ghost_hpp
#define Ghost_hpp

#include <stdio.h>

class Ghost
{
public:
    // Constructors and functions.
    Ghost();
    ~Ghost();
    void init();
    void update();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void stop_ghost();
    
    // Variables.
    int pos_x;
    int pos_y;
    int speed;
    bool is_alive = false;
    
    enum direction {up, down, left, right, stop};
    bool direction_boolean[4];
    
    // Default direction.
    direction player_direction = up;
private:
};

#endif /* Ghost_hpp */
