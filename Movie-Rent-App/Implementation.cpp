#include <iostream>
#include "Data.h"
using namespace std;

//ADD NEW Movie
void SandueBoxue::addMovie() { 
	cout << "\n\t\t-----------------------------------------------------------------\n";
	cout << "\t\t|\t\t\t   MOVIE CODES    \t\t\t|\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	cout << "\t\t|  000-099  |  Animation\t|  500-599  | Horror\t\t|\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	cout << "\t\t|  100-199  | Action\t\t|  600-699  | Musical\t\t|\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	cout << "\t\t|  200-299  | Comedy\t\t|  700-799  | Mystery\t\t|\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	cout << "\t\t|  300-399  | Crime\t\t|  800-899  | Romance\t\t|\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	cout << "\t\t|  400-499  | Drama\t\t|  900-999  | Science Fiction\t|\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	
	cin.ignore();
	cout << "Movie Title: ";
	getline(cin, M.mtitle);

	cout << "Genre: ";
	getline(cin, M.mGenre);

	M.mID = movieCodegenerator(M.mGenre);

	cout << "Production: ";
	getline(cin, M.mprod);

	cout << "Number of copies: ";
	cin >> M.mCopy;
	cout << "Movie ID: " << M.mID << endl; //mID = Movie ID

	while (M.mCopy <= 0) {
		cout << "INVALID!" << endl; system("pause"); system("cls");
		cout << "Movie ID: " << M.mID << endl;
		cout << "Genre: " << M.mGenre << endl;
		cout << "Production: " << M.mprod << endl;
		cout << "Number of copies: "; cin >> M.mCopy;
	}
	cin.ignore();
	mv.push_back(M);
	cout << "[SUCCESSFULLY ADDED!]" << endl;
	system("pause");

}
//RENT A Movie
void SandueBoxue::rentVideo() { 

	system("cls");
	int c_ID; int v_ID; char ch; 
	cout << "Customer ID: ";
	cin >> c_ID;

	for (it = customer.begin(); it != customer.end(); it++) {
		if (it->cID == c_ID) {
			do {
				cout << "Video ID: ";
				cin >> v_ID;
				for (itr = mv.begin(); itr != mv.end(); itr++) {
					if (itr->mID == v_ID) {
						r.custID = c_ID;
						r.vID = v_ID; 
						rent.push(r);
						st.push_back(r);
						itr->mCopy--;
						cout << "Rent another video? [Y/N]: ";
						cin >> ch;
						system("cls");
						cout << "Customer ID: " << c_ID << endl;
					}
				}
			} while (ch == 'y' || ch == 'Y');
		}
	}
}

void SandueBoxue::moviedetails() {  // [4] MOVIE DETAILS

	int id;
	bool found=false;
	system("cls");
	cout << "Movie ID: ";
	cin >> id;
	cout << endl;
	for (itr = mv.begin(); itr != mv.end(); itr++) {
		if (itr->mID == id) {
			found = true;		
			cout << "Video ID: " << itr->mID << endl;
			cout << "Movie Title: " << itr->mtitle << endl;
			cout << "Genre: " << itr->mGenre << endl;
			cout << "Production: " << itr->mprod << endl;
			cout << "Number of copies: " << itr->mCopy << endl;
		}
	}
	
	if (found==false) {
		cout << "Video not available!" << endl;
	}
		
	cout << endl;  system("pause");
}

void SandueBoxue::displayMovies() { // [5] DISPLAY ALL VIDEOS

	system("cls");
	cout << "Video ID " << setw(24) << "Movie Title " << setw(25) << "Genre " << setw(25) << "Production " << setw(25) << "Copies #" << endl;
	for (auto& itr : mv) {
		cout << itr.mID << setw(26) << itr.mtitle << setw(31) << itr.mGenre << setw(26) << itr.mprod << setw(20) << itr.mCopy << endl;
	} cout << endl;
	system("pause");

}

void SandueBoxue::availableMovie() { //[6] VIDEO AVAILABILITY

	int id;
	system("cls");
	cout << "Movie ID: ";
	cin >> id;
	for (itr = mv.begin(); itr != mv.end(); itr++) {
		if (itr->mID == id && itr->mCopy > 0) {
			cout << "Movie Title: " << itr->mtitle << endl;
			cout << "Genre:" << itr->mGenre << endl;
			cout << "Production: " << itr->mprod << endl;
			cout << "Number of Copies:" << itr->mCopy << endl;
			cout << "Availability: " << "Available" << endl;
		}
		else if (itr->mID == id && itr->mCopy == 0) {
			cout << "Availability: " << "Unavailable!" << endl;
		}
	} cout << endl; system("pause");
}

int SandueBoxue::movieCodegenerator(string movie_genre) {
	int mCode;
	if (movie_genre == "Animation")
	{

		mCode = 1 + (rand() % (99 - 1 + 1));
	}
	else if (movie_genre == "Action") {

		mCode = 100 + (rand() % (199 - 100 + 1));
	}
	else if (movie_genre == "Comedy") {

		mCode = 200 + (rand() % (299 - 200 + 1));
	}
	else if (movie_genre == "Crime") {
		mCode = 300 + (rand() % (399 - 300 + 1));

	}
	else if (movie_genre == "Drama") {

		mCode = 400 + (rand() % (499 - 400 + 1));
	}
	else if (movie_genre == "Horror") {

		mCode = 500 + (rand() % (599 - 500 + 1));
	}
	else if (movie_genre == "Musical") {

		mCode = 600 + (rand() % (699 - 600 + 1));
	}
	else if (movie_genre == "Mystery") {

		mCode = 700 + (rand() % (799 - 700 + 1));
	}
	else if (movie_genre == "Romance") {

		mCode = 800 + (rand() % (899 - 800 + 1));
	}
	else {

		mCode = 900 + (rand() % (999 - 900 + 1));
	}

	return mCode;

}

