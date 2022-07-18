#include <iostream>
#include <fstream>

using namespace std;

struct Seat
{
    char column;
    int row;
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

// Initial variables declaring
Passenger passengers[72];

int menuOption = 0, codePlaceholder = 100, reserves = 0;

char saveOption;

int main()
{
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
            // Call function depending on user input
            optionManager();
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

void optionManager()
{
    switch (menuOption)
    {
    case 1:
        newPassenger();
        break;
    
    case 2:
        showPassengers();
        break;
    
    case 3:
        showSeats();
        break;
    
    case 4:
        removePassenger();
        break;
    
    case 5:
        sortPassengers();
        break;
    
    case 6:
        generateTicket();
        break;
    
    case 7:
        saveData();
        break;

    default:
        break;
    }
}