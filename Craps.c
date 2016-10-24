/*
 * =====================================================================================
 *
 *       Filename:  Craps.c
 *
 *    Description:  This is the source file for 'Craps': the game.
 *
 *        Version:  1.0
 *        Created:  10/1/2016 12:18:29 PM
 *       Revision:  none
 *       Compiler:  msft c
 *
 *         Author:  Edgar Perez
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */

#include	"Craps.h"

 /*************************************************************
 * Function: print_game_rules()
 * Date Created: 9/29/2016
 * Date Last Modified: 10/5/2016
 * Description: This function prints a menu screen along with
 * 	       options to play, read rules, and exit.
 * Input parameters: None
 * Returns: Nothing.
 * Preconditions: A functional computer.
 * Postconditions: Menu screen is presented to player.
 *************************************************************/
void print_game_rules(void){
	printf("\nEach game has two phases: Come Out and Point. To start a round, the shooter makes one or more\n"
		"Come Out rolls. A Come Out roll of 2, 3 or 12 (called Craps, the shooter is said to 'crap out') ends the\n"
		"round, while a Come Out roll of 7 or 11 (a Natural) results in a win. The shooter continues to make Come Out\n"
		"rolls until he rolls 4, 5, 6, 8, 9, or 10, which number becomes the Point. If the shooter rolls the Point\n"
		"number the result is a win for bets on the Pass Line. If the shooter rolls a seven (a Seven-out),\n"
		"the pass line loses and the round ends.\n"
		"- Bone Bash Houston\n\n");
}

/*************************************************************
* Function: get_bank_balance()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Prompts the player for an initial bank balance
*              from which wagering will be added or subtracted.
* Input parameters: None.
* Returns: A floating-point value representing currency.
* Preconditions: A functional computer.
* Postconditions: The player's current balance is made
*                 available by a single function call.
*************************************************************/
double get_bank_balance(void){
	double balance = 0.0;
	printf("\nPlease enter your balance for tonight: ");
	scanf("%lf", &balance);
	while (balance <= 0) {
		printf("\nPlease enter your balance for tonight: ");
		scanf("%lf", &balance);
		system("cls");
	}
	return balance;
}

/*************************************************************
* Function: get_wager_amount()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Prompts the player for a wager on a
*              particular roll.
* Input parameters: None.
* Returns: A floating-point value representing currency.
* Preconditions: A functional computer.
* Postconditions: The player's current wager amount is made
*                 available by a single function call.
*************************************************************/
double get_wager_amount(void){
	double wager = 0.0;
	printf("How much will you wager?\n");
	scanf("%lf", &wager);
	while (wager <= 0) {
		printf("How much will you wager?\n");
		scanf("%lf", &wager);
		system("cls");
	}
	return wager;
}

/*************************************************************
* Function: check_wager_amount()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Checks to see if the wager is within the limits
*              of the player's available balance. If the wager
*              exceeds the player's allowable balance, then
*              nothing is returned; otherwise wager is returned.
* Input parameters: Floating-point values for wager and balance.
* Returns: An integer determining wager availability.
* Preconditions: Both wager and balance have been collected.
* Postconditions: Current wager is allowed or denied.
*************************************************************/
double check_wager_amount(double balance, double wager){
	while((balance - wager) < 0){
		system("cls");
		printf("C'mon, dont play yourself like that.\n");
		wager = get_wager_amount();
	}
	return wager;
}

/*************************************************************
* Function: roll_die()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Rolls one die. This function should randomly
*              generate a value between 1 and 6, inclusively.
* Input parameters: None
* Returns: Returns an integer value of the die.
* Preconditions: srand() must be called in main.
* Postconditions: A die is rolled.
*************************************************************/
int roll_die(void){
	return (rand() % 6 + 1);
}

