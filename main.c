#include <stdio.h>
#include <stdlib.h>

#define placeholder_symbol '*'

char board[3][3] = {
    {placeholder_symbol, placeholder_symbol, placeholder_symbol}, 
    {placeholder_symbol, placeholder_symbol, placeholder_symbol}, 
    {placeholder_symbol, placeholder_symbol, placeholder_symbol}
};

const char player_CPU = 'O';
const char player_symbol = 'X';

void draw_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
        }

        printf("\n");
    }

    printf("\n\n\n");
}

int check_winner() {
	int winner;

	for (int i = 0; i <= 2; i++)	
	{
		if (board[i][0] == board[i][1] &&
			board[i][1] == board[i][2] &&
			board[i][0] != placeholder_symbol)
		{

			if (board[i][0] == player_CPU) 
			{
				printf("CPU Wins!\n");
			} else if (board[i][0] == player_symbol) {
				printf("The human Wins!\n");
			}

			winner = board[i][0];
			return winner;
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		if (board[0][i] == board[1][i] &&
			board[1][i] == board[2][i] &&
			board[0][i] != placeholder_symbol)
		{
			if (board[0][i] == player_CPU) 
			{
				printf("CPU Wins!");
			} else if (board[i][0] == player_symbol) {
				printf("The human Wins!\n");
			}

			winner = board[i][0];
			return winner;
		}

	}

	for (int i = 0; i <= 2; i++)
	{
		if (board[0][i] == board[1][1] &&
			board[1][1] == board[2][2] &&
			board[0][i] != placeholder_symbol)
		{
			if (board[0][i] == player_CPU) 
			{
				printf("CPU Wins!\n");
			} else if (board[i][0] == player_symbol) {
				printf("The human Wins!\n");
			}

			winner = board[i][0];
			return winner;
		}
	}
}

void place_piece(int boardPosition, char user)
{

    if(boardPosition > 9){
        printf("!!!Invalid turn.!!!\n");
        return;
    }

	char currentSymbol;

	if (user == 'p')
	{
		currentSymbol = player_symbol;
	}
	else if (user == 'c') {
		currentSymbol = player_CPU;
	}

	switch (boardPosition)
	{
	case 1:
        if(board[0][0] == player_CPU || board[0][0] == player_symbol) {
           break;
        } else {
            board[0][0] = currentSymbol;
        }

		break;

	case 2:
        if(board[0][1] == player_CPU || board[0][1] == player_symbol) {
            break;
        } else {
            board[0][1] = currentSymbol;
        }

		break;

	case 3:
        if(board[0][2] == player_CPU || board[0][2] == player_symbol) {
            break;
        } else {
            board[0][2] = currentSymbol;
        }

		break;

	case 4:
        if(board[1][0] == player_CPU || board[1][0] == player_symbol) {
            break;
        } else {
		    board[1][0] = currentSymbol;
        }

		break;

	case 5:
        if(board[1][1] == player_CPU || board[1][1] == player_symbol) {
            break;
        } else {
            board[1][1] = currentSymbol;
        }

		break;

	case 6:
        if(board[1][2] == player_CPU || board[1][2] == player_symbol) {
            break;
        } else {
            board[1][2] = currentSymbol;
        }

		break;

	case 7:
        if(board[2][0] == player_CPU || board[2][0] == player_symbol) {
            break;
        } else {
            board[2][0] = currentSymbol;
        }

		break;

	case 8:
        if(board[2][1] == player_CPU || board[2][1] == player_symbol) {
            break;
        } else {
		    board[2][1] = currentSymbol;
        }

		break;

	case 9:
        if(board[2][2] == player_CPU || board[2][2] == player_symbol) {
            break;
        } else {
            board[2][2] = currentSymbol;
        }

		break;
	}

	check_winner();
}

int generate_rand() {
    int rand_ = rand() % 10;

    return rand_;
}

int main() {
    int is_running = 1;
    draw_board();
    printf("\n");

    while(is_running) {
        int input;
        scanf("%d", &input);
        place_piece(input, 'p');
        draw_board();

        int cpu_choice = generate_rand();
        place_piece(cpu_choice, 'c');

    }

    return 0;
}