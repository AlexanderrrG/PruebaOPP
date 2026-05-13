#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm> 
using namespace std;

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    string nombre = "";
    float notas[5], suma = 0, promedio = 0;
    float notaMayor, notaMenor;
    int opcion;
    const string AUTOR = "Alexander Guaman";

    do {
        limpiarPantalla();
        cout << "========================================" << endl;
        cout << "   SISTEMA ACADEMICO - " << AUTOR << endl;
        cout << "========================================" << endl;
        cout << " 1. Operaciones Aritmeticas" << endl;
        cout << " 2. Registrar Estudiante y Analizar Notas" << endl;
        cout << " 3. GUARDAR RESULTADOS EN TXT" << endl;
        cout << " 4. Salir" << endl;
        cout << "========================================" << endl;
        cout << " Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                limpiarPantalla();
                float a, b;
                cout << "--- 1. OPERACIONES ARITMETICAS ---" << endl;
                cout << "Ingrese valor A: "; cin >> a;
                cout << "Ingrese valor B: "; cin >> b;
                cout << "Suma: " << a + b << " | Resta: " << a - b << endl;
                cout << "Mult: " << a * b << " | Div: " << (b != 0 ? a/b : 0) << endl;
                system("pause");
                break;
            }

            case 2: {
                limpiarPantalla();
                cout << "--- 2. REGISTRO Y ANALISIS ---" << endl;
                cout << "Nombre del Estudiante: ";
                cin.ignore();
                getline(cin, nombre);

                suma = 0;
                for(int i = 0; i < 5; i++) {
                    cout << "Nota " << i + 1 << ": ";
                    cin >> notas[i];
                    suma += notas[i];

                    // Lógica para mayor y menor
                    if(i == 0) {
                        notaMayor = notaMenor = notas[i];
                    } else {
                        if(notas[i] > notaMayor) notaMayor = notas[i];
                        if(notas[i] < notaMenor) notaMenor = notas[i];
                    }
                }

                promedio = suma / 5;

                cout << "\n---------- ANALISIS ACADEMICO ----------" << endl;
                cout << " ESTUDIANTE: " << nombre << endl;
                cout << " PROMEDIO:   " << fixed << setprecision(2) << promedio << endl;
                cout << " NOTA MAYOR: " << notaMayor << endl;
                cout << " NOTA MENOR: " << notaMenor << endl;
                cout << " ESTADO:     " << (promedio >= 7 ? "APROBADO" : "REPROBADO") << endl;
                cout << "----------------------------------------" << endl;
                system("pause");
                break;
            }

            case 3: {
                limpiarPantalla();
                if (nombre == "") {
                    cout << "!!! Error: No hay datos procesados." << endl;
                } else {
                    ofstream archivo;
                    archivo.open("resultados.txt", ios::app);

                    if (archivo.is_open()) {
                        archivo << "========================================" << endl;
                        archivo << "ESTUDIANTE: " << nombre << endl;
                        archivo << "PROMEDIO:   " << fixed << setprecision(2) << promedio << endl;
                        archivo << "NOTA MAX:   " << notaMayor << " | NOTA MIN: " << notaMenor << endl;
                        archivo << "ESTADO:     " << (promedio >= 7 ? "APROBADO" : "REPROBADO") << endl;
                        archivo << "REGISTRADO POR: " << AUTOR << endl;
                        archivo << "========================================" << endl;
                        archivo.close();

                        cout << ">> EXITOSO: Datos guardados en resultados.txt" << endl;
                    } else {
                        cout << "!!! Error al abrir el archivo." << endl;
                    }
                }
                system("pause");
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}
