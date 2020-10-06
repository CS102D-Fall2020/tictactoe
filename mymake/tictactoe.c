#include <stdio.h>
#include <setup.h>

void draw_board();
void player_move();
void computer_move();

int symbol_won(char c);

int main() {

    init_board();
    draw_board();
    init_symbol();
    
    /*
     * first attempt...
    int i=0;
    while (i!=9) {
        player_move();
        draw_board();
        computer_move();
        draw_board();
        i++;
    }
    */

    for (int i=0; i<9; i++) {
        if (i % 2 == 0) {
            if (user == 'X') {
                player_move();
            } else {
                computer_move();
            }
        }
        else {
            if (user == 'X') {
                computer_move();
            } else {
                player_move();
            }
        }
        draw_board();
        if (symbol_won(user)) {
            printf("YOU WON!!!");
            return 0;
        } else if (symbol_won(computer)) {
            printf("You lose. :(");
            return 0;
        }  
    }

    return 0;
}


/*  X O X
 *  O X O
 *  X O X
 */
void draw_board() {
    for (int i=0; i<3; i++) {
        printf("%c %c %c\n", board[i][0], board[i][1], board[i][2]);
    }
}

void player_move() {
    int spot;
//    printf("Choose your spot: ");

    int row, col;
    do {
        printf("Choose a valid spot: ");
        scanf("%d", &spot);

        row = (spot-1)/3;
        col = (spot-1)%3;

    } while (board[row][col] != '-');
    board[row][col] = user;
}

void computer_move() {
    //board[0][0] = computer;
    //

    printf("Computer chooses...\n");
    int i=0;
    int j=0;
    int counter=1;
    for ( ; board[i][j] == 'X' || board[i][j] == 'O'; counter++) {
        i = (counter-1)/3;
        j = (counter-1)%3;
    }
    board[i][j] = computer;

    /*
    if (board[i][j] == 'X' || board[i][j] == 'O') {
        board[
    }

    while (board[i][j] == '-') {
        board[i][j] = computer;
    }*/
}

int symbol_won(char c){ 
    for (int i=0; i<3; i++) {
        if (board[i][0] == c &&
            board[i][1] == c &&
            board[i][2] == c) {
            return 1;
        }
    }

    for (int j=0; j<3; j++) {
        if (board[0][j] == c &&
            board[1][j] == c &&
            board[2][j] == c) {
            return 1;
        }
    }

    if (board[0][0] == c &&
        board[1][1] == c &&
        board[2][2] == c) {
        return 1;
    }

    if (board[0][2] == c &&
        board[1][1] == c &&
        board[2][0] == c) {
        return 1;
    }

    return 0;

}
