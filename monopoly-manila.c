/****************************************************************************
This is to certify that this project is my own work, based on my personal 
efforts in studying and applying the concepts learned.  I have constructed  
the functions and their respective algorithms and corresponding code by  
myself.  The program was run, tested, and debugged by my own efforts.  I  
further certify that I have not copied in part or whole or otherwise  
plagiarized the work of other students and/or persons. 
<Patricia Naui>
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/******************************************************* 
Function: void cleaner
Description: Clears the screen by printing newline characters.
Precondition(s): None.
Parameters: None.
Return Value: None.
*******************************************************/
void cleaner() {
    printf("\n\n\n\n\n\n\n\n\n\n");  // 10 newlines for spacing
    printf("----------------------------------------------------------\n");
}

/******************************************************* 
Function: void display_intro
Description: Displays the game's intro message including the title, game description, how to play, and how to win.
Precondition(s): None.
Parameters: None.
Return Value: None.
*******************************************************/
void display_intro(){
    // Display intro message
      printf("Welcome to:\n\n----------------------------------------------------------\n\n /$$      /$$                     /$$ /$$           /$$\n| $$$    /$$$                    |__/| $$          | $$\n| $$$$  /$$$$  /$$$$$$  /$$$$$$$  /$$| $$  /$$$$$$ | $$\n| $$ $$/$$ $$ |____  $$| $$__  $$| $$| $$ |____  $$| $$\n| $$  $$$| $$  /$$$$$$$| $$  \ $$| $$| $$  /$$$$$$$|__/\n| $$\  $ | $$ /$$__  $$| $$  | $$| $$| $$ /$$__  $$    \n| $$ \/  | $$|  $$$$$$$| $$  | $$| $$| $$|  $$$$$$$ /$$\n|__/     |__/ \_______/|__/  |__/|__/|__/ \_______/|__/\n                                                       \n----------------------------------------------------------\n\nGet ready to take over the bustling streets of Manila!\nIn this game, you and three other players will will roll the dice, buy properties, and collect rent to become the ultimate tycoon!\n\nHit 'Enter' to learn how to play the game.\n");
      getchar(); // Waits for user to press 'Enter'

      // Display how to play the game
        printf("\n----------------------------------------------------------\nHow to play:\n* Each player starts with ₱50,000 and takes turns rolling two dice to move across the board.\n* If you land on an unsold property, you can buy it if you have enough cash.\n* If you land on a sold property, you must pay rent to the owner.\n* Special blocks have unique effects such as paying taxes, getting bonuses, or even going to jail!\n* Railroads transport you to the next available station when landed on.\n----------------------------------------------------------\n");

      // Display how to win the game
        printf("\n----------------------------------------------------------\nHow to win:\nAt the end of the game, the player who owns the most properties is declared the winner!\n----------------------------------------------------------\n");

      // Start the game
        printf("\nAre you ready? Hit 'Enter' to begin!\n");
        getchar(); // Waits for player to hit 'Enter'
        cleaner(); // Cleans the screen
}

/******************************************************* 
Function: int roll_dice
Description: Rolls two six-sided dice and returns the sum of the rolls.
Precondition(s): The random number generator has been seeded.
Parameters: None.
Return Value: A positive integer between 2 and 12.
*******************************************************/
int roll_dice(){
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    return die1 + die2; // Return the sum of 2 dice rolls
}

/******************************************************* 
Function: void sort_players
Description: Sorts the players from highest to lowest roll.
Precondition(s): (p1, p2, p3, p4) - Valid pointers to character pointers that are pointing to a player's name string. (roll_p1, roll_p2, roll_p3, roll_p4) - Valid pointers to integers that are pointing to a player's roll.
Parameters: (p1, p2, p3, p4) - Pointers representing the players' names. (roll_p1, roll_p2, roll_p3, roll_p4) - Pointers to the players' dice rolls.
Return Value: None.
*******************************************************/
void sort_players(char** p1, char** p2, char** p3, char** p4, int *roll_p1, int *roll_p2, int *roll_p3, int *roll_p4){
  int temp_roll;
  char* temp_name;

  // Bubble sort to order players based on their rolls
  if (*roll_p1 < *roll_p2){
    // Swap rolls
    temp_roll = *roll_p1;
    *roll_p1 = *roll_p2;
    *roll_p2 = temp_roll;

    // Swap names
    temp_name = *p1;
    *p1 = *p2;
    *p2 = temp_name;
  }
  if (*roll_p1 < *roll_p3){
    temp_roll = *roll_p1;
    *roll_p1 = *roll_p3;
    *roll_p3 = temp_roll;

    temp_name = *p1;
    *p1 = *p3;
    *p3 = temp_name;
  }
  if (*roll_p1 < *roll_p4){
      temp_roll = *roll_p1;
      *roll_p1 = *roll_p4;
      *roll_p4 = temp_roll;

      temp_name = *p1;
      *p1 = *p4;
      *p4 = temp_name;
  }
  if (*roll_p2 < *roll_p3){
      temp_roll = *roll_p2;
      *roll_p2 = *roll_p3;
      *roll_p3 = temp_roll;

      temp_name = *p2;
      *p2 = *p3;
      *p3 = temp_name;
  }
  if (*roll_p2 < *roll_p4){
      temp_roll = *roll_p2;
      *roll_p2 = *roll_p4;
      *roll_p4 = temp_roll;

      temp_name = *p2;
      *p2 = *p4;
      *p4 = temp_name;
  }
  if (*roll_p3 < *roll_p4){
      temp_roll = *roll_p3;
      *roll_p3 = *roll_p4;
      *roll_p4 = temp_roll;

      temp_name = *p3;
      *p3 = *p4;
      *p4 = temp_name;
  }
}

