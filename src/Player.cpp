//
//  Player.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/25/18.
//

#include "Player.hpp"
#include "Board.hpp"

Player::Player() {
    
}

Player::Player(int x, int y) {
    is_alive = true;
    
    spawn_x = x;
    spawn_y = y;
    pos_x = x;
    pos_y = y;
    current_direction = left;
    
    pacman_left.load("\images\pacleft.png");
    pacman_right.load("\images\pacright.png");
    pacman_up.load("\images\pacup.png");
    pacman_down.load("\images\pacdown.png");
        
    speed = 1.0f;
    lives = 3;
    score = 0;
}

void Player::update() {
    if (current_direction == up) {
        pos_x -= 1;
    } else if (current_direction == down) {
        pos_x += 1;
    } else if (current_direction == left) {
        pos_y -= 1;
    } else if (current_direction == right) {
        pos_y += 1;
    }
}

void Player::reset() {
    lives -= 1;
    pos_x = spawn_x;
    pos_y = spawn_y;
    current_direction = left;
}

void Player::move_up() {
    if (can_move(up)) {
        current_direction = up;
    }
}

void Player::move_down() {
    if (can_move(down)) {
        current_direction = down;
    }
}

void Player::move_left() {
    if (can_move(left)) {
        current_direction = left;
    }
}

void Player::move_right() {
    if (can_move(right)) {
        current_direction = right;
    }
}

bool Player::can_move(direction dir) {
    if (dir == up) {
        return !(Board::board[this->pos_x - 1][this->pos_y] == Board::w);
    } else if (dir == down) {
        return !(Board::board[this->pos_x + 1][this->pos_y] == Board::w);
    } else if (dir == left) {
        return !(Board::board[this->pos_x][this->pos_y - 1] == Board::w);
    } else if (dir == right) {
        return !(Board::board[this->pos_x][this->pos_y + 1] == Board::w);
    }
    
    return false;
}

void Player::draw() {
    if (current_direction == up) {
        pacman_up.draw(pos_x, pos_y);
    } else if (current_direction == down) {
        pacman_down.draw(pos_x, pos_y);
    } else if (current_direction == left) {
        pacman_left.draw(pos_x, pos_y);
    } else if (current_direction == right) {
        pacman_right.draw(pos_x, pos_y);
    }
}

