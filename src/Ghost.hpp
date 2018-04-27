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
    void move_at_end();
    
    // Variables.
    int pos_x;
    int pos_y;
    
    ofImage ghost_img;
    
    float speed;
    
    enum direction{up, down, left, right};
    direction current_direction;
    direction direction_arr[4] = {up, down, left, right};
    
    void load_image(ofImage img, string url);
    
    bool is_alive;
    bool can_move(direction dir);
};

#endif /* Ghost_hpp */

