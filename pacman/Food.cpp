//
//  Food.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/20/18.
//  Copyright © 2018 Brian Wang. All rights reserved.
//

#include "Food.hpp"

class Food
{
public:
    Food();
    ~Food();
    void init();
    void update();
    
    int pos_x;
    int pos_y;
    bool exists = false;
};
