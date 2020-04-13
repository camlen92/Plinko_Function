#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <ctime>

using namespace std;



//Prize money
const double prize0 = 100;
const double prize1 = 500;
const double prize2 = 1000;
const double prize3 = 0;
const double prize4 = 10000;
const double prize5 = 0;
const double prize6 = 1000;
const double prize7 = 500;
const double prize8 = 100;
const int rows = 12;


//Input:	
//Put in 1 or multiple chips into Plinko
//Press 3 to quit program
//After selection, reprompt user on what to do next(except quitting)

//Output:
//If incorrect input, reprompt to select another choice



//Test Cases:

// Test #1: If you enter "A" as a selection, the program will quit and you will be taken back to the menu.
// Test #2: If you enter a single chip into slot 7, the winnings are $100.0. 
// Test #3: If you enter 100 chips into slot 3, I unfortunately only won $100.00 dollars.

/**

Displays the Menu

*/
void menu()
{
	cout << "\t***PLINKO MENU***\n";
	cout << "Enter \"1\" to drop 1 chip.\n";
	cout << "Enter \"2\" to drop multiple chips.\n";
	cout << "Enter \"3\" to drop multiple chips into 9 slots.\n";
	cout << "Enter \"4\" to quit.\n";
}

/**

Find out the average winnings and total winnings
@param slot_number, print 
@return winnings, the total winnings

*/
double prize_money(double slot_number, bool print)
{
	int end_position = slot_number;
	int winnings = 0;
	
	switch (end_position)
	{
	case 0:
		winnings = winnings + prize0; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 1.\n";
		break;
	case 1:
		winnings = winnings + prize1; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 2.\n";
		break;
	case 2:
		winnings = winnings + prize2; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 3.\n";
		break;
	case 3:
		winnings = winnings + prize3; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 4.\n";
		break;
	case 4:
		winnings = winnings + prize4; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 5.\n";
		break;
	case 5:
		winnings = winnings + prize5; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 6.\n";
		break;
	case 6:
		winnings = winnings + prize6; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 7.\n";
		break;
	case 7:
		winnings = winnings + prize7; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 8.\n";
		break;
	case 8:
		winnings = winnings + prize8; 
		if (print)
			cout << "YOU WON: " << winnings << " ON SLOT 9.\n";
		break;
	}
	return winnings;
}

/**

Prints out the path of chips falling
@param start, show 
@return position of the chip

*/
double chipPath(double start, bool show)
{



	double position = start; // Set parameter to new variable for use in function
	

	if (show == true)
	cout << fixed << setprecision(1) << "PATH: [" << start;
	
	for (int i = 0; i < rows; i++)
	{

		int shift = rand() % 2;
		if (position == 0)
		{
			shift = rand() % 2;
			position = position + 0.5;

			if (show == true)
				cout << fixed << setprecision(1) << " " << position;


		}
		else if (position == 8)
		{
			shift = rand() % 2;
			position = position - 0.5;

			if (show == true)
				cout << fixed << setprecision(1) << " " << position;

		}
		else if (shift == 0)
		{
			shift = rand() % 2;
			position = position + 0.5;

			if (show == true)
				cout << fixed << setprecision(1) << " " << position;

		}
		else
		{
			shift = rand() % 2;
			position = position - 0.5;

			if (show == true)
				cout << fixed << setprecision(1) << " " << position;

		}
	}
	if (show == true)
	cout << "]";
	return position;  // Return position
}

/**

Processes money won from dropping multiple chips
@param number_chips, slot
@return sum of the winnings

*/
int multipleChips(int number_chips, double slot)
	{

		double sum = 0;
		for (int i = 0; i < number_chips; i++)  
		{
			sum+=prize_money(chipPath(slot, false), false); // Calls the prize_money function with chipPath function as parameter and set to not print path
		}
		return sum;
	}


/**

If the user chooses to drop single chip
@param slot_number
@return chipPath with slot choice for a single chip, set to print path

*/
int optionOne(int slot_number)
{
	double slot_choice_one = slot_number;
	int random_number = rand();
	int shift = rand() % 2;

	
	double prize_money(slot_choice_one);
	return chipPath(slot_choice_one, true);

}


