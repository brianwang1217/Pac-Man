#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    game_started = false;
    can_move = true;
    
    player = Player(15, 23);
    board_obj = Board();
    
    // Ghosts.
    ghost1 = Ghost();
    ghost2 = Ghost();
    ghost3 = Ghost();
    ghost4 = Ghost();
    
    is_paused = false;
    game_over = false;
    
    sound_player.load("/sounds/pacman_beginning.wav", true);
    sound_player.play();
    
    frame_count = 0;
    high_score = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Make sure to unload the sound player if nothing is playing, so no differing sounds overlap.
    if (!sound_player.isPlaying()) {
        sound_player.unload();
    }
    
    ghost1.update();
    ghost2.update();
    ghost3.update();
    ghost4.update();
    
    // If the player dies, frame_count is increased from 0 to 1 and game no longer updates.
    // This is to ensure a respawn timer that lasts 15 updates; the ghosts are not affected, but everything else is.
    if (frame_count == 0) {
        // While game is in progress.
        if (game_started && !is_paused && !game_over) {
            // If player collides with a ghost.
            if (collided()) {
                player.lives -= 1;
                
                // Play death sound effect.
                sound_player.unload();
                sound_player.load("/sounds/pacman_death.wav", true);
                sound_player.play();
                if (!sound_player.isPlaying()) {
                    sound_player.unload();
                }
                
                frame_count++;
                
                // If player has enough lives to continue.
                if (player.lives > 0) {
                    player.reset();
                    //player.update();
                } else {
                    game_over = true;
                }
            }
            
            // While player can move in direction.
            if (can_move) {
                
                // Check if player collides with dotted block.
                if (board_obj.num_dots[player.pos_y][player.pos_x] == 1) {
                    player.score += 1;
                    board_obj.num_dots[player.pos_y][player.pos_x] = 0;
                    
                    // Play eating sound effect.
                    //sound_player.unload();
                    if (!sound_player.isLoaded()) {
                        sound_player.load("/sounds/pacman_chomp.wav",  true);
                        sound_player.setSpeed(1.25);
                        sound_player.play();
                    }
                    
                } else {
                    // Play moving sound effect.
                    //sound_player.unload();
                    //sound_player.load("/sounds/pacman_move.wav", true);
                    //sound_player.play();
                }

                player.update();
            }
            
            // Check if player collides with refresh power-up.
            if (player.pos_y == board_obj.refresh_y && player.pos_x == board_obj.refresh_x) {
                // If collides, readd dots to the board.
                board_obj.refresh_board();
                board_obj.has_refreshed = true;
            }
            
            // Check if player collides with oneup power-up.
            if (player.pos_y == board_obj.oneup_y && player.pos_x == board_obj.oneup_x) {
                sound_player.unload();
                sound_player.load("/sounds/smb_1-up.wav", true);
                sound_player.play();
                if (!sound_player.isPlaying()) {
                    sound_player.unload();
                }
                board_obj.oneup_exists = false;
                board_obj.oneup_x = -1;
                board_obj.oneup_y = -1;
                
                player.lives++;
            }
            
            // Gets player direction, and checks if player can continue moving in that direction.
            if (player.current_direction == player.up) {
                can_move = player.can_move(Player::up);
            } else if (player.current_direction == player.down) {
                can_move = player.can_move(Player::down);
            } else if (player.current_direction == player.left) {
                can_move = player.can_move(Player::left);
            } else if (player.current_direction == player.right) {
                can_move = player.can_move(Player::right);
            }
        }
    } else {
        frame_count++;
    }
    
    if (frame_count == 15) {
        frame_count = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // If the game has started.
    if (!game_started) {
        draw_game_start();
    }
    // If it is paused.
    else if (is_paused) {
        draw_pause();
    }
    // If game is over.
    else if (game_over) {
        draw_game_over();
    }
    else {
        board_obj.draw_board();
        
        // Draw score and number of lives.
        string stat_message = "Lives: " + std::to_string(player.lives) + "\nScore: " + std::to_string(player.score);
        ofDrawBitmapString(stat_message, ofGetWindowWidth() - 200, 10);
        
        // Draw player depending on his/her direction.
        if (player.current_direction == Player::up) {
            player.pacman_up.draw(player.pos_x * ofGetWindowWidth() / 28, player.pos_y * ofGetWindowHeight() / 30);
        } else if (player.current_direction == Player::down) {
            player.pacman_down.draw(player.pos_x * ofGetWindowWidth() / 28, player.pos_y * ofGetWindowHeight() / 30);
        } else if (player.current_direction == Player::left) {
            player.pacman_left.draw(player.pos_x * ofGetWindowWidth() / 28, player.pos_y * ofGetWindowHeight() / 30);
        } else if (player.current_direction == Player::right) {
            player.pacman_right.draw(player.pos_x * ofGetWindowWidth() / 28, player.pos_y * ofGetWindowHeight() / 30);
        }
        
        ghost1.draw();
        ghost2.draw();
        ghost3.draw();
        ghost4.draw();
    }
}

/*:
    Checks if player has collided with ghost.
 */
