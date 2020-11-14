#include "tic_tac_toe_4.h"
#include "tic_tac_toe.h"


/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/




/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool tic_tac_toe_4::check_diagonal_win() {
    return (board[0] != " " && board[0] == board[5] && board[0] == board[10] && board[0] == board[15]) ||
           (board[3] != " " && board[3] == board[6] && board[3] == board[9] && board[3] == board[12]);
}

bool tic_tac_toe_4::check_column_win() {
    for (int i = 0; i < 4; i += 1)
        if (board[0 + i] != " " &&
            board[0 + i] == board[4 + i] &&
            board[0 + i] == board[8 + i] &&
            board[0 + i] == board[12 + i])
            return true;
    return false;
}

bool tic_tac_toe_4::check_row_win() {
    for (int i = 0; i <= 12; i += 4)
        if (board[0 + i] != " " &&
            board[0 + i] == board[1 + i] &&
            board[1 + i] == board[2 + i] &&
            board[2 + i] == board[3 + i])
            return true;
    return false;
}