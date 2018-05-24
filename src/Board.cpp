//
//  Board.cpp
//  Pac-Man
//
//  Created by Brian Wang on 4/25/18.
//

#include "Board.hpp"

// Board to be played on.
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

/*:
    Constructor with no parameters.
 */
Board::Board() {
    // Load images.
    wall_img.load("/images/wall_block.png");
    open_block_img.load("/images/empty_block.png");
    dot_block_img.load("/images/dot_block.png");
    refresh_img.load("/images/refresh.png");
    oneup_img.load("/images/oneup_img.png");
    
    // Resize image for board.
    wall_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    open_block_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    dot_block_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    refresh_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    oneup_img.resize(ofGetWindowWidth() / 28, ofGetWindowHeight() / 30);
    
    has_refreshed = true;
    oneup_exists = false;
}

/*:
    Draws board given 2D array of block_type as well as dot 2D array.
 */
void Board::draw_board() {
    // If there are no dots left, draw refresh power up at random xy coord.
    if (count_dots() == 2 && has_refreshed) {
        has_refreshed = false;
        refresh_x = rand() % 28;
        refresh_y = rand() % 30;
        
        while (board[refresh_y][refresh_x] != o) {
            refresh_x = rand() % 28;
            refresh_y = rand() % 30;
        }
    }
    
    // Randomly generate one-up power-up.
    if (rand() % 500 == 1 && !oneup_exists) {
        oneup_exists = true;
        oneup_x = rand() % 28;
        oneup_y = rand() % 30;
        
        while (board[oneup_y][oneup_x] != o) {
            oneup_x = rand() % 28;
            oneup_y = rand() % 30;
        }
    }
        
    // Draw wall if 'w'; if 'o', draw either dotted or empty open block.
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            if (board[i][j] == w) {
                wall_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
            } else {
                // If open block is empty.
                if (num_dots[i][j] == 0) {
                    open_block_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                }
                // If open block contains a dot on it.
                else {
                    dot_block_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                }
                
                // If these are the xy coords for the refresh power-up, draw it.
                if (refresh_x == j && refresh_y == i) {
                    refresh_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                }
                
                // Draw one-up power up if it exists on this coordinate.
                if (oneup_exists && oneup_x == j && oneup_y == i) {
                    oneup_img.draw(j * ofGetWindowWidth() / 28, i * ofGetWindowHeight() / 30);
                }
            }
        }
    }
    
    // Reset power-up coords and remove from board if power-up has been taken.
    if (has_refreshed) {
        refresh_x = -1;
        refresh_y = -1;
    }
}

/*:
    Count the number of dots in the 2D num_dots array. If there are no dots, then player has cleared the board.
 */
int Board::count_dots() {
    int dot_count = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            dot_count += num_dots[i][j];
        }
    }
    std::cout << dot_count << std::endl;
    return dot_count;
}

/*:
    Refreshes board by resetting num_dots array to its original values.
 */
void Board::refresh_board() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 28; j++) {
            num_dots[i][j] = num_dots_copy[i][j];
            has_refreshed = true;
        }
    }
}
