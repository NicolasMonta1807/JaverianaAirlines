#include <iostream>
#include <fstream>

using namespace std;

struct Tident
{
    char Nombre[30];
    char Apellido[30];
    int Id;
    int Edad;
    char Columna;
    int Fila;
    int Cod;
    char Grupo;
};

int Sillas [12][6] =
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

void leer_pasajero(Tident pasajeros[], int Tam, int codigo);

void leer(Tident pasajeros[]);

void imprimir_pasajeros(Tident pasajeros[], int Tam);

void guardar_datos(Tident pasajeros[], int Tam);

int cargar_pasajeros(Tident pasajeros[]);

void actualizar_cupos(Tident Pasajero[], int Tam);

void actualizar_cupo(Tident pasajero);

void imprimir_cupos();

void remover_pasajero(Tident pasajeros[], int Tam);

void ordenar_pasajeros(Tident pasajeros[], int Tam);

void pasabordo(Tident pasajeros[], int Tam);

int main()
{
    Tident pasajeros[72];

    int opc = 0, codigo = 100, Tam = 0;

    char save = 'z';

    cout << "*******************************" << endl;
    cout << "Bienvenid@ a Javeriana Airlines" << endl;
    cout << "*******************************" << endl;

    system("PAUSE");

    system("CLS");

    Tam = cargar_pasajeros(pasajeros) - 1;

    if (Tam == -1)
    {
        Tam = 0;
    }

    if(Tam > 0)
    {
        cout << "**************" << endl;
        cout << "DATOS CARGADOS" << endl;
        cout << "**************" << endl;

        codigo += Tam;

        system("PAUSE");
        system("CLS");
    }

    cout << "1. Para ingresar un pasajero" << endl;
    cout << "2. Mostrar pasajeros" << endl;
    cout << "3. Mostrar cupos" << endl;
    cout << "4. Remover pasajero" << endl;
    cout << "5. Ordenar pasajeros" << endl;
    cout << "6. Generar pasabordo" << endl;
    cout << "7. Guardar datos" << endl;
    cout << "-1. Terminar" << endl;
    cin >> opc;

    if (opc == -1)
    {
        system("CLS");

        do
        {
            cout << "Desea guardar los datos antes de salir? [y/n]: ";
            cin >> save;

            switch (save){
                
                case 'y':
                    guardar_datos(pasajeros, Tam);
                    system("CLS");
                    cout << "***************" << endl;
                    cout << "DATOS GUARDADOS" << endl;
                    cout << "***************" << endl;
                    system("PAUSE");
                    return 0;
                    break;
                
                case 'n':
                    system("CLS");
                    cout << "***************" << endl;
                    cout << "Saliendo......." << endl;
                    cout << "***************" << endl;
                    system("PAUSE");
                    return 0;
                    break;
                
                default:
                    cout << "!Ingrese de nuevo!" << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
            }

        }while (save != 'y' || save != 'n');
    }

    while (opc != -1)
    {
        switch (opc)
        {
            case 1:
                if (Tam < 72)
                {
                    leer_pasajero(pasajeros, Tam, codigo);
                    Tam++;
                    codigo++;
                }
                else
                {
                    cout << "!CUPOS DEL AVION TERMINADOS!" << endl;
                }
                break;


            case 2:
                if (Tam >= 1)
                {
                    imprimir_pasajeros(pasajeros, Tam);
                }
                else
                {
                    system("CLS");
                    cout << "AUN NO HAY PASAJEROS" << endl;
                    system("PAUSE");
                }
                break;

            case 3:
                imprimir_cupos();
                cout << "Pasajeros totales: " << Tam << endl;
                system("PAUSE");
                break;

            case 4:
                if (Tam >= 1)
                {
                    remover_pasajero(pasajeros, Tam);
                    Tam--;
                }
                else
                {
                    system("CLS");
                    cout << "AUN NO HAY PASAJEROS" << endl;
                    system("PAUSE");
                }
                break;

            case 5:
                if (Tam >= 1)
                {
                    ordenar_pasajeros(pasajeros, Tam);
                }
                else
                {
                    system("CLS");
                    cout << "AUN NO HAY PASAJEROS" << endl;
                    system("PAUSE");
                }
                break;
            
            case 6:
                pasabordo(pasajeros, Tam);
                break;

            case 7:
                guardar_datos(pasajeros, Tam);
                system("CLS");
                cout << "***************" << endl;
                cout << "DATOS GUARDADOS" << endl;
                cout << "***************" << endl;
                system("PAUSE");
                break;

            default:
                system("CLS");
                cout << "Opcion no valida: Intente de nuevo" << endl;
                system("PAUSE");
                break;
        }

        system("CLS");

        cout << "1. Para ingresar un pasajero" << endl;
        cout << "2. Mostrar pasajeros" << endl;
        cout << "3. Mostrar cupos" << endl;
        cout << "4. Remover pasajero" << endl;
        cout << "5. Ordenar pasajeros" << endl;
        cout << "6. Generar pasabordo" << endl;
        cout << "7. Guardar datos" << endl;
        cout << "-1. Terminar" << endl;
        cin >> opc;

        if (opc == -1)
    {
        system("CLS");

        do
        {
            cout << "Desea guardar los datos antes de salir? [y/n]: ";
            cin >> save;

            switch (save){
                
                case 'y':
                    guardar_datos(pasajeros, Tam);
                    system("CLS");
                    cout << "***************" << endl;
                    cout << "DATOS GUARDADOS" << endl;
                    cout << "***************" << endl;
                    system("PAUSE");
                    return 0;
                    break;
                
                case 'n':
                    system("CLS");
                    cout << "***************" << endl;
                    cout << "Saliendo......." << endl;
                    cout << "***************" << endl;
                    system("PAUSE");
                    return 0;
                    break;
                
                default:
                    cout << "!Ingrese de nuevo!" << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
            }
            
        }while (save != 'y' || save != 'n');
    }
    }


}