/******************************************************* 
Function: void display_player_info
Description: Displays the player's information, including their name, cash, and the number of properties they own.
Precondition(s): (player_name) - Character pointer representing the player's name. (cash) - Integer representing the player's cash. (player_num) - Valid player number. 
Parameters: (player_name) - Character pointer representing the player's name. (cash) - Integer representing the player's cash. (player_num) - Represents the player number. (owner_2 - owner_40) - Integers representing the owner of each property.
Return Value: None. Prints the player's information.
*******************************************************/
void display_player_info(char* player_name, int cash, int player_num, int owner_2, int owner_4, int owner_7, int owner_9, int owner_10, int owner_12, int owner_14, int owner_15, int owner_17, int owner_19, int owner_20, int owner_22, int owner_24, int owner_25, int owner_27, int owner_28, int owner_30, int owner_32, int owner_33, int owner_35, int owner_38, int owner_40) {

    // Count properties owned by a player
    int props = 0;
    if (owner_2 == player_num) props++;
    if (owner_4 == player_num) props++;
    if (owner_7 == player_num) props++;
    if (owner_9 == player_num) props++;
    if (owner_10 == player_num) props++;
    if (owner_12 == player_num) props++;
    if (owner_14 == player_num) props++;
    if (owner_15 == player_num) props++;
    if (owner_17 == player_num) props++;
    if (owner_19 == player_num) props++;
    if (owner_20 == player_num) props++;
    if (owner_22 == player_num) props++;
    if (owner_24 == player_num) props++;
    if (owner_25 == player_num) props++;
    if (owner_27 == player_num) props++;
    if (owner_28 == player_num) props++;
    if (owner_30 == player_num) props++;
    if (owner_32 == player_num) props++;
    if (owner_33 == player_num) props++;
    if (owner_35 == player_num) props++;
    if (owner_38 == player_num) props++;
    if (owner_40 == player_num) props++;

    // Display the player's information
    printf("\n----------------------------------------------------------");
    printf("\n* %s's Turn", player_name);
    printf("\n* Cash: ₱%d | Properties: %d", cash, props);
    printf("\n----------------------------------------------------------\n");
}

/******************************************************* 
Function: char* get_property_name
Description: Returns the name of a property or a special block based on its block number.
Precondition(s): (position) - A valid number from 1-40. 
Parameters: (position) - An integer representing the block number.
Return Value: A character pointer representing the name of the property or special block.
*******************************************************/
char* get_property_name(int position){
  switch (position){
    case 1: return "Go";
    case 2: return "Muralla Street";
    case 3: return "Internal Revenue Allotment";
    case 4: return "Muelle de la Industria Street";
    case 5: return "Income Tax";
    case 6: return "LRT 1";
    case 7: return "Ongpin Street";
    case 8: return "Chance";
    case 9: return "Quezon Boulevard";
    case 10: return "Sampaloc Street";
    case 11: return "Manila City Jail";
    case 12: return "Road 10";
    case 13: return "Meralco";
    case 14: return "Abad Santos Avenue";
    case 15: return "Juan Luna Street";
    case 16: return "PNR";
    case 17: return "España Boulevard";
    case 18: return "Internal Revenue Allotment";
    case 19: return "P. Noval Street";
    case 20: return "M. dela Fuente Street";
    case 21: return "Free Parking";
    case 22: return "Pedro Gil Street";
    case 23: return "Chance";
    case 24: return "R. Magsaysay Boulevard";
    case 25: return "Beata Street";
    case 26: return "LRT 2";
    case 27: return "Quirino Avenue";
    case 28: return "Paz Mendoza Guazon Street (Otis)";
    case 29: return "Maynilad";
    case 30: return "San Andres Street";
    case 31: return "Manila Police District";
    case 32: return "Taft Avenue";
    case 33: return "Pablo Ocampo Street";
    case 34: return "Internal Revenue Allotment";
    case 35: return "Adriatico Street";
    case 36: return "MRT 3";
    case 37: return "Chance";
    case 38: return "Roxas Boulevard";
    case 39: return "Real Property Tax";
    case 40: return "United Nations Avenue";
  }
}

/******************************************************* 
Function: void display_position
Description: Displays a message indicating which position a player has landed on.
Precondition(s): (position) - Valid block number from 1 to 40.
Parameters: (player_name) - Character pointer to the player's name. (position) - Integer representing the block number.
Return Value: None. Prints a message indicating the player's position.
*******************************************************/
void display_position(char* player_name, int position){
  printf("\n%s landed on %s.\n", player_name, get_property_name(position));
}

/******************************************************* 
Function: void turn_system
Description: Sets turn indicators for 4 players based on the provided turn order, assigning 1 to the 1st player's turn and 0 to the others.
Precondition(s): (first, second, third, fourth, p1, p2, p3, p4) - Valid character pointers that are pointing to a player's name string. (turn_p1, turn_p2, turn_p3, turn_p4) - Valid pointers to integers.
Parameters: (first, second, third, fourth) - Character pointers to the players' name in the turn order. (turn_p1, turn_p2, turn_p3, turn_p4) - Pointers to the players' turn indicator. (p1, p2, p3, p4) - Character pointers to players' names.
Return Value: None.
*******************************************************/
void turn_system(char* first, char* second, char* third, char* fourth, int* turn_p1, int* turn_p2, int* turn_p3, int* turn_p4, char* p1, char* p2, char* p3, char* p4){

  // Set the first player's turn to 1, and the rest to 0
  if (first == p1){
    *turn_p1 = 1, *turn_p2 = 0, *turn_p3 = 0, *turn_p4 = 0;
  } else if (first == p2){
    *turn_p1 = 0, *turn_p2 = 1, *turn_p3 = 0, *turn_p4 = 0;
  } else if (first == p3){
    *turn_p1 = 0, *turn_p2 = 0, *turn_p3 = 1, *turn_p4 = 0;
  } else if (first == p4){
    *turn_p1 = 0, *turn_p2 = 0, *turn_p3 = 0, *turn_p4 = 1;
  }
}

/******************************************************* 
Function: int roll_dice_move
Description: Prompts a player to roll dice, updates their position based on the roll, and returns the rolled value.
Precondition(s): (player_name) - Valid character pointer representing the player's name. (pos) - Valid pointer to an integer representing the player's current position on the board. (cash) - Valid pointer to an integer representing the player's cash amount.
Parameters: (player_name) - Character pointer to the player's name. (pos) - Pointer to the player's current position. (cash) - Pointer to the player's cash amount.
Return Value: An integer representing the sum of the dice roll.
*******************************************************/
int roll_dice_move(char* player_name, int *pos, int *cash){
  printf("\n%s, hit 'Enter' to roll the dice...", player_name); // Prompts the player to hit 'Enter' to roll the dice
  
  // Clear input buffer first
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
  
  // Wait for proper Enter press
  getchar();
  
  int roll = roll_dice();
  printf("\n* %s rolled %d!", player_name, roll);

  // Update player's position according to dice roll
  *pos += roll;
  if (*pos > 40){
    *pos -= 40; // Loops back to GO
    *cash += 2500; // Bonus for passing GO
    printf("\n* Passed GO! Collected ₱2,500");
  }

  // Display where the player landed
  display_position(player_name, *pos);
}

