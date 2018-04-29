//
//  Ghost.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/26/18.
//

#include "Ghost.hpp"
#include "Board.hpp"
#include <cstdlib>

Ghost::Ghost() {
    pos_x = 50;
    pos_y = 0;
    
    is_alive = true;
    speed = 1.0f;
    
    //red_ghost.load("../images/redghost.png");
    ghost_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/redghost.png");
    ghost_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    
    current_direction = direction_arr[rand() % 4];
}

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

void Ghost::update() {
    if (current_direction == up) {
        pos_y -= 1;
    } else if (current_direction == down) {
        pos_y += 1;
    } else if (current_direction == left) {
        pos_x -= 1;
    } else if (current_direction == right) {
        pos_x += 1;
    }
}

void Ghost::draw() {
    ghost_img.draw(pos_x, pos_y);
}

bool Ghost::can_move(direction dir) {
    /**
    if (dir == up) {
        return !(Board::board[this->pos_x - 1][this->pos_y] == Board::w);
    } else if (dir == down) {
        return !(Board::board[this->pos_x + 1][this->pos_y] == Board::w);
    } else if (dir == left) {
        return !(Board::board[this->pos_x][this->pos_y - 1] == Board::w);
    } else if (dir == right) {
        return !(Board::board[this->pos_x][this->pos_y + 1] == Board::w);
    }
    **/
    return false;
}

bool Ghost::at_intersection() {
    // Automatically 2 paths: forwards and backwards; need 3 or 4 for it to be intersection.
    int num_paths = 0;
    /**
    if (Board::board[this->pos_x - 1][this->pos_y] == Board::o) {
        num_paths++;
    } else if (Board::board[this->pos_x + 1][this->pos_y] == Board::o) {
        num_paths++;
    } else if (Board::board[this->pos_x][this->pos_y - 1] == Board::o) {
        num_paths++;
    } else if (Board::board[this->pos_x][this->pos_y + 1] == Board::o) {
        num_paths++;
    }
     **/
    
    return num_paths >= 3;
}

void Ghost::move_at_intersection() {
    int rand_direction = rand() % 4;
    while (!can_move(direction_arr[rand_direction])) {
        rand_direction = rand() % 4;
    }
    
    current_direction = direction_arr[rand_direction];
}

void Ghost::move_at_end() {
    if (!can_move(current_direction)) {
        int rand_direction = rand() % 4;
        while (!can_move(direction_arr[rand_direction])) {
            rand_direction = rand() % 4;
        }
        
        current_direction = direction_arr[rand_direction];
    }
}

