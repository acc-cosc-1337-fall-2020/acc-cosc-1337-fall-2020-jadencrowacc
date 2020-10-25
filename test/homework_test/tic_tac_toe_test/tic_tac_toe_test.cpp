#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <tic_tac_toe.h>
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("CAT Tie") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    game.mark_board(5);
    game.mark_board(8);
    game.mark_board(4);
    game.mark_board(6);
    game.mark_board(9);
    game.mark_board(7);
    REQUIRE(game.game_over());
}

