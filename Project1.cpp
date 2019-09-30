//------------------------------------------------------------------------------------------------------------------------
//Author:Oreoluwa Olukotun
//Description: This program simulates a Beverage Vending Machine
//------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <Math.h>
using namespace std;

const double TAX_RATE = 0.06; // the tax rate on beverages 
const int MAX_NUM_OZ = 18; // Maximum number of ounces user can order
const int MIN_NUM_OZ = 9;  // Minimum number of ounces user can order
const int OZ_DISPENSE = 3; // Number of ounces dispensed at a time
const int SLEEP_SECS = 2000; // Number of milliseconds program pauses 

void main()
{
	int CoffeeTank = 0;  //number of ounces in coffee tank
	int LatteTank = 0;  // number of ounces in latte tank
	int MochaTank = 0;  // number of ounces in Mocha tank
	int totalOunceCoffeeS = 0; // total ounce of coffee sold
	int totalOunceLatteS = 0;  // total ounce of latte sold
	int totalOunceMochaS = 0;  // total ounce of mocha sold
	int totalCoffeeL = 0;   // total ounce of coffee left in tank
	int totalLatteL = 0;    // total ounce of latte left in tank
	int totalMochaL = 0;   // total ounce of mocha left in tank
	int NumOz = 0; //User Entry number of ounces
	int i;
	double priceCoffee = 0.15;
	double priceLatte = 0.25;
	double priceMocha = 0.30;
	double subTotal = 0;
	double subTotalC = 0; // subtotal coffee
	double subTotalL = 0; // subtotal latte
	double subTotalM = 0; // subtotal mocha
	double totalCost = 0; // subtotal + tax
	double amountPaid = 0;
	double userChange = 0;
	double totalSold = 0; 
	double subTotalTax = 0;
	double PriceReceipt = 0;
	string FirstLetter;
	string SecretCode = "!";
	string UserEntry;
	string UserSelection;
	 
	
	

//STARTUP

	//LOGO
	cout << "+-----------------------------------------+" << endl;
	cout << "+             OREO'S CAFE                 +" << endl;
	cout << "+          By <Oreoluwa Olukotun>         +" << endl;
	cout << "+-----------------------------------------+" << endl;

	//Get Initial Ounces for StartUp
	cout << "STARTUP: Enter tank levels" << endl;
	cout << "Coffee Tank: ";
	cin >> CoffeeTank;
	cout << "Latte Tank:  ";
	cin >> LatteTank;
	cout << "Mocha Tank:  ";
	cin >> MochaTank;
	cout << "\n";  
	cout << "\n";

	//Beverage Selection
	cout << "PLEASE SELECT YOUR BEVERAGE !" << endl;
	if (CoffeeTank > MAX_NUM_OZ)
	{
		cout << "C. Coffee $ " << fixed << setprecision(2) << setw(5) << priceCoffee<<  " per oz." << endl;
	}

	if (LatteTank > MAX_NUM_OZ)
	{
		cout << "L. Latte  $ " << fixed << setprecision(2) << setw(5) << priceLatte << " per oz." << endl;
	}

	if (MochaTank > MAX_NUM_OZ)
	{
		cout << "M. Mocha  $ " << fixed << setprecision(2) << setw(5) << priceMocha << " per oz." << endl;
	}
	cout << "----> ";
	cin >> UserEntry;
	FirstLetter = toupper(UserEntry[0]); // gets first letter of user entry and capitalizes

	
	while (UserEntry != SecretCode)
	{
		// Validating User Entry for bev selection
		while ((FirstLetter != "C") && (FirstLetter != "L") && (FirstLetter != "M"))
		{
			//cout << "\n";
			cout << "Invalid selection! Try again!" << endl;
			cout << "----> ";
			cin >> UserEntry;
			FirstLetter = toupper(UserEntry[0]);
		

			
		}// end of while statement bev entry validation

		// validating beverage levels and user entry
		while ((FirstLetter == "C" && CoffeeTank < MAX_NUM_OZ) || (FirstLetter == "L" && LatteTank < MAX_NUM_OZ) ||
			 (FirstLetter == "M" && MochaTank < MAX_NUM_OZ))
		{
			cout << "Invalid selection! Try again!" << endl;
			cout << "----> ";
			cin >> UserEntry;
			FirstLetter = toupper(UserEntry[0]);
		}

		// gets number of ounces
		if ((FirstLetter == "C" && CoffeeTank > MAX_NUM_OZ) || (FirstLetter == "L" && LatteTank > MAX_NUM_OZ) ||
			(FirstLetter == "M" && MochaTank > MAX_NUM_OZ))
		{
			cout << "How many ounces would you like ("<< MIN_NUM_OZ << "-" << MAX_NUM_OZ << "):";
			cin >> NumOz;

		}

		
		//Number of OUNCE validation
		while ((NumOz < MIN_NUM_OZ) || (NumOz > MAX_NUM_OZ))
		{
			cout << "Invalid Entry !" << endl;
			cout << "Number of ounces (9-18): ";
			cin >> NumOz;
		}

		// if all validations are met
		if (NumOz >= MIN_NUM_OZ || NumOz <= MAX_NUM_OZ)
		{
			// coffee 
			if (FirstLetter == "C")
			{
				totalOunceCoffeeS += NumOz;
				CoffeeTank -= NumOz; // keeps record of coffee levels
				UserSelection = "Coffee";
				PriceReceipt += priceCoffee;
				// calculates user price
				subTotal = priceCoffee * NumOz;
				subTotalTax = subTotal * TAX_RATE;
				subTotalC += subTotal;
				totalCost = round((subTotal + subTotalTax) * 100) / 100;
				cout << "Total Price:  $  " << totalCost << endl;
				cout << "Pay here:     $  ";
				cin >> amountPaid;
			}// end if statement coffee calculations
		}

		// latte

		if (FirstLetter == "L")
		{
			totalOunceLatteS += NumOz; 
			LatteTank -= NumOz; // keeps record of latte levels
			UserSelection = "Latte";
			PriceReceipt += priceLatte;
			// calculates user price
			subTotal = priceLatte * NumOz;
			subTotalTax = subTotal * TAX_RATE;
			subTotalL += subTotal;
			totalCost = round((subTotal + subTotalTax) * 100) / 100;
			cout << "Total Price:  $  " << totalCost << endl;
			cout << "Pay here:     $  ";
			cin >> amountPaid;
		} //end of if latte calculation

		// mocha
		if (FirstLetter == "M")
		{
			totalOunceMochaS += NumOz;
			MochaTank -= NumOz;  // keeps record of mocha levels
			UserSelection = "Mocha";
			PriceReceipt += priceMocha;
			// calculates user price
			subTotal = priceMocha * NumOz;
			subTotalTax = subTotal * TAX_RATE;
			subTotalM += subTotal;
			totalCost = round ((subTotal + subTotalTax) * 100)/ 100;
			cout << "Total Price:  $  " << totalCost << endl;
			cout << "Pay here:     $  ";
			cin >> amountPaid;
		} //end of if mocha calculations
	

		//amount paid validation
		while (amountPaid < totalCost)
		{
			cout << "That is not enough! Please try again." << endl;
			cout << "Pay here: ";
			cin >> amountPaid;
		}// end while statement

		if (amountPaid > totalCost)
		{
			userChange = amountPaid - totalCost;
			cout << "Pick up your $ " << userChange << " change.  Your " << UserSelection << " will now be brewed !" << endl;
			cout << "\n";		
		}//  end if statement amount paid

		cout << "Get ready for your tasty " << UserSelection << endl;

		for (i = 0; i <= NumOz; i ++)
		{
			Sleep(SLEEP_SECS);

			if ((i % OZ_DISPENSE == 0) && (i <= NumOz))
			{
				cout << i << " ounces dispensed ..." << endl;
			}

			if (( i % OZ_DISPENSE != 0) && (i == NumOz))
			{
				cout << i << " ounces dispensed... " << endl;
			}
		}

		Sleep(SLEEP_SECS); // to get a little pause before receipt

		//RECEIPT
		cout << "\n";
		cout << "Your " << UserSelection << " is ready! Here is your receipt." <<  endl;
		cout << "Beverage:              " << UserSelection << endl;
		cout << "Ounces:                " << NumOz << endl;
		cout << "Price Per Oz:       $ " << fixed << setprecision(2) << setw(5)<< PriceReceipt << endl;
		cout << "Sub Total:          $ " << fixed << setprecision(2) << setw(5)<< subTotal << endl;
		cout << "Tax:                $ " << fixed << setprecision(2) << setw(5) << subTotalTax << endl;
		cout << "Total:              $ " << fixed << setprecision(2) << setw(5) << totalCost << endl;
		cout << "Amount Paid:        $ " << fixed  << setprecision(2) << setw(5) << amountPaid<< endl;
		cout << "Change:             $ " << fixed << setprecision(2) << setw(5) << userChange << endl;
		cout << "\n";
	    cout << "Thank you for shopping with Oreo's Cafe !!!" << endl;

				
		totalSold = subTotalC + subTotalL + subTotalM; // total sold for the period
		cout << "\n";
		cout << "\n";	
		system("pause");

		
		//Beverage Selection
		cout << "PLEASE SELECT YOUR BEVERAGE !" << endl;
		if (CoffeeTank > MAX_NUM_OZ)
		{
			cout << "C. Coffee $ " << fixed << setprecision(2) << setw(5) << priceCoffee << " per oz." << endl;
		}

		if (LatteTank > MAX_NUM_OZ)
		{
			cout << "L. Latte  $ " << fixed << setprecision(2) << setw(5) << priceLatte << " per oz." << endl;
		}

		if (MochaTank > MAX_NUM_OZ)
		{
			cout << "M. Mocha  $ " << fixed << setprecision(2) << setw(5) << priceMocha << " per oz." << endl;
		}
		cout << "----> ";
		cin >> UserEntry;
		FirstLetter = toupper(UserEntry[0]);
    }// end main while loop

	
	if (UserEntry == SecretCode)
	{
		// prints out shutown message which gives break down of all transactions.
		cout << "SHUTDOWN:  Total Sold" << endl;
		cout << "BEVERAGE     OUNCES      TOTAL SOLD       LEFT IN TANK" << endl;
		cout << "--------     ------    -------------     ------------" << endl;
		cout << "Coffee" <<" " << setw(10) << fixed << setprecision(0) << totalOunceCoffeeS <<"       $" << fixed << setprecision(2) << setw(10) << subTotalC << " " << setw(12) << fixed << setprecision(0) << CoffeeTank << endl;
		cout << "Latte " <<" " << setw(10) << fixed << setprecision(0) << totalOunceLatteS  <<"       $" << fixed << setprecision(2) << setw(10) << subTotalL << " " << setw(12) << fixed << setprecision(0) << LatteTank << endl;
		cout << "Mocha " <<" " << setw(10) << fixed << setprecision(0) << totalOunceMochaS  <<"       $" << fixed << setprecision(2) << setw(10) << subTotalM << " " << setw(12) << fixed << setprecision(0) << MochaTank << endl;
		cout << "Total " <<"                  $" <<fixed << setprecision(2) << setw(10) << totalSold << endl;
	}

	system("pause");
}
			

			

			

	

	
