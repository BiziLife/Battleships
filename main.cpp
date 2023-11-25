#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

//Global declarations
const int NUMBEROfROWS = 25;
const int NUMBEROFCOLUMNS = 25;

//Function prototypes
void fire(int& x, int& y, char boardGame[NUMBEROFCOLUMNS][NUMBEROfROWS]);
bool fleetSunk(int& x, int& y, char boardGame[NUMBEROFCOLUMNS][NUMBEROfROWS]);
void wait();

int main() {
	//Variable declarations
	char boardGame[NUMBEROFCOLUMNS][NUMBEROfROWS]{ '\0' };
	int x{ 0 }, y{ 0 };
	bool allShipsSunk{ false };
	ifstream inFile;

	//Program logic
	inFile.open("boardGame.txt");
	if (inFile.fail() == true) {
		cout << "File could not be found" << endl;
		return 1;
	}
	else {

		for (int cols = 0; cols < NUMBEROFCOLUMNS; ++cols) {
			for (int rows = 0; rows < NUMBEROfROWS; ++rows) {
				inFile >> boardGame[cols][rows];
			}
		}
		inFile.close();

		cout << "Welcome to battle ship!" << endl << endl;

		cout << "The enemy has hacked into our satellites" << endl
			<< "making there ships disapear on the map below." << endl
			<< "Your going to have to guess where there location is." << endl
			<< "Have fun soilder!" << endl << endl;

		do {
			//calls the fire function
			fire(x, y, boardGame);

		} while (!fleetSunk(x, y, boardGame));
	}
	

	//Closing program statements

	wait();
	return 0;
}

//Function Definitions
void fire(int& x, int& y, char boardGame[NUMBEROFCOLUMNS][NUMBEROfROWS]) {
	

	for (int cols = 0; cols < NUMBEROFCOLUMNS; ++cols) {
		for (int rows = 0; rows < NUMBEROfROWS; ++rows) {
			if (boardGame[cols][rows] == '#') {
				cout << '~';
			}
			else
				cout << boardGame[cols][rows];
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "Enter in an X and Y coordinate: ";
	cin >> x >> y;

	if (x < NUMBEROfROWS && y < NUMBEROFCOLUMNS) {
		if (boardGame[y][x] == '#') {
			boardGame[y][x] = 'H';
			cout << "Hit" << endl << endl;
		}
		else if (boardGame[y][x] == 'H') {
			cout << "Hit Again!" << endl << endl;
		}
		else {
			boardGame[y][x] = 'M';
			cout << "Missed" << endl << endl;
		}
	}
	else {
		cout << "The number you enter is out of bounds. Please enter a number from 0 to 24 for the coordinates " << endl << endl;
	}
}

bool fleetSunk(int& x, int& y, char boardGame[NUMBEROFCOLUMNS][NUMBEROfROWS]) {

	bool allShipsSunk{ true };

	for (int cols = 0; cols < NUMBEROFCOLUMNS; ++cols) {
		for (int rows = 0; rows < NUMBEROfROWS; ++rows) {
			if (boardGame[cols][rows] == '#') {
				allShipsSunk = false;
			}
		}
	}

	if (allShipsSunk) {
		cout << "Congrats you have sunk all ships!" << endl  << endl;
	}

	return allShipsSunk;
}


void wait()
{
	
	if (cin.rdbuf()->in_avail() > 0) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\t'); 
	}
	cout << "Press the Enter key to continue ... ";
	cin.get();
}
 
