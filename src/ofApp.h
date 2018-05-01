#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Ghost.hpp"
#include "Board.hpp"
#include <cmath>
#include "ofxBaseGui.h"
#include "ofxButton.h"

class ofApp : public ofBaseApp{

public:
        void setup();
		void update();
		void draw();
    
    void draw_game_over();
    void draw_pause();
    void draw_game_start();
    void restart();
    bool collided();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    bool game_over;
    bool is_paused;
    bool game_started;
		
private:
    Player player;
    Board board_obj;
    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;
        
    bool can_move;
    ofSoundPlayer sound_player;
    ofColor button_color;
    //ofxBaseGui start_screen;
    //ofxButton start_button;
    int frame_count;
};
