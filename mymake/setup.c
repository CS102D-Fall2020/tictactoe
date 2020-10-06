#include <stdio.h>
#include <setup.h>

/* - - - 
 * - - - 
 * - - - 
 */ 
void init_board() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

void init_symbol() {

    printf("Choose your character!");
    do {
        scanf("%c", &user);
        //getchar();
    } while (user != 'X' && user != 'O');

    printf("You chose %c", user);

    if (user == 'X') {
        computer = 'O';
    } else if (user == 'O') {
        computer = 'X';
    }

    /*
    scanf("%c", &user);
    if (user != 'X' && user != 'O') {
        printf("Invalid input");
    }
    */
}