void leer_pasajero(Tident pasajeros[], int Tam, int codigo)
{
    system("CLS");

    int validar = 0, fila = 0, vacio = 0, actColumna = 0;

    char columna;

    cout<<"Ingrese nombre: ";
    cin>>pasajeros[Tam].Nombre;

    cout<<"Ingrese apellido: ";
    cin>>pasajeros[Tam].Apellido;

    cout<<"Ingrese Id: ";
    cin>>pasajeros[Tam].Id;

    cout<<"Ingrese edad: ";
    cin>>pasajeros[Tam].Edad;

    while (vacio == 0)
    {
        system("CLS");

        imprimir_cupos();

        while (validar == 0)
        {
            cout<<"Ingrese el numero de la fila: ";
            cin >> fila;

            if (fila > 12)
            {
                cout << "!Ingrese de nuevo la fila!: Solo hay 12" << endl;
            }

            else if (fila < 1)
            {
                cout << "!Ingrese de nuevo la fila!: Numero no valido" << endl;
            }

            else if (fila == 7 && pasajeros[Tam].Edad < 18)
            {
                cout << "!Ingrese de nuevo la fila!: Pasajero menor de edad no puede ir en la fila 7 (Habilitada para emergencias)" << endl;
            }

            else
            {
                validar = 1;
            }
        }

        validar = 0;

        while (validar == 0)
        {
            cout<<"Ingrese la letra de la columna: ";
            cin >> columna;

            if (columna < 65 || columna > 70)
            {
                cout << "!Ingrese de nuevo la columna: Letra no valida (Solo Mayusculas)!" << endl;
            }
            else
            {
                validar = 1;
            }
        }

        validar = 0;

        switch (columna)
        {
            case 'A':
                actColumna = 0;
                break;

            case 'B':
                actColumna = 1;
                break;

            case 'C':
                actColumna = 2;
                break;

            case 'D':
                actColumna = 3;
                break;

            case 'E':
                actColumna = 4;
                break;

            case 'F':
                actColumna = 5;
                break;

        }

        if ((Sillas[fila - 1][actColumna]) == 1)
        {
            cout << "!Ingrese de nuevo el asiento: Asiento ocupado!" << endl;
            system("PAUSE");
        }
        else
        {
            vacio = 1;
        }
    }

    if (vacio == 1)
    {
        pasajeros[Tam].Fila = fila;
        pasajeros[Tam].Columna = columna;
        vacio = 1;
        codigo++;
        pasajeros[Tam].Cod = codigo;
        actualizar_cupo(pasajeros[Tam]);
        vacio = 0;
    }

    if (pasajeros[Tam].Fila < 5){
        cout<<"Su grupo es el: A" << endl;
        pasajeros[Tam].Grupo = 'A';
    }
    else if (pasajeros[Tam].Fila < 9){
        cout<<"Su grupo es el: B" << endl;
        pasajeros[Tam].Grupo = 'B';
    }
    else if (pasajeros[Tam].Fila < 13){
        cout<<"Su grupo es el: C" << endl;
        pasajeros[Tam].Grupo = 'C';
    }

    system("PAUSE");
}

