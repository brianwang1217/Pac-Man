#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Ghost.hpp"
#include "Board.hpp"

class ofApp : public ofBaseApp{

public:
        void setup();
		void update();
		void draw();
    
    void draw_game_over();
    void draw_pause();
    void draw_game_start();

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
    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;
};
