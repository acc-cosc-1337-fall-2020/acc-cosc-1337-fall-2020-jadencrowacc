#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <tic_tac_toe.h>
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") {
    tic_tac_toe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    tic_tac_toe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}


TEST_CASE("Test game over if 9 slots are selected.") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(8);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(6);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(!game.game_over());
    game.mark_board(7);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(7);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(8);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(6);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(6);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(7);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(8);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(7);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}