/*************************************************************
* Function: calculate_sum_dice()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Sums together the values of the two dice given.
* Input parameters: Integer values for first and second dice.
* Returns: Returns the sum as an integer value.
* Preconditions: Both dice must be rolled.
* Postconditions: The fate of the player is determined.
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value){
	print_dice(die1_value, die2_value);
	printf("\nThe sum of your roll was: %d\n", (die1_value + die2_value));
	return (die1_value + die2_value);
}

/*************************************************************
* Function: is_win_loss_or_point()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Determines the result of the first dice roll.
*              If the sum is 7 or 11 on the roll, the player
*              wins and 1 is returned. If the sum is 2, 3, or
*              12 on the first throw (called "craps"), the
*              player loses. If the sum is 4, 5, 6, 8, 9, or 10
*              on the first throw, then the sum becomes the
*              player's "point" and -1 is returned.
* Input parameters: Integer value for sum of dice.
* Returns: 1 for win, 0 for loss, -1 for point.
* Preconditions: The dice must be rolled.
* Postconditions: THe player wins, loses, or continues.
*************************************************************/
int is_win_loss_or_point(int sum_dice){
	if(sum_dice == 7 || sum_dice == 11)
		return WIN;
	else if(sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
		return LOSS;
	else
		return POINT;
}

/*************************************************************
* Function: is_point_loss_or_neither()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: Determines the result of any successive roll
*              after the first roll. If the sum of the roll
*              is the point_value, then 1 is returned. If the
*              sum of the roll is a 7, then 0 is returned.
*              Otherwise, -1 is returned.
* Input parameters: Integer value for sum of next dice and
*                   result of previous roll.
* Returns: 1 for point, 2 for 7, 0 for neither.
* Preconditions: Sum of current dice roll and result of
*                previous roll must be calculated.
* Postconditions: The player's bet is transacted.
*************************************************************/
int is_point_loss_or_neither(int sum_dice, int count){
	int die1 = 0;
	int die2 = 0;
	if(is_win_loss_or_point(sum_dice) == POINT){
		printf("\nWe've got ourselves a point!\n");
		die1 = roll_die();
		die2 = roll_die();
		count++;
		if(sum_dice == calculate_sum_dice(die1, die2))
			return WIN;
		else
			return LOSS;
	}
	else
		return is_win_loss_or_point(sum_dice);
}

/*************************************************************
* Function: adjust_bank_balance()
* Date Created: 9/29/2016
* Date Last Modified: 10/5/2016
* Description: If add_or_subtract is 1, then the wager amount
*              is added to the bank_balance. If add_or_subtract
*              is 0, then the wager amount is subtracted from
*              the bank_balance. Otherwise, the bank_balance
*              remains the same.
* Input parameters: Floating-point values for bank_balance and
*                   wager_amaount, and an integer value for
*                   the type of transaction.
* Returns: The latest bank_balance result is returned.
* Preconditions: The player's balance, wager, and transaction
*                type must be determined.
* Postconditions: The player's balance is up-to-date.
*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract){
	if(add_or_subtract == WIN)
		return (bank_balance + (wager_amount * 2));
	else if(add_or_subtract == LOSS)
		return (bank_balance - wager_amount);
	else
		return bank_balance;
}

/*************************************************************
* Function: chatter_messages()
* Date Created: 10/1/2015
* Date Last Modified: 10/5/2016
* Description: Prints an appropriate message dependent on the
			   number of rolls taken so far by the player,
			   the current balance, and whether or not the
			   player just won his roll.
* Input parameters: Integer values for number of rolls and
					win/loss condition, and floating point
					values for balance and wager.
* Returns: Nothing.
* Preconditions: Win/loss condition must be determined.
* Postconditions: Player gets served.
*************************************************************/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance){
	printf("Number of Rolls: %d, Initial Balance: %.2lf, Current Balance: %.2lf\n\n",
			number_rolls, initial_bank_balance, current_bank_balance);
	if(win_loss_neither == WIN){
		switch(rand() % 5 + 1){
			case 1:
				printf("You might just take the vault with that kinda luck!\n\n");
				break;
			case 2:
				printf("Now, now, we gotta start sharing that bread with the rest of the table.\n\n");
				break;
			case 3:
				printf("You ever heard of Icarus? 'Cause I think you might be flyin' a little too high.\n\n");
				break;
			case 4:
				printf("You're gonna drain the reservation's budget with that sorta skill!\n\n");
				break;
			case 5:
				printf("I'll have to start bringin' the manager over if you keep winnin' like this.\n\n");
				break;
		}
	}
	else if(win_loss_neither == LOSS){
		switch(rand() % 5 + 1){
			case 1:
				printf("Hey buddy, sooner than later we're gonna have to let someone else be the shooter.\n\n");
				break;
			case 2:
				printf("I'd start keepin' an eye on my balance if I were you.\n\n");
				break;
			case 3:
				printf("Maybe you should grab a drink and come back refreshed.\n\n");
				break;
			case 4:
				printf("I hear your spouse isn't too fond of your gambling addiction.\n\n");
				break;
			case 5:
				printf("Why don't you play this on your iPhone and come back when you know a thing or two!\n\n");
				break;
		}
	}
	else
		printf("Hey pal I don't have all night!\n\n");
}

