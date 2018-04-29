#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    game_started = false;
    
    player = Player(15, 23);
    board_obj = Board();
    ghost1 = Ghost();
    ghost2 = Ghost();
    ghost3 = Ghost();
    ghost4 = Ghost();
    
    is_paused = false;
    game_over = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (game_started) {
        // If player collides with a ghost.
        
        /** Write a collision method elsewhere to check for multiple collisions. */
        if (ghost1.pos_x != player.pos_x && ghost1.pos_y != player.pos_y
            && ghost2.pos_x != player.pos_x && ghost2.pos_y != player.pos_y
            && ghost3.pos_x != player.pos_x && ghost3.pos_y != player.pos_y
            && ghost4.pos_x != player.pos_x && ghost4.pos_y != player.pos_y) {
            
            // Check if player collides with dotted block.
            if (board_obj.num_dots[player.pos_y][player.pos_x] == 1) {
                player.score += 1;
                board_obj.num_dots[player.pos_y][player.pos_x] = 0;
            }
            
            player.update();
            
            ghost1.update();
            ghost2.update();
            ghost3.update();
            ghost4.update();
        }
        
        // If player collides with one of the ghosts.
        else {
            player.lives -= 1;
            
            // If player has enough lives to continue.
            if (player.lives > 1) {
                player.reset();
                player.update();
                
                ghost1.update();
                ghost2.update();
                ghost3.update();
                ghost4.update();
            } else {
                game_over = true;
            }
        }
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

void ofApp::draw_game_start() {
    string start_message = "PAC-MAN\nPress 'B' to begin.";
    ofSetColor(100, 100, 100);
    ofDrawBitmapString(start_message, ofGetWindowWidth() / 2 - 50, ofGetWindowHeight() / 2);
}

void ofApp::draw_game_over() {
    string lose_message = "You Lost! Final Score: " + std::to_string(player.score);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(lose_message, ofGetWindowWidth() / 2 - 50, ofGetWindowHeight() / 2);
}

void ofApp::draw_pause() {
    string pause_message = "Paused. Your current score: " + std::to_string(player.score);
    string stat_message = "Lives: " + std::to_string(player.lives) + "\nScore: " + std::to_string(player.score);
    ofSetColor(0, 0, 0);
    
    ofDrawBitmapString(pause_message + "\n" + stat_message, ofGetWindowWidth() / 2 - 50, ofGetWindowHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    
    if (upper_key == 'W') {
        player.move_up();
    } else if (upper_key == 'A') {
        player.move_left();
    } else if (upper_key == 'S') {
        player.move_down();
    } else if (upper_key == 'D') {
        player.move_right();
    } else if (upper_key == 'B' && !game_started) {
        game_started = true;
    } else if (upper_key == 'P') {
        is_paused = !is_paused;
    }
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

