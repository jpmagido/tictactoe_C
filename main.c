#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char symbol;
    char name[25];
} Player;

void display_player(Player player, int number);

bool game_is_on(char board[3][3]);

void display_board(char board[3][3]);

void update_board(char board[3][3], char position[], char symbol);

int letter_value(char letter);

int char_int_value(char char_int);

int main() {
    printf("Welcome to our TicTacToe for 2 players\n");

    Player player1;
    Player player2;

    printf("\nPlease enter player 1 name: \t");
    scanf("%s", &player1.name);

    printf("\nPlease enter player 2 name: \t");
    scanf("%s", &player2.name);

    player1.symbol = 'O';
    player2.symbol = 'X';

    char board[3][3] = {{" ", " ", " "},
                        {" ", " ", " "},
                        {" ", " ", " "}
    };

    printf("\n***********\n\n");

    display_player(player1, 1);
    display_player(player2, 2);

    printf("\n***********\n\n");

    char symbol_turn = 'O';
    char position[3];

    do {
        display_board(board);
        printf("%c must play his/her turn\n", symbol_turn);
        printf("> ");
        scanf("%s", &position);
        update_board(board, position, symbol_turn);

        if (symbol_turn == 'O') {
            symbol_turn = 'X';
        } else {
            symbol_turn = 'O';
        }

    } while (game_is_on(board));

    return 0;
}

bool game_is_on(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
            // horizontal victory
            printf("X victory with horizontal");
            return false;
        } else if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
            // vertical victory
            printf("X victory with vertical");
            return false;
        } else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
            printf("O victory with horizontal");
            // horizontal victory
            return false;
        } else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
            // vertical victory
            printf("O victory with vertical");
            return false;
        }

        // diagonal victory
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
            printf("X victory with diagonal");
            return false;
        } else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
            printf("X victory with diagonal");
            return false;
        } else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
            printf("O victory with diagonal");
            return false;
        } else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
            printf("O victory with diagonal");
            return false;
        }
    }

    return true;
}

void update_board(char board[3][3], char position[], char symbol) {
    int horizontal = letter_value(position[0]);
    int vertical = char_int_value(position[1]);

    board[horizontal][vertical] = symbol;
}

int letter_value(char letter) {
    // ex: A3
    char letters[] = {'A', 'B', 'C'};
    int letter_value;

    for (int i = 0; i < 3; ++i) {
        if (letter == letters[i]) {
            letter_value = i;
        }
    }

    return letter_value;
}

int char_int_value(char char_int) {
    // ex: A3
    char numbers[] = {'1', '2', '3'};
    int char_value;

    for (int i = 0; i < 3; ++i) {
        if (char_int == numbers[i]) {
            char_value = i;
        }
    }

    return char_value;
}

void display_board(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf(" %c  |", board[i][j]);
        }
        printf("\n");
    }
}

void display_player(Player player, int number) {
    printf("Player %d", number);
    printf(" is %s", player.name);
    printf(" with symbol: %c\n", player.symbol);
}