/******************************************************* 
Function: void buy_property
Description: Allows a player to purchase a property if it is unowned and they have sufficient funds, updating the player's cash and property ownership
Precondition(s): (cash) - Valid pointer to an integer representing the player's cash. (player) is a valid player number. (property_owner) - Valid pointer to an integer representing the property's owner. (price) - Integer representing the property's price.
(property_name) - Valid character pointer representing the property's name.
Parameters: (cash) - Pointer to the player's cash. (player) - The player's number. (property_owner) - Pointer to the property's owner. (price) - The property's price. (property_name) - The property's name.
Return Value: None. (cash) and (property_owner) may be modified.
*******************************************************/
void buy_property(int *cash, int player, int *property_owner, int price, char *property_name){
  int choice;
    if (*property_owner == 0) {
        printf("\n* This property costs ₱%d", price);
        printf("\n* Your current balance: ₱%d", *cash);
        printf("\nWould you like to buy it? [1 = Yes | 0 = No]: ");

        scanf("%d", &choice);

        if (choice == 1) {
            if (*cash >= price) {
                *cash -= price;
                *property_owner = player; // Assign property to the player
                printf("\n* You purchased %s! Remaining balance: ₱%d\n", property_name, *cash);
            } else {
                printf("\n* You don't have enough money to buy %s\n", property_name);
            }
        } else {
            printf("\nYou chose not to buy %s\n", property_name);
        }
    }
}

/******************************************************* 
Function: bool handle_jail
Description: Handles the jail mechanics for a player. The player will attempt to roll a double to get out of jail. If they fail, they will be sent to jail.
Precondition(s): 'player' is a valid number (1, 2, 3, or 4)
Parameters: (player) - The player number who is in jail. (*p1, *p2, *p3, *p4) - Pointers to the players' name. 
Return Value: (true) - If the player rolls a double. (false) - If the player fails to roll a double and pays the fine.
*******************************************************/
bool handle_jail(int player, char *p1, char *p2, char *p3, char *p4) {
    char *current_player;

    if (player == 1) current_player = p1;
    else if (player == 2) current_player = p2;
    else if (player == 3) current_player = p3;
    else current_player = p4;

    printf("\n----------------------------------------------------------");
    printf("\n* %s is in jail!", current_player);
    printf("\n* Roll doubles in three attempts to escape without paying a fine.");
    printf("\n----------------------------------------------------------\n");

    for (int attempt = 1; attempt <= 3; attempt++) {
        printf("\nAttempt %d - Press Enter to roll...", attempt);

        // Clear input buffer first
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;

        printf("\nYou rolled: %d and %d", die1, die2);

        if (die1 == die2) {
            printf("\n----------------------------------------------------------");
            printf("\n* Success! You rolled doubles!");
            printf("\n* You're free to leave jail without paying a fine!");
            printf("\n----------------------------------------------------------\n");
            return true;
        }

        if (attempt < 3) {
            printf("\nNot a double. Try again.\n");
        }
    }

    printf("\n----------------------------------------------------------");
    printf("\n* No doubles rolled after three attempts.");
    printf("\n* You must pay the ₱10,000 fine to leave jail.");
    printf("\n----------------------------------------------------------\n");
    return false;
}

/******************************************************* 
Function: void check_block
Description: Determines the action to take when a player lands on a specific board position, including buying properties, paying rent, paying taxes, receiving bonuses, or going to jail, and modifies player cash and position.
Precondition(s): (position) - Valid position number 1 to 40. (pos, cash, owner) - Valid pointers to integers. (player) - Valid player number from 1 to 4. (player_name, p1, p2, p3, p4) - Valid character pointers to player names.
Parameters: (position) - The position the player landed on. (pos) - Pointer to the player's position. (cash) - Pointer to the player's cash. (player) - The current player's number. (owner) - Pointer to the property's owner. (player_name) - The current player's name. (p1, p2, p3, p4) - Player names.
Return Value: None. (pos, cash, owner) may be modified.
*******************************************************/

