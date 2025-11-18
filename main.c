#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE		6

int rolldie(void){
		return rand() %MAX_DIE + 1;
}
	
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int cnt;
	int pos;
	int coinResult;
	srand( (unsigned) (time(NULL)) );
	
	//opening
	printf("=================================================================\n");
    printf("*****************************************************************\n");
    printf("*                               BINGO GAME                      *\n");
    printf("*****************************************************************\n");
    printf("=================================================================\n\n\n");

	//step 1. initializaion (player name setting, variables)
	board_initBoard();
	
	//step 2. turn play (do-while)
	cnt = 0;
	pos = 0;
	coinResult = 0;
	do {
		int die_result;

		
	// 2-1. status printing
	board_printBoardStatus();
	
	// 2-2. roll die
	die_result = rolldie();
	// 2-3. move (result)
	pos += die_result;
	
	printf("pos : %i (die:%i)\n", pos, die_result);
	
	coinResult += board_getBoardCoin (pos);
	
	printf("coin : %i \n", coinResult);
	// 2-4. change turn, shark move
	cnt++;
	} while(cnt <5);
	// step 3. game end (winner printing)


		
	//ending
    printf("\n\n\n\n\n\n\n");
    printf("=================================================================\n");
    printf("*****************************************************************\n");
    printf("*                        CONGRATULATION!!!!!                    *\n");
    printf("*   *#&$^#&$8^@($!@(* BINGO!!!!! #)!(*(#)*$$(#)*(!^@&$)*        *\n");
    printf("*                            YOU WIN!!!!!!                      *\n");
    printf("*****************************************************************\n");
    printf("=================================================================\n\n\n");
	
	return 0;
}