bool ofApp::collided() {
    // If they are on the same block at the same time.
    if ((ghost1.pos_x == player.pos_x && ghost1.pos_y == player.pos_y)
        || (ghost2.pos_x == player.pos_x && ghost2.pos_y == player.pos_y)
        || (ghost3.pos_x == player.pos_x && ghost3.pos_y == player.pos_y)
        || (ghost4.pos_x == player.pos_x && ghost4.pos_y == player.pos_y)) {
        return true;
    }
    
    /// If they switch blocks but never actually end up on the same block.
    
    // Vertically.
    if ((ghost1.pos_x == player.pos_x && abs(ghost1.pos_y - player.pos_y) == 1)) {
        if ((ghost1.current_direction == Ghost::up && player.current_direction == player.down)
            || (ghost1.current_direction == Ghost::down && player.current_direction == player.up)) {
            return true;
        }
    } else if ((ghost2.pos_x == player.pos_x && abs(ghost2.pos_y - player.pos_y) == 1)) {
        if ((ghost2.current_direction == Ghost::up && player.current_direction == player.down)
            || (ghost2.current_direction == Ghost::down && player.current_direction == player.up)) {
            return true;
        }
    } else if ((ghost3.pos_x == player.pos_x && abs(ghost3.pos_y - player.pos_y) == 1)) {
        if ((ghost3.current_direction == Ghost::up && player.current_direction == player.down)
            || (ghost3.current_direction == Ghost::down && player.current_direction == player.up)) {
            return true;
        }
    } else if ((ghost4.pos_x == player.pos_x && abs(ghost4.pos_y - player.pos_y) == 1)) {
        if ((ghost4.current_direction == Ghost::up && player.current_direction == player.down)
            || (ghost4.current_direction == Ghost::down && player.current_direction == player.up)) {
            return true;
        }
    }
    
    // Horizontally.
    if ((ghost1.pos_y == player.pos_y && abs(ghost1.pos_x - player.pos_x) == 1)) {
        if ((ghost1.current_direction == Ghost::left && player.current_direction == player.right)
            || (ghost1.current_direction == Ghost::right && player.current_direction == player.left)) {
            return true;
        }
    } else if ((ghost2.pos_y == player.pos_y && abs(ghost2.pos_x - player.pos_x) == 1)) {
        if ((ghost2.current_direction == Ghost::left && player.current_direction == player.right)
            || (ghost2.current_direction == Ghost::right && player.current_direction == player.left)) {
            return true;
        }
    } else if ((ghost3.pos_y == player.pos_y && abs(ghost3.pos_x - player.pos_x) == 1)) {
        if ((ghost3.current_direction == Ghost::left && player.current_direction == player.right)
            || (ghost3.current_direction == Ghost::right && player.current_direction == player.left)) {
            return true;
        }
    } else if ((ghost4.pos_y == player.pos_y && abs(ghost4.pos_x - player.pos_x) == 1)) {
        if ((ghost4.current_direction == Ghost::left && player.current_direction == player.right)
            || (ghost4.current_direction == Ghost::right && player.current_direction == player.left)) {
            return true;
        }
    }
    
    return false;
}

/*:
    Draws start menu GUI for game.
 */
void ofApp::draw_game_start() {
    string start_message = "PAC-MAN\nPress 'B' to begin.";
    board_obj.draw_board();
    ofSetColor(255, 255, 0);
    ofDrawBitmapString(start_message, ofGetWindowWidth() / 2 - 50, ofGetWindowHeight() / 2);
}

/*:
    Draw game over menu GUI for game.
 */
void ofApp::draw_game_over() {
    if (player.score > high_score) {
        high_score = player.score;
    }
    string lose_message = "You Lost! Final Score: " + std::to_string(player.score) + "\nPress 'R' to play again.";
    string high_score_message = "Your Highest Score: \n" + std::to_string(high_score);
    
    //ofSetColor(0, 0, 255);
    
    ofDrawBitmapString(lose_message, ofGetWindowWidth() / 2 - 100, ofGetWindowHeight() / 2);
    ofDrawBitmapString(high_score_message, ofGetWindowWidth() / 2 - 75, ofGetWindowHeight() / 2 + 50);
}

/*:
    Draw pause menu GUI for game.
 */
void ofApp::draw_pause() {
    string pause_message = "Paused. Your current score: " + std::to_string(player.score);
    string stat_message = "Lives: " + std::to_string(player.lives) + "\nScore: " + std::to_string(player.score);
    
    board_obj.draw_board();
    ofDrawBitmapString(pause_message + "\n" + stat_message, ofGetWindowWidth() / 2 - 50, ofGetWindowHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    
    // WASD for standard movement controls.
    // B for begin, P for pause, R for restart.
    if (upper_key == 'B' && !game_started) {
        game_started = true;
    }
    
    if (upper_key == 'P') {
        is_paused = !is_paused;
    }
    
    if (game_started && !is_paused) {
        if (upper_key == 'W') {
            player.move_up();
        } else if (upper_key == 'A') {
            player.move_left();
        } else if (upper_key == 'S') {
            player.move_down();
        } else if (upper_key == 'D') {
            player.move_right();
        }
    }
    
    if (upper_key == 'R' && game_over) {
        restart();
    }
}

void ofApp::restart() {
    game_started = false;
    can_move = true;
    
    player = Player(15, 23);
    board_obj = Board();
    
    // Ghosts.
    ghost1 = Ghost();
    ghost2 = Ghost();
    ghost3 = Ghost();
    ghost4 = Ghost();
    
    is_paused = false;
    game_over = false;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    /**
    if (!game_started
        && (x >= ofGetWindowWidth() / 2 - 50 && x <= ofGetWindowWidth() / 2 + 50)
        && (y >= ofGetWindowHeight() / 2 - 15 && x <= ofGetWindowHeight() / 2 + 15)) {
        game_started = true;
    }*/
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