void check_block(int position, int *pos, int *cash, int player, int *owner, char *player_name, 
                char *p1, char *p2, char *p3, char *p4, int *cash_p1, int *cash_p2, int *cash_p3, int *cash_p4,
                int owner_2, int owner_4, int owner_7, int owner_9, int owner_10, int owner_12, 
                int owner_14, int owner_15, int owner_17, int owner_19, int owner_20, int owner_22, 
                int owner_24, int owner_25, int owner_27, int owner_28, int owner_30, int owner_32, 
                int owner_33, int owner_35, int owner_38, int owner_40){
    int price = 0;
    int rent = 0;
    int original_position = position;  // Store original position
    char *property_name = get_property_name(position);
    int *property_owner = owner;
    char *owner_name = "";
    int chance;
    int new_pos;
    bool is_purchasable;
    int auto_price;
    int tax;
    int total_property_value;

    switch(position) {
        case 1:
            printf("You landed on GO! Collect ₱2,500.\n");
            *cash += 2500;
            return; // Return after processing GO to continue the game loop
            break;
        case 2: case 10: case 19: case 22: case 25: case 27:
            price = (*property_owner == 0) ? 25000 : 0;
            rent = (*property_owner != 0) ? 5000 : 0;
            break;
        case 4: case 17: case 20: case 24:
            price = (*property_owner == 0) ? 15000 : 0;
            rent = (*property_owner != 0) ? 2500 : 0;
            break;
        case 7:
            price = (*property_owner <= 0) ? 10000 : 0;
            rent = (*property_owner > 0) ? 1250 : 0;
            break;
        case 9: case 15:
            price = (*property_owner <= 0) ? 7500 : 0;
            rent = (*property_owner > 0) ? 900 : 0;
            break;
        case 12:
            price = (*property_owner == 0) ? 12500 : 0;
            rent = (*property_owner != 0) ? 1500 : 0;
            break;
        case 21:  // Free Parking
            printf("\nYou landed on Free Parking! Nothing happens, enjoy your rest.\n");
            return;  // Return after processing Free Parking to continue the game loop
            break;
        case 14: case 28: case 33:
            price = (*property_owner == 0) ? 15000 : 0;
            rent = (*property_owner != 0) ? 2500 : 0;
            break;
        case 30: case 40:
            price = (*property_owner == 0) ? 17500 : 0;
            rent = (*property_owner != 0) ? 2125 : 0;
            break;
        case 32: case 38:
            price = (*property_owner == 0) ? 25000 : 0;
            rent = (*property_owner != 0) ? 5000 : 0;
            break;
        case 35:
            price = (*property_owner == 0) ? 12500 : 0;
            rent = (*property_owner != 0) ? 1500 : 0;
            break;
        case 8: case 23: case 37:  // Chance blocks
            if (original_position == position) {  // Only process Chance if directly landed on it
                chance = rand() % 3;
                printf("\nYou landed on Chance! Let's see what happens...\n");

                if (chance == 0){
                    *cash += 20000;
                    printf("Lucky you! You received ₱20,000! Your current balance is ₱%d\n", *cash);
                    // Return after processing the cash bonus to continue the game loop
                    return;
                } else if (chance == 1) {
                    printf("You get to buy the next available property automatically!\n");
                    // Move to next available property
                    new_pos = *pos + 1;

                    // Keep moving forward until finding a purchasable property
                    is_purchasable = false;
                    while (!is_purchasable) {
                        // Check if the current position is purchasable
                        // Purchasable properties are: 2,4,7,9,10,12,14,15,17,19,20,22,24,25,27,28,30,32,33,35,38,40
                        // Non-purchasable are: 1,3,5,6,8,11,13,16,21,23,26,29,31,34,36,37,39

                        if (new_pos == 2 || new_pos == 4 || new_pos == 7 || new_pos == 9 || new_pos == 10 || 
                            new_pos == 12 || new_pos == 14 || new_pos == 15 || new_pos == 17 || new_pos == 19 || 
                            new_pos == 20 || new_pos == 22 || new_pos == 24 || new_pos == 25 || new_pos == 27 || 
                            new_pos == 28 || new_pos == 30 || new_pos == 32 || new_pos == 33 || new_pos == 35 || 
                            new_pos == 38 || new_pos == 40){
                            is_purchasable = true;
                        } else {
                            // Move to next position
                            new_pos++;
                            if (new_pos > 40){
                                new_pos -= 40;
                                *cash += 2500;  // Passing GO
                                printf("You passed GO! Collect ₱2,500. Your current balance is ₱%d.\n", *cash);
                            }
                        }
                    }
                    *pos = new_pos;
                    display_position(player_name, *pos);

                    // Calculate the price of the property based on the position
                    auto_price = 0;
                    int *auto_owner = NULL;

                    // For Chance card's auto-purchase, directly update property owners
                    // Get the property price based on position
                    switch(new_pos) {
                        case 2: auto_price = 25000; break;
                        case 4: auto_price = 15000; break;
                        case 7: auto_price = 10000; break;
                        case 9: auto_price = 7500; break;
                        case 10: auto_price = 25000; break;
                        case 12: auto_price = 12500; break;
                        case 14: auto_price = 15000; break;
                        case 15: auto_price = 7500; break;
                        case 17: auto_price = 15000; break;
                        case 19: auto_price = 25000; break;
                        case 20: auto_price = 15000; break;
                        case 22: auto_price = 25000; break;
                        case 24: auto_price = 15000; break;
                        case 25: auto_price = 7500; break;
                        case 27: auto_price = 25000; break;
                        case 28: auto_price = 15000; break;
                        case 30: auto_price = 17500; break;
                        case 32: auto_price = 25000; break;
                        case 33: auto_price = 15000; break;
                        case 35: auto_price = 12500; break;
                        case 38: auto_price = 25000; break;
                        case 40: auto_price = 17500; break;
                    }

                    // Check if property is unowned and purchase it if player has enough money
                    if (*cash >= auto_price) {
                        // Auto-purchase the property
                        *cash -= auto_price;

                        // Return to main function with this position for ownership update
                        printf("\nYou automatically purchased %s for ₱%d! Remaining balance: ₱%d.\n", 
                              get_property_name(new_pos), auto_price, *cash);

                        // Set position to return to main for ownership update
                        *pos = new_pos;
                        return; // Return to main for ownership update
                    } else {
                        printf("\nYou don't have enough money to buy %s. It costs ₱%d but you only have ₱%d.\n", 
                              get_property_name(new_pos), auto_price, *cash);
                    }

                    return; // Return after processing the special position to continue the game loop
                } else {
                    *cash -= 10000;
                    printf("Bad luck! You lost ₱10,000. Your current balance is ₱%d.\n", *cash);
                    return; // Return after processing the cash penalty to continue the game loop
                }
            }
            break;

        case 5:  // Income Tax
            printf("\nTime to pay your Income Tax! You are charged ₱7,500.\n");
            *cash -= 7500;
            return;  // Return after processing Income Tax to continue the game loop
            break;
        case 13: // Meralco
            printf("\nYour electric bill from Meralco has arrived! You are charged ₱2,500.\n");
            *cash -= 2500;
            return;  // Return after processing Meralco to continue the game loop
            break;
        case 29: // Maynilad
            printf("\nTime to pay your water bill to Maynilad! You are charged ₱1,000.\n");
            *cash -= 1000;
            return; // Return after processing Maynilad to continue the game loop
            break;
        case 3: case 18: case 34: // Internal Revenue Allotment
            *cash += 5000;
            printf("\nYou received ₱5,000 from Internal Revenue Allotment! Your current balance is ₱%d.\n", *cash);
            return; // Continue the game loop
            break;
        case 6:  // LRT 1
            if (original_position == 6) {  // Only move if directly landed on LRT 1
                printf("\nYou landed on LRT 1! Moving to next station (PNR)...\n");
                *pos = 16;  // Move to PNR
                display_position(player_name, *pos);
                // Process the new station position
                return; // Return after processing to continue the game loop
            } 
            break;
        case 16:  // PNR
            if (original_position == 16) {  // Only move if directly landed on PNR
                printf("\nYou landed on PNR! Moving to next station (LRT 2)...\n");
                *pos = 26;  // Move to LRT 2
                display_position(player_name, *pos);
                // Process the new station position
                return;
            }
            break;
        case 26:  // LRT 2
            if (original_position == 26) {  // Only move if directly landed on LRT 2
                printf("\nYou landed on LRT 2! Moving to next station (MRT 3)...\n");
                *pos = 36;  // Move to MRT 3
                display_position(player_name, *pos);
                // Process the new station position
                return;
            }
            break;
        case 36:  // MRT 3
            if (original_position == 36) {  // Only move if directly landed on MRT 3
                printf("\nYou landed on MRT 3! Moving to LRT 1...\n");
                *pos = 6;  // Move to LRT 1
                *cash += 2500;  // Add GO bonus since we pass GO
                printf("You passed GO! Collect ₱2,500. Your current balance is ₱%d\n", *cash);
                display_position(player_name, *pos);
                // Process the new station position
                return;
            }
            break;
        case 39:  // Real Property Tax
            {
                // Calculate 5% of total property value
                total_property_value = 0;

                // Check all properties owned by the current player
                // Calculate total property value by checking each property
                if (owner_2 == player) total_property_value += 25000;
                if (owner_4 == player) total_property_value += 15000;
                if (owner_7 == player) total_property_value += 10000;
                if (owner_9 == player) total_property_value += 7500;
                if (owner_10 == player) total_property_value += 25000;
                if (owner_12 == player) total_property_value += 12500;
                if (owner_14 == player) total_property_value += 15000;
                if (owner_15 == player) total_property_value += 7500;
                if (owner_17 == player) total_property_value += 15000;
                if (owner_19 == player) total_property_value += 25000;
                if (owner_20 == player) total_property_value += 15000;
                if (owner_22 == player) total_property_value += 25000;
                if (owner_24 == player) total_property_value += 15000;
                if (owner_25 == player) total_property_value += 25000;
                if (owner_27 == player) total_property_value += 25000;
                if (owner_28 == player) total_property_value += 15000;
                if (owner_30 == player) total_property_value += 17500;
                if (owner_32 == player) total_property_value += 25000;
                if (owner_33 == player) total_property_value += 15000;
                if (owner_35 == player) total_property_value += 12500;
                if (owner_38 == player) total_property_value += 25000;
                if (owner_40 == player) total_property_value += 17500;

                // Calculate and apply property tax (5% of total property value)
                tax = total_property_value / 20; // This is equivalent to total_property_value * 0.05
                printf("\nReal Property Tax time! You are charged 5%% of your properties' value: ₱%d.\n", tax);
                printf("Total property value: ₱%d\n", total_property_value);
                *cash -= tax;
                printf("Your remaining balance: ₱%d.\n", *cash);
                return; // Return after processing tax to continue the game loop
            }
            break;
            case 11: // Manila City Jail
                if (original_position == 11){ // Only process if directly landed on jail
                    bool escaped = handle_jail(player, p1, p2, p3, p4);
                    if (escaped) {
                        printf("\n%s is now just visiting Manila City Jail.\n", player_name);
                    } else {
                        *cash -= 10000;
                        printf("Your balance after paying the fine: ₱%d.\n", *cash);
                    }
                    // Return after jail handling to continue the game loop
                    return;
                }
                break;
            case 31: // Manila Police District
                if (original_position == 31) { // Only process if directly landed on police
                    printf("\n%s is being sent to Manila City Jail!\n", player_name);
                    *pos = 11;  // Move player to jail position
                    bool escaped = handle_jail(player, p1, p2, p3, p4);
                    if (escaped) {
                        printf("\n%s is now just visiting Manila City Jail.\n", player_name);
                    } else {
                        *cash -= 10000;
                        printf("Your balance after paying the fine: ₱%d.\n", *cash);
                    }
                    // Return after jail handling to continue the game loop
                    return;
                }
                break;
            break;
    }

    // Determine the owner's name based on their player number
    if (*property_owner == 1) {
        owner_name = p1;
    } else if (*property_owner == 2) {
        owner_name = p2;
    } else if (*property_owner == 3) {
        owner_name = p3;
    } else if (*property_owner == 4) {
        owner_name = p4;
    }

    if (*property_owner == 0 && price > 0) {
        buy_property(cash, player, property_owner, price, property_name);
    } else if (*property_owner > 0 && rent > 0) {
        // Check if the player owns the property
        if (*property_owner == player) {
            printf("\nYou own this property. No rent to pay.\n");
        } else {
            *cash -= rent;
            printf("\nThis property is owned by %s. You paid ₱%d in rent.\nYour remaining balance: ₱%d.\n", owner_name, rent, *cash);

            // Add rent payment to property owner's cash
            if (*property_owner == 1) {
                *cash_p1 += rent;
                printf("%s received ₱%d in rent. New balance: ₱%d.\n", p1, rent, *cash_p1);
            } else if (*property_owner == 2) {
                *cash_p2 += rent;
                printf("%s received ₱%d in rent. New balance: ₱%d.\n", p2, rent, *cash_p2);
            } else if (*property_owner == 3) {
                *cash_p3 += rent;
                printf("%s received ₱%d in rent. New balance: ₱%d.\n", p3, rent, *cash_p3);
            } else if (*property_owner == 4) {
                *cash_p4 += rent;
                printf("%s received ₱%d in rent. New balance: ₱%d.\n", p4, rent, *cash_p4);
            }
        }
    }
}

