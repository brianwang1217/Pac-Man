//
//  Player.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/25/18.
//

#include "Player.hpp"

Player::Player() {}

Player::Player(int x, int y) {
    is_alive = true;
    
    spawn_x = x;
    spawn_y = y;
    pos_x = x;
    pos_y = y;
    current_direction = left;
    
    pacman_left.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/pacleft.png");
    pacman_left.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    pacman_right.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/pacright.png");
    pacman_right.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    pacman_up.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/pacup.png");
    pacman_up.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    pacman_down.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/pacdown.png");
    pacman_down.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
        
    speed = 1.0f;
    lives = 3;
    score = 0;
}

void Player::update() {
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

void Player::reset() {
    lives -= 1;
    pos_x = spawn_x;
    pos_y = spawn_y;
    current_direction = left;
}

void Player::move_up() {
    //if (can_move(up)) {
        current_direction = up;
    //}
}

void Player::move_down() {
    //if (can_move(down)) {
        current_direction = down;
    //}
}

void Player::move_left() {
    //if (can_move(left)) {
        current_direction = left;
    //}
}

void Player::move_right() {
    //if (can_move(right)) {
        current_direction = right;
    //}
}

bool Player::can_move(direction dir) {
    
    if (dir == up) {
        return !(board[this->pos_x - 1][this->pos_y] == w);
    } else if (dir == down) {
        return !(board[this->pos_x + 1][this->pos_y] == w);
    } else if (dir == left) {
        return !(board[this->pos_x][this->pos_y - 1] == w);
    } else if (dir == right) {
        return !(board[this->pos_x][this->pos_y + 1] == w);
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

