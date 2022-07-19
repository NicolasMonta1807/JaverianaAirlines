#include <iostream>
#include <fstream>

using namespace std;

struct Seat
{
    char column;
    int row;
    int columnInteger;
};

struct Passenger{
    char name[30];
    char surname[30];
    int id;
    int age;
    Seat booking;
    int reserveCode;
    int group;
};

int menu();

bool validateMenu();

void optionManager();

void newPassenger(Passenger passengers[], int reserves, int codePlaceholder);

bool validSeat(int requestedRow, char requestedColumn);

bool validRow(int requestedRow, int passengerAge);

bool validColumn(int requestedColumn);

int assignGroup(Passenger passenger);

int convertColumn(char column);

// Initial state of airplane seats
int SEATS[12][6]
{
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}
};


int main()
{
    // Initial variables declaring
    Passenger passengers[72];

    int menuOption = 0, codePlaceholder = 100, reserves = 0;

    char saveOption;

    // Welcome greeting
    cout << "*****************************" << endl;
    cout << "Welcome to Javeriana Airlines" << endl;
    cout << "*****************************" << endl;

    system("PAUSE");
    system("CLS");


    //Prompting for menu option
    while(menuOption != -1)
    {
        menuOption = menu();

        if(validateMenu())
        {
            switch (menuOption)
            {
                case 1:
                    newPassenger(passengers, reserves, codePlaceholder);
                    codePlaceholder++;
                    break;
                
                case 2:
                    // showPassengers();
                    break;
                
                case 3:
                    // showSeats();
                    break;
                
                case 4:
                    // removePassenger();
                    break;
                
                case 5:
                    // sortPassengers();
                    break;
                
                case 6:
                    // generateTicket();
                    break;
                
                case 7:
                    // saveData();
                    break;

                default:
                    break;
            }
        }
    }
    

    return 0;
}

int menu()
{
    int option;

    cout << "1. Para ingresar un pasajero" << endl;
    cout << "2. Mostrar pasajeros" << endl;
    cout << "3. Mostrar cupos" << endl;
    cout << "4. Remover pasajero" << endl;
    cout << "5. Ordenar pasajeros" << endl;
    cout << "6. Generar pasabordo" << endl;
    cout << "7. Guardar datos" << endl;
    cout << "-1. Terminar" << endl;
    cin >> option;

    return option;
}

bool validateMenu()
{
    if (menuOption < -1 || menuOption > 7)
    {
        cout << "Invalid option. Try again" << endl;
        return false;
    }

    return true;
}

void newPassenger(Passenger passengers[], int reserves, int codePlaceholder)
{   
    int requestedRow, columnMarker;

    char requestedColumn;

    system("CLS");

    // Prompting for passenger's personal info
    cout << "Passenger's name: ";
    cin >> passengers[reserves].name;

    cout << "Passenger's surname: ";
    cin >> passengers[reserves].surname;

    cout << "Passenger's ID: ";
    cin >> passengers[reserves].id;

    cout << "Passenger's age: ";
    cin >> passengers[reserves].age;

    system("CLS");

    // showSeats();

    // Validating user's input
    do
    {
        do
        {
            cout << "Input the desired row number: ";
            cin >> requestedRow;
        }
        while(!validRow(requestedRow, passengers[reserves].age));

        do
        {   
            cout << "Input the desired column letter: ";
            cin >> requestedColumn;
        }
        while(!validColumn(requestedColumn));
        
        columnMarker = convertColumn(requestedColumn);
    }
    while(!validSeat(requestedRow, columnMarker));
    
    // Assigning validated seat
    passengers[reserves].booking.row = requestedRow;
    passengers[reserves].booking.column = requestedColumn;
    passengers[reserves].booking.columnInteger = columnMarker;

    passengers[reserves].group = assignGroup(passengers[reserves]);
}

bool validSeat(int requestedRow, char columnMarker)
{
    // Checking occupied seats
    if((SEATS[requestedRow - 1][columnMarker]) == 1)
    {
        cout << "!That seat is already occupied¡ Please, select another one" << endl;
        return false;
    }

    return true;
}

bool validRow(int requestedRow, int passengerAge)
{
    // Validating row user's input
    if (requestedRow > 12)
    {
        cout << "¡Enter row again! Invalid number" << endl;
        return false;
    }

    if (requestedRow < 1)
    {
        cout << "¡Enter row again! Invalid number" << endl;
        return false;
    }

    if (requestedRow == 7 && passengerAge < 18)
    {
        cout << "¡Enter row again! Passengers below legal age should not go in row number 7" << endl;
        return false;
    }

    return true;
}

bool validColumn(int requestedColumn)
{
    if (requestedColumn < 65 || requestedColumn > 70)
    {
        cout << "!Enter column again¡ Invalid letter (Please, just use uppercase letters)" << endl;
        return false;
    }

    return true;
}

int convertColumn(char column)
{
    switch (column)
    {
        case 'A':
            return 0;

        case 'B':
            return 1;

        case 'C':
            return 2;

        case 'D':
            return 3;

        case 'E':
            return 4;

        case 'F':
            return 5;
    }
}

int assignGroup(Passenger passenger)
{
    if (passenger.booking.row < 5)
    {
        cout << "You were assigned to group: A" << endl;
        return 'A';
    }

    if (passenger.booking.row < 9)
    {
        cout << "You were assigned to group: B" << endl;
        return 'B';
    }

    if (passenger.booking.row < 13)
    {
        cout << "You were assigned to group: C" << endl;
        return 'C';
    }
}