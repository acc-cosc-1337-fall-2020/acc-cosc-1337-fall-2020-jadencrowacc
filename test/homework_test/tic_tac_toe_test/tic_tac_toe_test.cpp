#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <tic_tac_toe_3.h>
#include <tic_tac_toe_4.h>
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") {
    tic_tac_toe_3 game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    tic_tac_toe_3 game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}


TEST_CASE("Test game over if 9 slots are selected.") {
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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
    tic_tac_toe_3 game;
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

//4x4

TEST_CASE("Test game over if 16 slots are selected 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       16, 15, 14, 13};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }

    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {1, 2, 5, 6, 9, 10, 13};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {2, 3, 6, 7, 10, 11, 14};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {3, 2, 7, 6, 11, 10, 15};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by fourth column 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {4, 2, 8, 6, 12, 10, 16};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {1, 5, 2, 6, 3, 7, 4};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {5, 11, 6, 12, 7, 13, 8};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {9, 5, 10, 6, 11, 7, 12};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by fourth row 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {13, 5, 14, 6, 15, 7, 16};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {1, 4, 6, 9, 11, 7, 16};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left 4") {
    tic_tac_toe_4 game;
    game.start_game("X");
    int peg_order[] = {4, 1, 7, 9, 10, 2, 13};
    for (int pos : peg_order) {
        REQUIRE(!game.game_over());
        game.mark_board(pos);
    }
    REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

