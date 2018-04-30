//
//  Ghost.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/26/18.
//

#include "Ghost.hpp"
#include "Board.hpp"
#include <cstdlib>

/*:
    Constructor for ghost with no parameters.
 */
Ghost::Ghost() {
    pos_x = 13;
    pos_y = 14;
    
    is_alive = true;
    speed = 1.0f;
    
    //red_ghost.load("../images/redghost.png");
    ghost_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/redghost.png");
    ghost_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    
    //current_direction = direction_arr[rand() % 4];
    current_direction = up;
}

/*:
    Constructor taking in two parameters for its x and y coordinates.
 */
Ghost::Ghost(int x, int y) {
    pos_x = x;
    pos_y = y;
    
    is_alive = true;
    speed = 1.0f;
    
    //red_ghost.load("../images/redghost.png");
    ghost_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/redghost.png");
    ghost_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    
    current_direction = direction_arr[rand() % 4];
    while (!can_move(current_direction)) {
        current_direction = direction_arr[rand() % 4];
    }
}

/*:
    Updates Ghost object by changing x or y coordinates based on the character's ability to move in a certain direction.
 */
void Ghost::update() {
    // If the ghost is currently moving up...
    if (current_direction == up) {
        // and can continue to move up and is not at an itersection.
        if (can_move(up) && !at_intersection()) {
            pos_y -= 1;
        }
        // but is at an intersection.
        else if (at_intersection()) {
            change_direction();
        }
        // but can no longer continue moving up and must change direction.
        else {
            move_at_end();
        }
    }
    
    // If the ghost is currently moving down.
    else if (current_direction == down) {
        if (can_move(down) && !at_intersection()) {
            pos_y += 1;
        } else if (at_intersection()) {
            change_direction();
        } else {
            move_at_end();
        }
    }
    
    // If the ghost is currently moving left.
    else if (current_direction == left) {
        if (can_move(left) && !at_intersection()) {
            // We want the ghost to wrap around the map instead of walking off the board forever.
            if (pos_x < 0) {
                pos_x = 27;
            } else {
                pos_x -= 1;
            }
        } else if (at_intersection()) {
            change_direction();
        } else {
            move_at_end();
        }
    }
    
    // If the ghost is currently moving right.
    else if (current_direction == right) {
        if (can_move(right) && !at_intersection()) {
            // We want the ghost to wrap around the map instead of walking off the board forever.
            if (pos_x > 27) {
                pos_x = 0;
            } else {
                pos_x += 1;
            }
        } else if (at_intersection()) {
            change_direction();
        } else {
            move_at_end();
        }
    }
}

/*:
    Draws ghost at current x and y coordinate.
 */
void Ghost::draw() {
    ghost_img.draw(pos_x * ofGetWindowWidth() / 28, pos_y * ofGetWindowHeight() / 30);
}

/*:
    Checks if the ghost can move in a certain direction.
 */
bool Ghost::can_move(direction dir) {
    if (dir == up) {
        // Check if the block in front of the ghost is a wall or open block.
        return !(board[(this->pos_y - 1)][this->pos_x] == w);
    } else if (dir == down) {
        if (pos_y + 1 < 30) {
            return !(board[(this->pos_y + 1)][this->pos_x] == w);
        } else {
            return false;
        }
    } else if (dir == left) {
        if (pos_x > 0) {
            return !(board[(this->pos_y)][this->pos_x - 1] == w);
        } else {
            return true;
        }
    } else if (dir == right) {
        if (pos_x < 27) {
            return !(board[this->pos_y][this->pos_x + 1] == w);
        } else {
            return true;
        }
    }
    
    return false;
}
/*:
    Checks if the ghost is at an intersection (
 */
bool Ghost::at_intersection() {
    // Automatically 2 paths: forwards and backwards; need 3 or 4 for it to be intersection.
    int num_paths = 0;
    
    // Check for open blocks next to player position.
    if (board[this->pos_y - 1][this->pos_x] == o) {
        num_paths++;
    }
    if (board[this->pos_y + 1][this->pos_x] == o) {
        num_paths++;
    }
    if (board[this->pos_y][this->pos_x - 1] == o) {
        num_paths++;
    }
    if (board[this->pos_y][this->pos_x + 1] == o) {
        num_paths++;
    }
    
    return num_paths >= 3;
}

/*:
    If at intersection, move in a random direction.
 */
void Ghost::move_at_intersection() {
    int rand_direction = rand() % 4;
    // Keep rerolling direction until ghost can move.
    while (!can_move(direction_arr[rand_direction])) {
        rand_direction = rand() % 4;
    }
    
    current_direction = direction_arr[rand_direction];
}

/*:
    Once the ghost meets wall, it tries to change direction.
 */
void Ghost::move_at_end() {
    if (!can_move(current_direction)) {
        int rand_direction = rand() % 4;
        while (!can_move(direction_arr[rand_direction])) {
            rand_direction = rand() % 4;
        }
        
        current_direction = direction_arr[rand_direction];
    }
}

/*:
    Changes direction randomly until it can move in that direction.
 */
void Ghost::change_direction() {
    int rand_direction = rand() % 4;
    while (direction_arr[rand_direction] == current_direction) {
        rand_direction = rand() % 4;
    }
    
    current_direction = direction_arr[rand_direction];

    // Move the ghost out of the intersection after changing direction.
    if (current_direction == up) {
        if (can_move(up)) {
            pos_y -= 1;
        } else {
            move_at_end();
        }
    } else if (current_direction == down) {
        if (can_move(down)) {
            pos_y += 1;
        } else {
            move_at_end();
        }
    } else if (current_direction == left) {
        if (can_move(left)) {
            pos_x -= 1;
        } else {
            move_at_end();
        }
    } else if (current_direction == right) {
        if (can_move(right)) {
            pos_x += 1;
        } else {
            move_at_end();
        }
    }
}

