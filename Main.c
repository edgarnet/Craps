/*
 * =====================================================================================
 *
 *       Filename:  Main.c
 *
 *    Description:  The driver file for 'Craps': the game.
 *
 *        Version:  1.0
 *        Created:  10/1/2016 12:15:50 PM
 *       Revision:  none
 *       Compiler:  msft c
 *
 *         Author:  Edgar Perez
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */

#include	"Craps.h"

int main(void) {
	/* srand() function to randomize dice */
	srand((unsigned int)time(NULL));

	/* local variables for user input, dice, balance, wager, roll count, win/loss condition, and loop boolean. */
	int option = 0;
	int dieOne = 0;
	int dieTwo = 0;
	double initial_balance = 0;
	double current_balance = 0;
	double current_wager = 0;
	int roll_count = 0;
	int win_lose = 0;
	char answer = 0;
	int complete = 0;
	char proxy = 0;

	/* do-while loop containing menu and respective switch statement. */
	do {
		complete = FALSE;
		printf("Craps: Play 'till you're broke!\n");
		printf("Press 1 for the rules.\n");
		printf("Press 2 to have some fun...\n");
		printf("Press 3 to get the hell out!\n");
		scanf("%d", &option);
		switch (option) {
			/* Case 1 prints game rules.*/
		case 1:
			print_game_rules();
			break;
			/* Case 2 runs the game.*/
		case 2:
			initial_balance = get_bank_balance();
			current_balance = initial_balance;
			while (complete != TRUE) {
				current_wager = get_wager_amount();
				current_wager = check_wager_amount(current_balance, current_wager);
				dieOne = roll_die();
				dieTwo = roll_die();
				roll_count++;
				win_lose = is_point_loss_or_neither((calculate_sum_dice(dieOne, dieTwo)), roll_count);
				current_balance = adjust_bank_balance(current_balance, current_wager, win_lose);
				chatter_messages(roll_count, win_lose, initial_balance, current_balance);
				if (current_balance > 0) {
					printf("Do you still wanna play? (y/n): ");
					scanf(" %c", &answer);
					if (answer == 'n')
						complete = TRUE;
					else if (answer == 'y')
						complete = FALSE;
					else {
						while (answer != 'n' && answer != 'y') {
							proxy = getchar();
							system("cls");
							printf("You kiss your mother with that mouth?\n");
							scanf(" %c", &answer);
							if (answer == 'n')
								complete = TRUE;
							else if (answer == 'y')
								complete = FALSE;
						}
					}
				}
				else if (current_balance == 0){
					printf("Sorry chum, but your empty balance won't do you any good here.\n\n");
					complete = TRUE;
				}
			}
			break;
			/* Case 3 exits the game. */
		case 3:
			printf("\nThank you for playing 'Craps'!\n");
			exit(0);
			break;
		default:
			system("cls");
			break;
		}
	} while ((option >= 1) || (option <= 3));
	return 0;
}
