/*
 * =====================================================================================
 *
 *       Filename:  Craps.h
 *
 *    Description:  This is the header file for the program, which includes function 
 *                  declarations for: void print_game_rules()
 *                                   double get_bank_balance()
 *                                   double get_wager_amount()
 *                                   double check_wager_amount()
 *                                   int roll_die()
 *                                   int calculate_sum_dice()
 *                                   int is_win_loss_or_point()
 *                                   int is_point_loss_or_neither()
 *                                   double adjust_bank_balance()
 *                                   void chatter_messages()
 *                                   print_dice()
 *
 *        Version:  1.0
 *        Created:  9/29/2016 12:14:10 PM
 *       Revision:  none
 *       Compiler:  msft c
 *
 *         Author:  Edgar Perez 
 *   Organization:  Washington State University
 *
 * =====================================================================================
 */

#ifndef CRAPS_H
#define CRAPS_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<math.h>

#define		TRUE	1
#define		FALSE	0
#define		WIN	1
#define		LOSS	0
#define		POINT	-1

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
void print_game_rules(void);

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
double get_bank_balance (void);

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
double get_wager_amount (void);

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
double check_wager_amount (double wager, double balance);

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
int roll_die (void);

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
int calculate_sum_dice (int die1_value, int die2_value);

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
int is_win_loss_or_point (int sum_dice);

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
int is_point_loss_or_neither (int sum_dice, int count);

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
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract);

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
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

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
void print_dice(int die1_value, int die2_value);

#endif // !CRAPS_H
