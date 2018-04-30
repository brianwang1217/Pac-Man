//
//  Board.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/25/18.
//

#include "Board.hpp"

block_type board[30][28] =
{
    {w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w},
    {w, o, o, o, o, o, o, o, o, o, o, o, o, w, w, o, o, o, o, o, o, o, o, o, o, o, o, w},
    {w, o, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, o, w},
    {w, o, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, o, w},
    {w, o, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, o, w},
    {w, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, w},
    {w, o, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, o, w},
    {w, o, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, o, w},
    {w, o, o, o, o, o, o, w, w, o, o, o, o, w, w, o, o, o, o, w, w, o, o, o, o, o, o, w},
    {w, w, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, o, o, o, o, o, o, o, o, o, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, w, w, w, o, o, w, w, w, o, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, w, w, w, o, o, w, w, w, o, w, w, o, w, w, w, w, w, w},
    {o, o, o, o, o, o, o, o, o, o, w, o, o, o, o, o, o, w, o, o, o, o, o, o, o, o, o, o},
    {w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, o, o, o, o, o, o, o, o, o, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w},
    {w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w},
    {w, o, o, o, o, o, o, o, o, o, o, o, o, w, w, o, o, o, o, o, o, o, o, o, o, o, o, w},
    {w, o, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, o, w},
    {w, o, w, w, w, w, o, w, w, w, w, w, o, w, w, o, w, w, w, w, w, o, w, w, w, w, o, w},
    {w, o, o, o, w, w, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, w, w, o, o, o, w},
    {w, w, w, o, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, o, w, w, w},
    {w, w, w, o, w, w, o, w, w, o, w, w, w, w, w, w, w, w, o, w, w, o, w, w, o, w, w, w},
    {w, o, o, o, o, o, o, w, w, o, o, o, o, w, w, o, o, o, o, w, w, o, o, o, o, o, o, w},
    {w, o, w, w, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, w, w, o, w},
    {w, o, w, w, w, w, w, w, w, w, w, w, o, w, w, o, w, w, w, w, w, w, w, w, w, w, o, w},
    {w, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, w}
};

Board::Board() {
    // Load images.
    wall_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/wall_block.png");
    open_block_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/empty_block.png");
    dot_block_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/dot_block.png");
    refresh_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/refresh.png");
    slow_img.load("/Users/bwang/of_v0.9.8_osx_release/apps/myApps/Pac-Man/images/clock.png");
    
    // Resize image for board.
    wall_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    open_block_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    dot_block_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    refresh_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    slow_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    
    has_refreshed = true;
}

void Board::draw_board() {
    // If there are no dots left, draw refresh power up at random xy coord.
    if (count_dots() == 0) {
        has_refreshed = false;
        refresh_x = rand() % 28;
        refresh_y = rand() % 30;
        
        while (board[refresh_y][refresh_x] != o) {
            refresh_x = rand() % 28;
            refresh_y = rand() % 30;
        }
    }
    
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            if (board[i][j] == w) {
                wall_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
            } else {
                if (num_dots[i][j] == 0) {
                    open_block_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                    
                    // If these are the xy coords for the refresh power-up, draw it.
                    if (refresh_x == j && refresh_y == i) {
                        refresh_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                    }
                } else {
                    dot_block_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                }
            }
        }
    }
    
    if (has_refreshed) {
        refresh_x = -1;
        refresh_y = -1;
    }
}

int Board::count_dots() {
    int dot_count = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            if (num_dots[i][j] == 1) {
                dot_count++;
            }
        }
    }
    return dot_count;
}

void Board::refresh_board() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            num_dots[i][j] = num_dots_copy[i][j];
        }
    }
}
