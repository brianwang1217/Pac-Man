//
//  Player.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/20/18.
//  Copyright © 2018 Brian Wang. All rights reserved.
//

#include "Player.hpp"

Player::Player() {}

Player::~Player() {}


void Player::init()
{
    lives = 3;
    speed = 1;
    
    player_direction = stop;
    for (int i = 0; i < 4; i++) {
        direction_boolean[i] = false;
    }
}

void Player::update() {}

void Player::stop_player()
{
    player_direction = stop;
}
void Player::move_up()
{
    player_direction = up;
}
void Player::move_down()
{
    player_direction = down;
}
void Player::move_left()
{
    player_direction = left;
}
void Player::move_right()
{
    player_direction = right;
}
