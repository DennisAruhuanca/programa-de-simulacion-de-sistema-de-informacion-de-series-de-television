#include <iostream>
#include <string>
using namespace std;

struct Serie {
    string nombre;
    string genero;
    int numTemporadas;
    int numEpisodios;
};

Serie series[100]; // Array to store series
int numSeries = 0; // Number of series

void agregarSerie() {
    if (numSeries < 100) {
        cout << "Ingrese el nombre de la serie: ";
        cin.ignore();
        getline(cin, series[numSeries].nombre);
        cout << "Ingrese el género de la serie: ";
        getline(cin, series[numSeries].genero);
        cout << "Ingrese el número de temporadas: ";
        cin >> series[numSeries].numTemporadas;
        cout << "Ingrese el número de episodios: ";
        cin >> series[numSeries].numEpisodios;
        numSeries++;
        cout << "Serie agregada con éxito!" << endl;
    } else {
        cout << "No se pueden agregar más series." << endl;
    }
}

void mostrarSeries() {
    cout << "Series agregadas:" << endl;
    for (int i = 0; i < numSeries; i++) {
        cout << "Nombre: " << series[i].nombre << endl;
        cout << "Género: " << series[i].genero << endl;
        cout << "Temporadas: " << series[i].numTemporadas << endl;
        cout << "Episodios: " << series[i].numEpisodios << endl;
        cout << "------------------------" << endl;
    }
}

void buscarSerie() {
    string nombre;
    cout << "Ingrese el nombre de la serie a buscar: ";
    cin.ignore();
    getline(cin, nombre);
    bool encontrada = false;
    for (int i = 0; i < numSeries; i++) {
        if (series[i].nombre == nombre) {
            cout << "Serie encontrada:" << endl;
            cout << "Nombre: " << series[i].nombre << endl;
            cout << "Género: " << series[i].genero << endl;
            cout << "Temporadas: " << series[i].numTemporadas << endl;
            cout << "Episodios: " << series[i].numEpisodios << endl;
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "Serie no encontrada." << endl;
    }
}

void eliminarSerie() {
    string nombre;
    cout << "Ingrese el nombre de la serie a eliminar: ";
    cin.ignore();
    getline(cin, nombre);
    bool encontrada = false;
    for (int i = 0; i < numSeries; i++) {
        if (series[i].nombre == nombre) {
            for (int j = i; j < numSeries - 1; j++) {
                series[j] = series[j + 1];
            }
            numSeries--;
            encontrada = true;
            cout << "Serie eliminada con éxito!" << endl;
            break;
        }
    }
    if (!encontrada) {
        cout << "Serie no encontrada." << endl;
    }
}

int main() {
    int opcion;
    
    cout<<"Prueba de colaboracion\n\n";
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Agregar serie" << endl;
        cout << "2. Mostrar series" << endl;
        cout << "3. Buscar serie" << endl;
        cout << "4. Eliminar serie" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                agregarSerie();
                break;
            case 2:
                mostrarSeries();
                break;
            case 3:
                buscarSerie();
                break;
            case 4:
                eliminarSerie();
                break;
            case 5:
                cout << "Adiós!" << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 5);
    return 0;
}