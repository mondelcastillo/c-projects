#include "Implementation.cpp"
#include <iostream>
#include "Data.h"
using namespace std;

int main() {

	SandueBoxue shop;
	shop.MovieLoad();
	shop.loadCustomer();
	shop.loadrentedVideo();
	int ch=0; int c=0;

	while (true) {
		
		system("cls");
		cout << "\n\n\t\t\t* * * SANDUE BOXEU MOVIE RENTAL SHOP * * *\n";
		cout << "\t\t\t*\t\t\t\t\t *\n";
		cout << "\t\t\t*\t[1] Insert a New Movie\t\t *\n"; //(insert operation)

		cout << "\t\t\t*\t[2] Rent a Movie\t\t *\n"; //(delete operation)  //enter customer ID tas 
		cout << "\t\t\t*\t[3] Return a Movie\t\t *\n"; //(append operation)

		cout << "\t\t\t*\t[4] Show Movie Details\t\t *\n"; //(traversal operation with match Movie Code)
		cout << "\t\t\t*\t[5] Display Movies \t\t *\n"; //(traversal operation)

		cout << "\t\t\t*\t[6] Check Movie Availability\t *\n"; //(destructor)
		cout << "\t\t\t*\t[7] Customer Management\t\t *\n"; //(destructor)
		cout << "\t\t\t*\t[8] Leave\t\t\t *\n"; //(destructor)
		cout << "\t\t\t*\t\t\t\t\t *\n";
		cout << "\t\t\t* * * *   \t\t\t   * * * * \n";
		cout << "\t\t\t\t    Enter Choice: ";
		cin >> ch;
		switch (ch) {
		case 1:
		system("cls");
		shop.addMovie();
		break;
		case 2:
			shop.displayMovies();
			shop.rentVideo();
		break;

		case 3:

			shop.returnVideo();

			cout << endl; system("pause");
		break;
		
		case 4:
			shop.moviedetails();
		break;

		case 5:
			shop.displayMovies();
			break;

		case 6:
			shop.availableMovie();
		break;
 
		case 7:
			system("cls");
			cout << "[1] Add New Customer" << endl;
			cout << "[2] Show Customer Details" << endl;
			cout << "[3] List of Videos Rented by a Customer" << endl;
			cout << "Enter choice: ";
			cin >> c;
			if (c == 1) {
				shop.addCustomer();
			}
			else if (c == 2) {
				shop.detailsCustomer();
			}
			else if (c == 3) {
				shop.allrentedCustomer();
			}
			else {
				cout << "Invalid Input!" << endl;
			}
		break;

		case 8:
			shop.saverentedVideo();
			shop.saveCustomer();
			shop.MovieSave();
			exit(0);
		break;

		default:
			cout << "Invalid Input!" << endl;
			system("pause");
		break;

		}
		
	}
	return 0;
}