void actualizar_cupos(Tident pasajeros[], int Tam)
{
    int actColumna = 0;

    for (int i = 0; i < Tam; i++)
    {
        switch (pasajeros[i].Columna)
        {
            case 'A':
                actColumna = 0;
                break;

            case 'B':
                actColumna = 1;
                break;

            case 'C':
                actColumna = 2;
                break;

            case 'D':
                actColumna = 3;
                break;

            case 'E':
                actColumna = 4;
                break;

            case 'F':
                actColumna = 5;
                break;

        }

        Sillas[pasajeros[i].Fila - 1][actColumna] = 1;
    }

}

void actualizar_cupo(Tident pasajero)
{
    int actColumna;

    switch (pasajero.Columna)
        {
            case 'A':
                actColumna = 0;
                break;

            case 'B':
                actColumna = 1;
                break;

            case 'C':
                actColumna = 2;
                break;

            case 'D':
                actColumna = 3;
                break;

            case 'E':
                actColumna = 4;
                break;

            case 'F':
                actColumna = 5;
                break;

        }

        Sillas[pasajero.Fila - 1][actColumna] = 1;
}

void imprimir_cupos()
{
    system("CLS");

    cout << "*****************" << endl;

	cout << "     A B C D E F" << endl;

    for (int i = 0; i < 12; i++)
    {
    	if (i + 1 <= 9)
    	{
    		cout << i + 1 << ":   ";
		}
    	else if (i + 1 >= 10)
    	{
    		cout << i + 1 << ":  ";
		}

        for (int j = 0; j < 6; j++)
        {
            cout << Sillas[i][j] << " ";
        }

        int n = (i + 1) % 4;

        if (n == 0)
        {
        	cout << endl;
        	cout << endl;
		}
		else
		{
			cout << endl;
		}
    }

    cout << "*****************" << endl;

    cout << endl;
}

void imprimir_pasajeros(Tident pasajeros[], int Tam)
{
    system("CLS");

    for (int i = 0; i < Tam; i++)
    {
        for (int j = i; j == i; j++)
        {
                    cout << "*******************************" << endl;
                    cout << "Pasajero " << j + 1 << ": " << endl;
                    cout << "Nombre: " << pasajeros[j].Nombre << endl;
                    cout << "Apellido: " << pasajeros[j].Apellido << endl;
                    cout << "ID: " << pasajeros[j].Id << endl;
                    cout << "Edad: " << pasajeros[j].Edad << endl;
                    cout << "Asiento: " << pasajeros[j].Fila << pasajeros[j].Columna << endl;
                    cout << "Codigo: " << pasajeros[j].Cod << endl;
                    cout << "Grupo: " << pasajeros[j].Grupo << endl;
                    cout << "*******************************" << endl;
        }
    }

    system("PAUSE");
}

void guardar_datos(Tident pasajeros[], int Tam)
{
    FILE *escribir = fopen("pasajeros.bin", "wb");

    for (int i = 0; i < Tam; i++)
    {
        fwrite(&pasajeros[i], sizeof(pasajeros[i]), 1, escribir);
    }

    fclose(escribir);

    fstream cupos;

    cupos.open("cupos.txt", ios::out);

    if(cupos.is_open())
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cupos << Sillas[i][j] << " ";
            }
            cupos << endl;
        }
    }

    cupos.close();
}

