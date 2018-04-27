#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    player = Player(10, 5);
    ghost1 = Ghost();
    ghost2 = Ghost();
    ghost3 = Ghost();
    ghost4 = Ghost();
}

//--------------------------------------------------------------
void ofApp::update(){
    // If player collides with a ghost.
    if (ghost1.pos_x != player.pos_x && ghost1.pos_y != player.pos_y
        && ghost2.pos_x != player.pos_x && ghost2.pos_y != player.pos_y
        && ghost3.pos_x != player.pos_x && ghost3.pos_y != player.pos_y
        && ghost4.pos_x != player.pos_x && ghost4.pos_y != player.pos_y) {
        
        player.update();
        
        ghost1.update();
        ghost2.update();
        ghost3.update();
        ghost4.update();
    }
    
    // If player collides with one of the ghosts.
    else {
        player.reset();
        player.update();
        
        ghost1.update();
        ghost2.update();
        ghost3.update();
        ghost4.update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawRectangle(0, 0, 4, 4);
    player.draw();
    ghost1.draw();
    ghost2.draw();
    ghost3.draw();
    ghost4.draw();
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

