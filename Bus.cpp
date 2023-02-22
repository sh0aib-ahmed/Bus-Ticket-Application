#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Function to check if the given seat is already occupied
bool isSeatOccupied(int seatNumber)
{
    ifstream inFile("seats.txt");
    int seat;
    while (inFile >> seat) {
        if (seat == seatNumber) {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    return false;
}

// Function to book a seat
void bookSeat(int seatNumber)
{
    ofstream outFile("seats.txt", ios::app);
    outFile << seatNumber << endl;
    outFile.close();
    cout << "Seat " << seatNumber << " has been booked." << endl;
}

int main()
{
    int numSeats = 50;
    int seat;

    cout << "Welcome to the bus ticket application." << endl;
    cout << "There are " << numSeats << " seats available on this bus." << endl;

    while (true) {
        cout << "Enter seat number (1-" << numSeats << "): ";
        cin >> seat;

        if (seat < 1 || seat > numSeats) {
            cout << "Invalid seat number. Please enter a number between 1 and " << numSeats << "." << endl;
            continue;
        }

        if (isSeatOccupied(seat)) {
            cout << "Seat " << seat << " is already occupied. Please choose another seat." << endl;
            continue;
        }

        bookSeat(seat);
        break;
    }

    return 0;
}
