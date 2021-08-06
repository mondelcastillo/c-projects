#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <list>

#ifndef movie_h // Header file guard to avoid the problem of double inclusion 
#define movie_h

using namespace std;
//using namespace cv;
//#pragma once

class SandueBoxue {

private:
	//Movie Node 
	struct MNode {  
		int mID = 0;
		int mCopy;
		string mtitle;
		string mGenre;
		string mprod;
	};
	//Customer Node 
	struct CNode {
		int cID; 
		string cName; 
		string cAddress;
	};

	struct CRent {
		int custID; 
		int vID;
	};

public:
	//Methods of Movie 

	MNode M;
	list<MNode> mv;
	list <MNode>::iterator itr;

	void addMovie();  
	void moviedetails(); 
	void displayMovies(); 
	void availableMovie();
	void MovieSave(); 
	void MovieLoad(); 
	int movieCodegenerator(string movie_genre);

	//Methods of Customers 

	CNode cust;
	deque<CNode> customer;
	deque<CNode>::iterator it;

	void addCustomer(); 
	void detailsCustomer(); 
	void allrentedCustomer(); 
	void saveCustomer(); 
	void loadCustomer();

	//Methods for Rental 

	CRent r;
	stack<CRent> rent;
	vector <CRent> st;
	vector <CRent>::iterator i;

	void rentVideo();
	void saverentedVideo();
	void loadrentedVideo();
	void returnVideo();

};

#endif
