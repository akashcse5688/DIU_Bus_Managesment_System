#include <iostream>
#include <cstring>

using namespace std;

class Bus
{
private:
    // char busn[7];
    char driver[10];
    char arrival[10];
    char depart[10];
    char from[10];
    char to[10];
    char seat[8][4][10];

public:
    char busn[7];
    void addNewBus();
    void allotmentOfSeatToPassenger();
    void empty();
    void showAvailableBusSeats();
    void showReservedBusSeats();
    void showBusInfo();
};

void Bus::addNewBus()
{
    cout << "Enter bus no: ";
    cin >> busn;
    cout << "Enter Driver's name: ";
    cin >> driver;
    cout << "Enter Arrival time: ";
    cin >> arrival;
    cout << "Enter Departure time: ";
    cin >> depart;
    cout << "Enter From: ";
    cin >> from;
    cout << "Enter To: ";
    cin >> to;
    empty();
}

void Bus::allotmentOfSeatToPassenger()
{
    int seatNum;
    cout << "Bus no: " << busn << endl;
    cout << "Seat Number: ";
    cin >> seatNum;

    if (seatNum < 1 || seatNum > 32)
    {
        cout << "Invalid seat number. Please choose a seat between 1 and 32." << endl;
        return;
    }

    int row = (seatNum - 1) / 4;
    int col = (seatNum - 1) % 4;

    if (strcmp(seat[row][col], "Empty") == 0)
    {
        cout << "Enter passenger's name: ";
        cin >> seat[row][col];
        cout << "Seat number " << seatNum << " reserved for " << seat[row][col] << "." << endl;
    }
    else
    {
        cout << "The seat number is already reserved." << endl;
    }
}

void Bus::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(seat[i][j], "Empty");
        }
    }
}

void Bus::showAvailableBusSeats()
{
    cout << "Bus no: " << busn << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int seatNum = i * 4 + j + 1;
            cout << "Seat " << seatNum << ": " << seat[i][j] << endl;
        }
    }
}

void Bus::showReservedBusSeats()
{
    cout << "Bus no: " << busn << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int seatNum = i * 4 + j + 1;
            if (strcmp(seat[i][j], "Empty") != 0)
            {
                cout << "Seat " << seatNum << ": " << seat[i][j] << endl;
            }
        }
    }
}

void Bus::showBusInfo()
{
    cout << "Bus no: " << busn << endl;
    cout << "Driver: " << driver << endl;
    cout << "Arrival time: " << arrival << endl;
    cout << "Departure time: " << depart << endl;
    cout << "From: " << from << endl;
    cout << "To: " << to << endl;
}

int main()
{
    Bus buses[100];
    int numBuses = 0;

    cout << "\t\t\t\t***DIU Student Bus Services***" << endl
         << endl;

    while (true)
    {
        cout << "\n\n";
        cout << "\t\t\t1. Add new Bus Details\n";
        cout << "\t\t\t2. Reserve your seats\n";
        cout << "\t\t\t3. Show the available seats in a bus\n";
        cout << "\t\t\t4. Buses Available Now\n";
        cout << "\t\t\t5. Exit\n";
        cout << "\n\t\t\tEnter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            if (numBuses < 100)
            {
                buses[numBuses].addNewBus();
                numBuses++;
            }
            else
            {
                cout << "Maximum number of buses reached." << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the bus number: ";
            char busNumber[7];
            cin >> busNumber;
            int busIndex = -1;

            for (int i = 0; i < numBuses; i++)
            {
                if (strcmp(buses[i].busn, busNumber) == 0)
                {
                    busIndex = i;
                    break;
                }
            }

            if (busIndex != -1)
            {
                buses[busIndex].allotmentOfSeatToPassenger();
            }
            else
            {
                cout << "Bus not found. Please enter a valid bus number." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter the bus number: ";
            char busNumber[7];
            cin >> busNumber;
            int busIndex = -1;

            for (int i = 0; i < numBuses; i++)
            {
                if (strcmp(buses[i].busn, busNumber) == 0)
                {
                    busIndex = i;
                    break;
                }
            }

            if (busIndex != -1)
            {
                buses[busIndex].showAvailableBusSeats();
            }
            else
            {
                cout << "Bus not found. Please enter a valid bus number." << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Buses Available Now:" << endl;
            for (int i = 0; i < numBuses; i++)
            {
                buses[i].showBusInfo();
                buses[i].showReservedBusSeats();
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Successfully logged out from the application" << endl;
            cout << "<Thank you :)> " << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
