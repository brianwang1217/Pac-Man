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
    
    // Resize image for board.
    wall_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    open_block_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    dot_block_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
}

void Board::draw_board() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            if (board[i][j] == w) {
                wall_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
            } else {
                open_block_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
            }
        }
    }
}

void Board::draw_dots() {
    
}