/*************************************************************
* Function: print_dice()
* Date Created: 10/1/2016
* Date Last Modified: 10/5/2016
* Description: Prints the dice on the screen.
* Input parameters: Integer values for first and second dice.
* Returns: Nothing.
* Preconditions: Both dice must be rolled.
* Postconditions: The player sees what has been rolled.
*************************************************************/
void print_dice(int die1_value, int die2_value){
	switch(die1_value){
		case 1: 
						printf("\n   _______\n");
						printf("  /\\ o  o \\\n");
						printf(" /o \\ o  o \\\n");
						printf("<    >------>\n");
						printf(" \\ o/  o   /\n");
						printf("  \\/______/\n");
						break;
		case 2:
						printf("\n   _______\n");
						printf("  /\\ o  o \\\n");
                        printf(" /o \\ o  o \\\n");
                        printf("<  o >------>\n");
                        printf(" \\ o/ o  o /\n");
                        printf("  \\/______/\n");
                        break;
		case 3:
						printf("\n   _______\n");
                        printf("  /\\ o  o \\\n");
                        printf(" /  \\ o  o \\\n");
                        printf("<  o >------>\n");
                        printf(" \\  /o o o /\n");
                        printf("  \\/______/\n");
                        break;
		case 4:
						printf("\n   _______\n");
                        printf("  /\\ o  o \\\n");
                        printf(" /o \\ o  o \\\n");
                        printf("<    >------>\n");
                        printf(" \\ o/ o  o /\n");
                        printf("  \\/_o__o_/\n");
                        break;
		case 5:
						printf("\n   _______\n");
                        printf("  /\\ o  o \\\n");
                        printf(" /  \\ o  o \\\n");
                        printf("<  o >------>\n");
                        printf(" \\  / o  o /\n");
                        printf("  \\/_o_o_o/\n");
                        break;
		case 6:
						printf("\n   _______\n");
                        printf("  /\\ o  o \\\n");
                        printf(" /o \\ o  o \\\n");
                        printf("<    >------>\n");
                        printf(" \\ o/ o o o/\n");
                        printf("  \\/_o_o_o/\n");
                        break;
	}

	switch(die2_value){
		case 1:
						printf("\n    _______\n");
						printf("  /  o  o /|\n");
						printf(" /_______/o|\n");
						printf("|       |oo|\n");
						printf("|   o   |o/\n");
						printf("|_______|/\n\n");
						break;
		case 2:
						printf("\n    _______\n");
						printf("  /  o  o /|\n");
						printf(" /_______/o|\n");
						printf("|       |oo|\n");
						printf("|  o o  |o/\n");
						printf("|_______|/\n\n");
						break;
		case 3:
						printf("\n    _______\n");
						printf("  /  o  o /|\n");
						printf(" /_______/o|\n");
						printf("|       |  |\n");
						printf("| o o o |o/\n");
						printf("|_______|/\n\n");
						break;
		case 4:
						printf("\n    _______\n");
						printf("  /  o  o /|\n");
						printf(" /_______/o|\n");
						printf("|  o  o |  |\n");
						printf("|  o  o |o/\n");
						printf("|_______|/\n\n");
						break;
		case 5:
						printf("\n    _______\n");
						printf("  /  o  o /|\n");
						printf(" /_______/o|\n");
						printf("|  o o  |  |\n");
						printf("|   o   |o/\n");
						printf("|__o_o__|/\n\n");
						break;
		case 6:
						printf("\n    _______\n");
						printf("  /  o  o /|\n");
						printf(" /_______/o|\n");
						printf("| o o o |oo|\n");
						printf("| o o o |o/\n");
						printf("|_______|/\n\n");
						break;
	}
}