/******************************************************* 
Function: void handle_owner
Description: Checks whether a property a player landed on is owned by another player, and if so, handles the rent payment.
Precondition(s): (position) - Valid position number 1 to 40. (pos, cash) - Valid pointers to integers. (player_num) - Valid player number 1 to 4. (owner_2 - owner_40) - Valid pointers to integers representing property owners. (p1, p2, p3, p4) - Valid character pointers to player names.
Parameters: (position) - The position the player landed on. (pos) - Pointer to the player's position. (cash) - Pointer to the player's cash. (player_num) - The current player's number. (owner_2 - owner_40) - Pointers to property owners. (p1, p2, p3, p4) - Player names.
Return Value: None. (pos, cash) may be modified.
*******************************************************/
void handle_owner(int position, int *pos, int *cash, int player_num, int *owner_2, int *owner_4, int *owner_7, int *owner_9, int *owner_10, int*owner_12, int *owner_14, int *owner_15, int *owner_17, int *owner_19, int *owner_20, int *owner_22, int *owner_24, int *owner_25, int *owner_27, int *owner_28, int *owner_30, int *owner_32, int *owner_33, int *owner_35, int *owner_38, int *owner_40, char *p1, char *p2, char *p3, char *p4, int *cash_p1, int *cash_p2, int *cash_p3, int *cash_p4){
    char *player_name = (player_num == 1) ? p1 : (player_num == 2) ? p2 : (player_num == 3) ? p3 : p4;
    int old_pos = *pos; // Store original position before any possible changes

    // Only check ownable properties
    if (position == 2){
        check_block(position, pos, cash, player_num, owner_2, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 4){
        check_block(position, pos, cash, player_num, owner_4, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 7){
        check_block(position, pos, cash, player_num, owner_7, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 9){
        check_block(position, pos, cash, player_num, owner_9, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 10){
        check_block(position, pos, cash, player_num, owner_10, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 12){
        check_block(position, pos, cash, player_num, owner_12, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 14){
        check_block(position, pos, cash, player_num, owner_14, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 15){
        check_block(position, pos, cash, player_num, owner_15, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 17){
        check_block(position, pos, cash, player_num, owner_17, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 19){
        check_block(position, pos, cash, player_num, owner_19, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 20){
        check_block(position, pos, cash, player_num, owner_20, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 22){
        check_block(position, pos, cash, player_num, owner_22, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 24){
        check_block(position, pos, cash, player_num, owner_24, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 25){
        check_block(position, pos, cash, player_num, owner_25, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 27){
        check_block(position, pos, cash, player_num, owner_27, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 28){
        check_block(position, pos, cash, player_num, owner_28, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 30){
        check_block(position, pos, cash, player_num, owner_30, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 32){
        check_block(position, pos, cash, player_num, owner_32, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 33){
        check_block(position, pos, cash, player_num, owner_33, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 35){
        check_block(position, pos, cash, player_num, owner_35, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 38){
        check_block(position, pos, cash, player_num, owner_38, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else if (position == 40){
        check_block(position, pos, cash, player_num, owner_40, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    } else {
        check_block(position, pos, cash, player_num, NULL, player_name, p1, p2, p3, p4, cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
    }

    // Check if position was changed by Chance card auto-purchase
    if (old_pos != *pos) {
        // Handle auto-purchase by setting ownership for the new position
        int new_pos = *pos;
        if (new_pos == 2) *owner_2 = player_num;
        else if (new_pos == 4) *owner_4 = player_num;
        else if (new_pos == 7) *owner_7 = player_num;
        else if (new_pos == 9) *owner_9 = player_num;
        else if (new_pos == 10) *owner_10 = player_num;
        else if (new_pos == 12) *owner_12 = player_num;
        else if (new_pos == 14) *owner_14 = player_num;
        else if (new_pos == 15) *owner_15 = player_num;
        else if (new_pos == 17) *owner_17 = player_num;
        else if (new_pos == 19) *owner_19 = player_num;
        else if (new_pos == 20) *owner_20 = player_num;
        else if (new_pos == 22) *owner_22 = player_num;
        else if (new_pos == 24) *owner_24 = player_num;
        else if (new_pos == 25) *owner_25 = player_num;
        else if (new_pos == 27) *owner_27 = player_num;
        else if (new_pos == 28) *owner_28 = player_num;
        else if (new_pos == 30) *owner_30 = player_num;
        else if (new_pos == 32) *owner_32 = player_num;
        else if (new_pos == 33) *owner_33 = player_num;
        else if (new_pos == 35) *owner_35 = player_num;
        else if (new_pos == 38) *owner_38 = player_num;
        else if (new_pos == 40) *owner_40 = player_num;
    }
}

/******************************************************* 
Function: bool check_bankruptcy_win
Description: Checks if only one player has money and all others are bankrupt.
Precondition(s): (cash1 - cash4) - Valid integers representing each player's cash. (p1 - p4) - Valid character pointers to player names.
Parameters: (cash1 - cash4) - Each player's cash. (p1 - p4) - Player names.
Return Value: (true) - If only one player is not bankrupt. (false) - If more than one player still has money.
*******************************************************/
bool check_bankruptcy_win(int cash1, int cash2, int cash3, int cash4, char *p1, char *p2, char *p3, char *p4) {
    if (cash1 > 0 && cash2 <= 0 && cash3 <= 0 && cash4 <= 0) {
        printf("\n----------------------------------------------------------");
        printf("\n** %s WINS! All other players are bankrupt! **", p1);
        printf("\n----------------------------------------------------------\n");
        return true;
    } else if (cash2 > 0 && cash1 <= 0 && cash3 <= 0 && cash4 <= 0) {
        printf("\n----------------------------------------------------------");
        printf("\n** %s WINS! All other players are bankrupt! **", p2);
        printf("\n----------------------------------------------------------\n");
        return true;
    } else if (cash3 > 0 && cash1 <= 0 && cash2 <= 0 && cash4 <= 0) {
        printf("\n----------------------------------------------------------");
        printf("\n** %s WINS! All other players are bankrupt! **", p3);
        printf("\n----------------------------------------------------------\n");
        return true;
    } else if (cash4 > 0 && cash1 <= 0 && cash2 <= 0 && cash3 <= 0) {
        printf("\n----------------------------------------------------------");
        printf("\n** %s WINS! All other players are bankrupt! **", p4);
        printf("\n----------------------------------------------------------\n");
        return true;
    }
    return false;
}

/******************************************************* 
Function: void determine_winner
Description: Calculates the total asset value for each player, including cash and property values, and determines the winner based on the highest total asset value.
Precondition(s): (cash_p1 - cash_p4) - Valid integers representing each player's cash. (owner_2 - owner_40) - Valid integers representing property owners. (p1 - p4) - Valid character pointers to player names.
Parameters: (cash_p1 - cash_p4) - Each player's cash. (owner_2 - owner_40) - Property owners. (p1 - p4) - Player names.
Return Value: None. The function prints the winner's name and total asset value.
*******************************************************/
void determine_winner(int cash_p1, int cash_p2, int cash_p3, int cash_p4, int owner_2, int owner_4, int owner_7, int owner_9, int owner_10, int owner_12, int owner_14, int owner_15, int owner_17, int owner_19, int owner_20, int owner_22, int owner_24, int owner_25, int owner_27, int owner_28, int owner_30, int owner_32, int owner_33, int owner_35, int owner_38, int owner_40, char *p1, char *p2, char *p3, char *p4){

    // Calculate the total assets
    int total_value_p1 = cash_p1;
    if (owner_2 == 1 || owner_9 == 1 || owner_17 == 1 || owner_27 == 1 || owner_32 == 1 || owner_38 == 1){
        total_value_p1 += 25000;
    } if (owner_4 == 1 || owner_10 == 1 || owner_20 == 1 || owner_22 == 1 || owner_35 == 1){
        total_value_p1 += 15000;
    } if (owner_7 == 1 || owner_14 == 1 || owner_19 == 1 || owner_24 == 1 || owner_28 == 1 || owner_33 == 1){
        total_value_p1 += 15000;
    } if (owner_12 == 1){
        total_value_p1 += 12500;
    } if (owner_15 == 1 || owner_25 == 1){
        total_value_p1 += 7500;
    } if (owner_30 == 1 || owner_40 == 1){
        total_value_p1 += 17500;
    }

    int total_value_p2 = cash_p2;
    if (owner_2 == 2 || owner_9 == 2 || owner_17 == 2 || owner_27 == 2 || owner_32 == 2 || owner_38 == 2){
        total_value_p2 += 25000;
    } if (owner_4 == 2 || owner_10 == 2 || owner_20 == 2 || owner_22 == 2 || owner_35 == 2){
        total_value_p2 += 15000;
    } if (owner_7 == 2 || owner_14 == 2 || owner_19 == 2 || owner_24 == 2 || owner_28 == 2 || owner_33 == 2){
        total_value_p2 += 15000;
    } if (owner_12 == 2){
        total_value_p2 += 12500;
    } if (owner_15 == 2 || owner_25 == 2){
        total_value_p2 += 7500;
    } if (owner_30 == 2 || owner_40 == 2){
        total_value_p2 += 17500;
    }

    int total_value_p3 = cash_p3;
    if (owner_2 == 3 || owner_9 == 3 || owner_17 == 3 || owner_27 == 3 || owner_32 == 3 || owner_38 == 3){
        total_value_p3 += 25000;
    } if (owner_4 == 3 || owner_10 == 3 || owner_20 == 3 || owner_22 == 3 || owner_35 == 3){
        total_value_p3 += 15000;
    } if (owner_7 == 3 || owner_14 == 3 || owner_19 == 3 || owner_24 == 3 || owner_28 == 3 || owner_33 == 3){
        total_value_p3 += 15000;
    } if (owner_12 == 3){
        total_value_p3 += 12500;
    } if (owner_15 == 3 || owner_25 == 3){
        total_value_p3 += 7500;
    } if (owner_30 == 3 || owner_40 == 3){
        total_value_p3 += 17500;
    }

    int total_value_p4 = cash_p4;
    if (owner_2 == 4 || owner_9 == 4 || owner_17 == 4 || owner_27 == 4 || owner_32 == 4 || owner_38 == 4){
        total_value_p4 += 25000;
    } if (owner_4 == 4 || owner_10 == 4 || owner_20 == 4 || owner_22 == 4 || owner_35 == 4){
        total_value_p4 += 15000;
    } if (owner_7 == 4 || owner_14 == 4 || owner_19 == 4 || owner_24 == 4 || owner_28 == 4 || owner_33 == 4){
        total_value_p4 += 15000;
    } if (owner_12 == 4){
        total_value_p4 += 12500;
    } if (owner_15 == 4 || owner_25 == 4){
        total_value_p4 += 7500;
    } if (owner_30 == 4 || owner_40 == 4){
        total_value_p4 += 17500;
    }

    // Determine the winner
    int max_value = total_value_p1;
    char *winner = p1;

    if (total_value_p2 > max_value){
        max_value = total_value_p2;
        winner = p2;
    } if (total_value_p3 > max_value){
        max_value = total_value_p3;
        winner = p3;
    } if (total_value_p4 > max_value){
        max_value = total_value_p4;
        winner = p4;
    }

    // Display the winner
    printf("\n===========================================================");
    printf("\n** GAME OVER! The winner is %s **", winner);
    printf("\n* Total asset value: ₱%d", max_value);
    printf("\n===========================================================\n");
    
    // Display final standings
    printf("\nFinal Standings:");
    printf("\n1. %s: ₱%d", winner, max_value);
    
    // Display 2nd, 3rd, and 4th places
    int place = 2;
    
    // Manually check each player and print them in descending order by value
    // Second place
    if (p1 != winner && (total_value_p1 >= total_value_p2 || p2 == winner) && 
        (total_value_p1 >= total_value_p3 || p3 == winner) && 
        (total_value_p1 >= total_value_p4 || p4 == winner)) {
        printf("\n%d. %s: ₱%d", place++, p1, total_value_p1);
    } else if (p2 != winner && (total_value_p2 >= total_value_p1 || p1 == winner) && 
               (total_value_p2 >= total_value_p3 || p3 == winner) && 
               (total_value_p2 >= total_value_p4 || p4 == winner)) {
        printf("\n%d. %s: ₱%d", place++, p2, total_value_p2);
    } else if (p3 != winner && (total_value_p3 >= total_value_p1 || p1 == winner) && 
               (total_value_p3 >= total_value_p2 || p2 == winner) && 
               (total_value_p3 >= total_value_p4 || p4 == winner)) {
        printf("\n%d. %s: ₱%d", place++, p3, total_value_p3);
    } else if (p4 != winner && (total_value_p4 >= total_value_p1 || p1 == winner) && 
               (total_value_p4 >= total_value_p2 || p2 == winner) && 
               (total_value_p4 >= total_value_p3 || p3 == winner)) {
        printf("\n%d. %s: ₱%d", place++, p4, total_value_p4);
    }
    
    // Third place - find the next highest value player who isn't already placed
    if (place <= 4) {
        if (p1 != winner && place > 2 && printf("\n%d. %s: ₱%d", place++, p1, total_value_p1));
        else if (p2 != winner && place > 2 && printf("\n%d. %s: ₱%d", place++, p2, total_value_p2));
        else if (p3 != winner && place > 2 && printf("\n%d. %s: ₱%d", place++, p3, total_value_p3));
        else if (p4 != winner && place > 2 && printf("\n%d. %s: ₱%d", place++, p4, total_value_p4));
    }
    
    // Fourth place - the remaining player
    if (place <= 4) {
        if (p1 != winner && place > 3 && printf("\n%d. %s: ₱%d", place++, p1, total_value_p1));
        else if (p2 != winner && place > 3 && printf("\n%d. %s: ₱%d", place++, p2, total_value_p2));
        else if (p3 != winner && place > 3 && printf("\n%d. %s: ₱%d", place++, p3, total_value_p3));
        else if (p4 != winner && place > 3 && printf("\n%d. %s: ₱%d", place++, p4, total_value_p4));
    }
    printf("\n");
}

int main(){

    // Initialize variable to check if all properties are bought
    bool all_properties_bought = false;

    // Initialize player name variables
    char p1[10], p2[10], p3[10], p4[10];

    // Initialize turn indicators
    int turn_p1, turn_p2, turn_p3, turn_p4;

    // Ensures random dice rolls
    srand(time(NULL));

    // Initialize player attributes
    int cash_p1 = 50000, cash_p2 = 10000, cash_p3 = 10000, cash_p4 = 10000; // Starting cash
    int pos_p1 = 1, pos_p2 = 1, pos_p3 = 1, pos_p4 = 1; // Starting block (1 = Go)
    int props_p1 = 0, props_p2 = 0, props_p3 = 0, props_p4 = 0; // Starting properties owned

   // Initialize variables to track who owns a property
  int owner_2 = 0, owner_4 = 0, owner_7 = 0, owner_9 = 0, owner_10 = 0, owner_12 = 0, owner_14 = 0, owner_15 = 0, owner_17 = 0, owner_19 = 0, owner_20 = 0, owner_22 = 0, owner_24 = 0, owner_25 = 0, owner_27 = 0, owner_28 = 0, owner_30 = 0, owner_32 = 0, owner_33 = 0, owner_35 = 0, owner_38 = 0, owner_40 = 0;

    display_intro(); // Display the intro message

  // Ask for player names
    printf("Enter player 1's name: ");
    scanf("%s", p1);
    printf("Enter player 2's name: ");
    scanf("%s", p2);
    printf("Enter player 3's name: ");
    scanf("%s", p3);
    printf("Enter player 4's name: ");
    scanf("%s", p4);

  // Roll dice
  int roll_p1 = roll_dice();
  int roll_p2 = roll_dice();
  int roll_p3 = roll_dice();
  int roll_p4 = roll_dice();

  // Display dice roll results
  printf("\n%s rolled: %d\n", p1, roll_p1);
  printf("%s rolled: %d\n", p2, roll_p2);
  printf("%s rolled: %d\n", p3, roll_p3);
  printf("%s rolled: %d\n", p4, roll_p4);

  // Sort players based on their dice roll
  sort_players(&p1, &p2, &p3, &p4, &roll_p1, &roll_p2, &roll_p3, &roll_p4);

  // Display the sorted order of players
  printf("\n----------------------------------------------------------\n\nTurn Order:\n");
  printf("\nFirst player: %s\n", p1);
  printf("Second player: %s\n", p2);
  printf("Third player: %s\n", p3);
  printf("Fourth player: %s\n", p4);
  printf("\n----------------------------------------------------------\n");

  // Set initial turn order
  turn_system(p1, p2, p3, p4, &turn_p1, &turn_p2, &turn_p3, &turn_p4, p1, p2, p3, p4);

  while (!all_properties_bought){
      // Check if a player wins by bankruptcy before each round
      if (check_bankruptcy_win(cash_p1, cash_p2, cash_p3, cash_p4, p1, p2, p3, p4)) {
          return 0; // End the game
      }
      
      // Player 1's turn
      if (cash_p1 > 0) {
          display_player_info(p1, cash_p1, 1, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
          roll_dice_move(p1, &pos_p1, &cash_p1);
          handle_owner(pos_p1, &pos_p1, &cash_p1, 1, &owner_2, &owner_4, &owner_7, &owner_9, &owner_10, &owner_12, &owner_14, &owner_15, &owner_17, &owner_19, &owner_20, &owner_22, &owner_24, &owner_25, &owner_27, &owner_28, &owner_30, &owner_32, &owner_33, &owner_35, &owner_38, &owner_40, p1, p2, p3, p4, &cash_p1, &cash_p2, &cash_p3, &cash_p4);
      } else {
          printf("\n----------------------------------------------------------");
          printf("\n* %s is bankrupt (₱0). Turn skipped.", p1);
          printf("\n----------------------------------------------------------\n");
      }

      // Player 2's turn
      if (cash_p2 > 0) {
          display_player_info(p2, cash_p2, 2, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
          roll_dice_move(p2, &pos_p2, &cash_p2);
          handle_owner(pos_p2, &pos_p2, &cash_p2, 2, &owner_2, &owner_4, &owner_7, &owner_9, &owner_10, &owner_12, &owner_14, &owner_15, &owner_17, &owner_19, &owner_20, &owner_22, &owner_24, &owner_25, &owner_27, &owner_28, &owner_30, &owner_32, &owner_33, &owner_35, &owner_38, &owner_40, p1, p2, p3, p4, &cash_p1, &cash_p2, &cash_p3, &cash_p4);
      } else {
          printf("\n----------------------------------------------------------");
          printf("\n* %s is bankrupt (₱0). Turn skipped.", p2);
          printf("\n----------------------------------------------------------\n");
      }

      // Player 3's turn
      if (cash_p3 > 0) {
          display_player_info(p3, cash_p3, 3, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
          roll_dice_move(p3, &pos_p3, &cash_p3);
          handle_owner(pos_p3, &pos_p3, &cash_p3, 3, &owner_2, &owner_4, &owner_7, &owner_9, &owner_10, &owner_12, &owner_14, &owner_15, &owner_17, &owner_19, &owner_20, &owner_22, &owner_24, &owner_25, &owner_27, &owner_28, &owner_30, &owner_32, &owner_33, &owner_35, &owner_38, &owner_40, p1, p2, p3, p4, &cash_p1, &cash_p2, &cash_p3, &cash_p4);
      } else {
          printf("\n----------------------------------------------------------");
          printf("\n* %s is bankrupt (₱0). Turn skipped.", p3);
          printf("\n----------------------------------------------------------\n");
      }

      // Player 4's turn
      if (cash_p4 > 0) {
          display_player_info(p4, cash_p4, 4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40);
          roll_dice_move(p4, &pos_p4, &cash_p4);
          handle_owner(pos_p4, &pos_p4, &cash_p4, 4, &owner_2, &owner_4, &owner_7, &owner_9, &owner_10, &owner_12, &owner_14, &owner_15, &owner_17, &owner_19, &owner_20, &owner_22, &owner_24, &owner_25, &owner_27, &owner_28, &owner_30, &owner_32, &owner_33, &owner_35, &owner_38, &owner_40, p1, p2, p3, p4, &cash_p1, &cash_p2, &cash_p3, &cash_p4);
      } else {
          printf("\n----------------------------------------------------------");
          printf("\n* %s is bankrupt (₱0). Turn skipped.", p4);
          printf("\n----------------------------------------------------------\n");
      }
      
      // Check if a player wins by bankruptcy after each full round
      if (check_bankruptcy_win(cash_p1, cash_p2, cash_p3, cash_p4, p1, p2, p3, p4)) {
          return 0; // End the game
      }

      // Check if all properties are bought
      all_properties_bought = (owner_2 > 0) && (owner_4 > 0) && (owner_7 > 0) && (owner_9 > 0) && (owner_10 > 0) && (owner_12 > 0) && (owner_14 > 0) && (owner_15 > 0) &&(owner_17 > 0) && (owner_19 > 0) && (owner_20 > 0) && (owner_22 > 0) && (owner_24 > 0) && (owner_25 > 0) && (owner_27 > 0) && (owner_28 > 0) && (owner_30 > 0) && (owner_32 > 0) && (owner_33 > 0) && (owner_35 > 0) && (owner_38 > 0) && (owner_40 > 0);
  }

    // Call function to determine the winner
    determine_winner(cash_p1, cash_p2, cash_p3, cash_p4, owner_2, owner_4, owner_7, owner_9, owner_10, owner_12, owner_14, owner_15, owner_17, owner_19, owner_20, owner_22, owner_24, owner_25, owner_27, owner_28, owner_30, owner_32, owner_33, owner_35, owner_38, owner_40, p1, p2, p3, p4);

    return 0;
}