// ADD CUSTOMER
void SandueBoxue::addCustomer() { 

	system("cls");
	cust.cID++;
	cout << "Customer ID: " << cust.cID << endl; cin.ignore();

	cout << "Name: ";
	getline(cin, cust.cName);
	cout << "Address: ";
	getline(cin, cust.cAddress);

	customer.push_back(cust);
	cout << "[SUCCESSFULLY REGISTERED!]" << endl;
	system("pause");
}
//SHOW CUSTOMER DETAILS
void SandueBoxue::detailsCustomer() { 

	bool found = false;
	int id;
	system("cls");
	cout << "Customer ID: ";
	cin >> id;
	
	for (it = customer.begin(); it != customer.end(); ++it) {
		if (it->cID == id) {
			found = true;
			cout << endl << "[DETAILS]" << endl;
			cout << "Customer ID: " << it->cID << endl;
			cout << "Customer Name: " << it->cName << endl;
			cout << "Customer Address: " << it->cAddress << endl;
			break;
		}
	} 
	
	if (found==false) {
		cout << "Customer does not exist!" << endl;
	}
	
	system("pause");
}

// LIST ALL VIDEO RENTED
void SandueBoxue::allrentedCustomer() { 

	int c_ID;
	system("cls");
	cout << "Customer ID: ";
	cin >> c_ID;
	cout << endl;
	for (i = st.begin(); i != st.end(); i++) {
		for (it = customer.begin(); it != customer.end(); it++) {
			if (i->custID == c_ID && it->cID == c_ID) { //line 237, customer_ID. changing into cID
				cout << "Customer ID: " << it->cID << endl;
				cout << "Name: " << it->cName << endl;
				cout << "Address: " << it->cAddress << endl << endl;
			} break;
		} break;
	}

	for (i = st.begin(); i != st.end(); i++) {
		for (itr = mv.begin(); itr != mv.end(); itr++) {
			if (i->vID == itr->mID) {
				cout << "Video ID: " << itr->mID << endl;
				cout << "Movie Title: " << itr->mtitle << endl << endl;
			}
		}
	}
	system("pause");
}
//Saving a movie
void SandueBoxue::MovieSave() { 

	ofstream file;
	file.open("MovieList.txt");
	for (itr = mv.begin(); itr != mv.end(); itr++) {
		file << itr->mID << "," << itr->mtitle << "," << itr->mGenre << "," << itr->mprod << "," << itr->mCopy << endl;
	}file.close();

}

void SandueBoxue::MovieLoad() {

	ifstream file("MovieList.txt");

	int id;
	int numberofCopies;
	string title;
	string genre;
	string prod;
	string copy;
	string ID;
	string line;

	while (getline(file, line)) {
		stringstream s(line);
		getline(s, ID, ',');
		getline(s, title, ',');
		getline(s, genre, ',');
		getline(s, prod, ',');
		getline(s, copy, ',');

		numberofCopies = stoi(copy);
		id = stoi(ID);

		M.mID = id;
		M.mtitle = title;
		M.mGenre = genre;
		M.mprod = prod;
		M.mCopy = numberofCopies;
		mv.push_back(M);

	} file.close();

}

void SandueBoxue::saveCustomer() {

	ofstream file;
	file.open("CustomerList.txt");
	for (it = customer.begin(); it != customer.end(); it++) {
		file << it->cID << "," << it->cName << "," << it->cAddress << endl;
	}file.close();
}

void SandueBoxue::loadCustomer() {

	int id;
	string ID;
	string line;
	string name;
	string address;
	ifstream file("CustomerList.txt");
	while (getline(file, line)) {
		stringstream s(line);
		getline(s, ID, ',');
		getline(s, name, ',');
		getline(s, address, ',');

		id = stoi(ID);
		cust.cID = id;
		cust.cName = name;
		cust.cAddress = address;
		customer.push_back(cust);
	} file.close();
}


void SandueBoxue::saverentedVideo()
{
	ofstream file;
	file.open("RentedVids.txt");

	for (i = st.begin(); i != st.end(); i++) {
		file << i->custID << "," << i->vID << endl;
	}file.close();

}

void SandueBoxue::loadrentedVideo() {
	int cID;
	int mID;
	string CustID;
	string MovieID;
	string line;
	ifstream file("RentedVids.txt");
	while (getline(file, line)) {
		stringstream s(line);
		getline(s,CustID,',');
		getline(s, MovieID, ',');

		cID = stoi(CustID);
		mID = stoi(MovieID);
		r.custID = cID;
		r.vID = mID;
		rent.push(r);
		st.push_back(r);

	}file.close();


}

void SandueBoxue::returnVideo()
{
	system("cls");
	int c_ID; int v_ID;  //customer ID = c_ID ()
	cout << "Customer ID: ";
	cin >> c_ID;

	for (it = customer.begin(); it != customer.end(); it++) {
		if (it->cID == c_ID) {
				cout << "Video ID: ";
				cin >> v_ID;
				for (itr = mv.begin(); itr != mv.end(); itr++) {
					if (itr->mID == v_ID) {
						rent.pop();
						st.pop_back();
						itr->mCopy++;	
					}
				}
		
		}
	}
}