int cargar_pasajeros(Tident pasajeros[])
{
    Tident tmp;

    int i = 0;

    FILE *leer;

    leer = fopen("pasajeros.bin", "rb");

    if (!(leer == NULL))
    {
        while(!feof(leer))
        {
            fread(&tmp, sizeof(tmp), 1, leer);
            pasajeros[i] = tmp;
            i++;
        }

        actualizar_cupos(pasajeros, i);

        fclose(leer);
    }

    return i;
}

void ordenar_pasajeros(Tident pasajeros[], int Tam)
{
    Tident temp;

    for (int i = 0; i < Tam; i++)
    {
    	for (int j = i; j < Tam; j++)
    	{
            if (pasajeros[i].Fila > pasajeros[j].Fila)
            {
                temp = pasajeros[i];
                pasajeros[i] = pasajeros[j];
                pasajeros[j] = temp;
            }
        }
    }

    system("CLS");

    cout << "*********************" << endl;
    cout << "!Pasajeros Ordenados!" << endl;
    cout << "*********************" << endl;

    system("PAUSE");
}

void pasabordo(Tident pasajeros[], int Tam)
{
    system("CLS");

    int codigo, posicion;

    cout << "******************" << endl;
    cout << "Pasajeros actuales" << endl;
    cout << "******************" << endl;

    for (int i = 0; i < Tam; i++)
    {
        cout << "Pasajero " << i + 1 << ": " << pasajeros[i].Nombre << " " << pasajeros[i].Apellido << " - Cod: " << pasajeros[i].Cod << endl;
    }

    cout << endl;

    cout << "Digite el c�digo del pasajero para generar el pasabordo: ";
    cin >> codigo;

    for (int i = 0; i < Tam; i++)
    {
        if (pasajeros[i].Cod == codigo)
        {
            posicion = i;
        }
    }

    string archivo(pasajeros[posicion].Nombre);

    archivo += ".txt";

    fstream tiquete;

    tiquete.open(archivo, ios::out);

    if(tiquete.is_open())
    {
        tiquete << "       - - - TIQUETE DE ABORDAJE - - -    " << endl;
        tiquete << "Nombre: " << pasajeros[posicion].Nombre << " " << pasajeros[posicion].Apellido << endl;
        tiquete << "Asiento: " << pasajeros[posicion].Fila << pasajeros[posicion].Columna << endl;
        tiquete << "Codigo de reserva: " << pasajeros[posicion].Cod << endl;
        tiquete << "Grupo de abordaje: " << pasajeros[posicion].Grupo << endl;
        tiquete << " - - - TIQUETE GENERADO POR JAVERIANA AIRLINES - - - " << endl;
    }

    tiquete.close();

    system("CLS");

    cout << "******************" << endl;
    cout << "PASABORDO GENERADO" << endl;
    cout << "******************" << endl;

    system("PAUSE");
}

void remover_pasajero(Tident pasajeros[], int Tam)
{
    system("CLS");

    cout << "******************" << endl;
    cout << "Pasajeros actuales" << endl;
    cout << "******************" << endl;

    imprimir_pasajeros(pasajeros, Tam);

    int fila, actColumna, codigo = 0, posicion;

    int encontrado = 0;

    char columna;

	while (encontrado == 0)
	{
		cout << "Digite el codigo de reserva del pasajero a eliminar: ";
    	cin >> codigo;

    	for (int i = 0; i < Tam; i++)
    	{
        	if (pasajeros[i].Cod == codigo)
        	{
            	posicion = i;
            	fila = pasajeros[i].Fila;
            	encontrado = 1;
        	}
    	}

    	if (encontrado == 0)
    	{
    		cout << "ï¿½ERROR! Codigo no encontrado" << endl;
		}
	}


    switch (pasajeros[posicion].Columna)
    {
        case 'A':
            actColumna = 0;
            break;

        case 'B':
            actColumna = 1;
            break;

        case 'C':
            actColumna = 2;
            break;

        case 'D':
            actColumna = 3;
            break;

        case 'E':
            actColumna = 4;
            break;

        case 'F':
            actColumna = 5;
            break;
    }

    for (int i = posicion; i < Tam; i++)
    {
        pasajeros[i] = pasajeros[i+1];
    }

    system("CLS");
    cout << "!PASAJERO ELIMINADO CON EXITO!" << endl;
    system("PAUSE");

    Sillas[fila - 1][actColumna] = 0;
}
