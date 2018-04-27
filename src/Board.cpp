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

Board::Board() {}

void Board::draw_board() {
    
}

void Board::draw_dots() {
    
}
