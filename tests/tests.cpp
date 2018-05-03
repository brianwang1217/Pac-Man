/**
//
//  tests.cpp
//  Pac-Man
//
//  Created by Brian Wang on 5/2/18.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Player.cpp"
#include "../src/Board.hpp"
#include "../src/Ghost.hpp"

// PLAYER TESTS
 
TEST_CASE("Player Constructor") {
    Player player = Player(15, 25);
    REQUIRE(15 == player.pos_x);
}

TEST_CASE("Player update()") {
    Player player = Player(15, 23);
    player.update();
    REQUIRE(player.pos_x == 14);
}

TEST_CASE("Player move_right()") {
    Player player = Player(15, 23);
    REQUIRE(player.move_right());
}

TEST_CASE("Player reset()") {
    Player player = Player(15, 23);
    player.update();
    player.reset();
    REQUIRE(player.pos_x == 15);
}

TEST_CASE("Player can_move() test false") {
    Player player = Player(15, 23);
    REQUIRE(!player.can_move(player.up));
}

TEST_CASE("Player can_move() test true") {
    Player player = Player(15, 23);
    REQUIRE(player.can_move(player.left));
}

// GHOST TESTS

TEST_CASE("Ghost Constructor") {
    Ghost ghost = Ghost();
    REQUIRE(13 == ghost.pos_x);
}

TEST_CASE("Ghost can_move() test") {
    Ghost ghost = Ghost();
    REQUIRE(ghost.can_move(ghost.down));
}

// BOARD TESTS

TEST_CASE("Board Constructor") {
    Board board = Board();
    REQUIRE(board.has_refreshed == true);
}

TEST_CASE("Board count_dots()") {
    Board board = Board();
    REQUIRE(board.count_dots() == 248);
}
*/
