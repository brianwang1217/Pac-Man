//
//  Player.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/25/18.
//

#include "Player.hpp"

/*:
    Empty constructor.
 */
Player::Player() {}

/*:
    Constructor taking in x and y coordinate for Player.
 */
Player::Player(int x, int y) {
    is_alive = true;
    
    spawn_x = x;
    spawn_y = y;
    pos_x = x;
    pos_y = y;
    current_direction = left;
    
    // Load images and resize them to fit the screen.
    pacman_left.load("/images/pacleft.png");
    pacman_left.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    pacman_right.load("/images/pacright.png");
    pacman_right.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    pacman_up.load("/images/pacup.png");
    pacman_up.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    pacman_down.load("/images/pacdown.png");
    pacman_down.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    
    // Other statistics to keep track of.
    speed = 1.0f;
    lives = 3;
    score = 0;
}

/*:
    Call funciton to update player position.
 */
void Player::update() {
    if (current_direction == up) {
        pos_y -= 1;
    } else if (current_direction == down) {
        pos_y += 1;
    } else if (current_direction == left) {
        // Makes sure the player wraps around to other side instead of endlessly going to the left.
        if (pos_x < 0) {
            pos_x = 27;
        } else {
            pos_x -= 1;
        }
    } else if (current_direction == right) {
        if (pos_x > 27) {
            pos_x = 0;
            
        } else {
            pos_x += 1;
        }
    }
}

/*:
    After death, respawns the player at point of origin.
 */
void Player::reset() {
    pos_x = spawn_x;
    pos_y = spawn_y;
    current_direction = left;
}

/*:
    Moves up if capable. Returns true if able.
 */
bool Player::move_up() {
    if (can_move(up)) {
        current_direction = up;
        return true;
    }
    return false;
}

/*:
    Moves down if capable. Returns true if able.
 */
bool Player::move_down() {
    if (can_move(down)) {
        current_direction = down;
        return true;
    }
    return false;
}

/*:
    Moves left if capable. Returns true if able.
 */
bool Player::move_left() {
    if (can_move(left)) {
        current_direction = left;
        return true;
    }
    return false;
}

/*:
    Moves right if capable. Returns true if able.
 */
bool Player::move_right() {
    if (can_move(right)) {
        current_direction = right;
        return true;
    }
    return false;
}

/*:
    Checks if player can move in a certain direction.
 */
bool Player::can_move(direction dir) {
    
    if (dir == up) {
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
    Draws player with different ofImages depending on player direction, at x and y coordinate (scaled to fit).
 */
void Player::draw() {
    if (current_direction == up) {
        pacman_up.draw(pos_x * ofGetWindowWidth() / 28, pos_y * ofGetWindowHeight() / 30);
    } else if (current_direction == down) {
        pacman_down.draw(pos_x * ofGetWindowWidth() / 28, pos_y * ofGetWindowHeight() / 30);
    } else if (current_direction == left) {
        pacman_left.draw(pos_x * ofGetWindowWidth() / 28, pos_y * ofGetWindowHeight() / 30);
    } else if (current_direction == right) {
        pacman_right.draw(pos_x * ofGetWindowWidth() / 28, pos_y * ofGetWindowHeight() / 30);
    }
}

