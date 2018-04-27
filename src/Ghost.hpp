//
//  Ghost.hpp
//  Pac-Man
//
//  Created by Brian Wang on 4/26/18.
//

#ifndef Ghost_hpp
#define Ghost_hpp

#include <stdio.h>
#include "ofMain.h"

class Ghost {
public:
    // Constructors and methods.
    Ghost();
    Ghost(int x, int y);
    bool at_intersection();
    void move_at_intersection();
    void update();
    void draw();
    
    // Variables.
    int pos_x;
    int pos_y;
    
    ofImage red_ghost;
    ofImage green_ghost;
    ofImage orange_ghost;
    
    float speed;
    
    enum direction{up, down, left, right};
    direction current_direction;
    direction direction_arr[4] = {up, down, left, right};
    
    bool is_alive;
    bool can_move(direction dir);
};

#endif /* Ghost_hpp */