/**

If the user chooses to drop multiple chips

*/
/*int optionTwo()
{
	double slot;
	int random_number = rand();
	int shift = rand() % 2;

	return chipPath(slot_choice_one, false);


	// How many chips will be dropped
	int chip_amount;
	cout << "\tDROP MULTIPLE CHIPS\n";
	cout << "How many chips do you want to drop? ";
	cin >> chip_amount;
	cout << endl;
	int final_chips = chip_amount;

	// If input is bad
	if (cin.fail() || chip_amount <= 0)
	{
		cout << endl << "INVALID NUMBER OF CHIPS. Please enter a number larger than zero" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	if (chip_amount > 0) // Find out what slot they are choosing
	{
		int slot_number;
		cout << "Which slot will you drop the chips in [0-8]?\n";
		cin >> slot_number;
		cout << fixed << setprecision(1) << "***DROPPING CHIPS INTO SLOT " << slot_number << "***" << endl << endl;

		if (cin.fail())
		{
			cout << endl << "INVALID SLOT.  Please enter an integer greater than zero." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (slot_number > 8 || slot_number < 0)
		{
			cout << endl << "INVALID SLOT. Please enter an integer [0-8]." << endl;
		}
		else
		{
			if (slot_number <= 8)
			{
				double winnings = 0;

				for (int number_chips = 0; number_chips < chip_amount; number_chips++)
				{
					slot = slot_number;

					for (int i = 0; i < rows; i++)
					{

						findPosition(slot);
					}
					
				}
			}
			
		}
		return slot;
	}
}
*/







int main()
{
	srand(time(0));

	
	while (true)
	{
		menu();
		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cout << endl << "INVALID Selection.  Please enter 1-4" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		if (choice == 1)
		{
			double slot;
			int random_number = rand();
			int shift = rand() % 2; // Find the remainder of the random value

			// Drop in a single chip
			cout << "\t***DROP SINGLE CHIP***\n";
			cout << "Which slot will you drop the chip in [0-8]?\n";
			cin >> fixed >> setprecision(1) >> slot;
			cout << fixed << setprecision(1) << "***DROPPING CHIP INTO SLOT " << slot << "***" << endl << endl;

			if (cin.fail())
			{
				cout << endl << "INVALID SLOT.  Please enter an integer between [0-8]." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (slot > 8 || slot < 0)
			{
				cout << fixed << setprecision(1) << endl << "INVALID SLOT.  Please enter an integer between [0-8]." << endl;
			}
			else
			{
				if (slot <= 8)
				{
					if (slot >= 0)
					{
						slot = optionOne(slot); // Call on the option one function with slot number as input
					}
				}
			}
		}

		else if (choice == 2)
		{
			double slot;
			int random_number = rand();
			int shift = rand() % 2; // Find the remainder of the random value

			// How many chips will be dropped
			int chip_amount;
			cout << "\tDROP MULTIPLE CHIPS\n";
			cout << "How many chips do you want to drop? ";
			cin >> chip_amount;
			cout << endl;
			int final_chips = chip_amount;

			// If input is bad
			if (cin.fail() || chip_amount <= 0)
			{
				cout << endl << "INVALID NUMBER OF CHIPS. Please enter a number larger than zero" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (chip_amount > 0) // Chip amount must be greater than zero
			{
				int slot_number;
				cout << "Which slot will you drop the chips in [0-8]?\n";
				cin >> slot_number;
				cout << fixed << setprecision(1) << "***DROPPING CHIPS INTO SLOT " << slot_number << "***" << endl << endl;

				if (cin.fail())
				{
					cout << endl << "INVALID SLOT.  Please enter an integer greater than zero." << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else if (slot_number > 8 || slot_number < 0)
				{
					cout << endl << "INVALID SLOT. Please enter an integer [0-8]." << endl;
				}

				else
				{
					if (slot_number <= 8)
					{
						double total_winnings = multipleChips(chip_amount, slot_number);

						cout << fixed << setprecision(2) << "TOTAL WINNINGS: $" << total_winnings << " ON: " << final_chips << " CHIPS " << endl;
						cout << fixed << setprecision(2) << "AVERAGE WINNINGS: $" << total_winnings / final_chips << " PER CHIP" << endl << endl;

					}
				}
			}
		}

		// Option 3: Drop _ chips into all 9 slots
		else if (choice == 3)
		{
			int chips_all_slots;
			cout << "\tDROP MULTIPLE CHIPS INTO ALL 9 SLOTS\n";
			cout << "How many chips do you want to drop? ";
			cin >> chips_all_slots;
			cout << endl;
			int final_chips_all_slots = chips_all_slots;

			// If input is bad
			if (cin.fail() || chips_all_slots <= 0)
			{
				cout << endl << "INVALID NUMBER OF CHIPS. Please enter a number larger than zero" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			else
			{
				int all_slots_choice = 9;

				for (int i = 0; i < all_slots_choice; i++)
				{
					double total_winnings = multipleChips(chips_all_slots, i);
					cout << fixed << setprecision(2) << "SLOT " << i << endl << endl;
					cout << fixed << setprecision(2) << "TOTAL WINNINGS: $" << total_winnings << i << endl;
					cout << fixed << setprecision(2) << "AVERAGE WINNINGS: $" << total_winnings / final_chips_all_slots << " FOR THIS SLOT." << endl << endl;
				}
			}
		}
		// If choice is to quit
		else if (choice == 4)
		{
			cout << "\tGOODBYE\n";
			return 0;
		}			
	}
	system("pause");
	return 0;
}