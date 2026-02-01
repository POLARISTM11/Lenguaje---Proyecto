// Lenguaje - Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>

#define FILAS 7
#define COLUMNAS 6

using namespace std;

// --- PARTE 1: GESTIÓN DE MEMORIA (Fernando) ---
string** crearMatriz() {
    string** matriz = new string * [FILAS];
    for (int hora = 0; hora < FILAS; hora++) {
        matriz[hora] = new string[COLUMNAS];
    }
    return matriz;
}

void inicializar(string** matriz) {
    for (int hora = 0; hora < FILAS; hora++) {
        for (int dia = 0; dia < COLUMNAS; dia++) {
            matriz[hora][dia] = "---";
        }
    }
}

void liberarMemoria(string** matriz) {
    for (int hora = 0; hora < FILAS; hora++) {
        delete[] matriz[hora];
    }
    delete[] matriz;
}

// --- PARTE 2: REGISTRO (XAVI) ---
string* buscarEspacio(string** matriz, int fila, int columna) {
    return &matriz[fila][columna];
}

void registrarCurso(string** matriz) {
    int fila, columna;
    string nombre;
    cout << "\n--- Registrar Curso ---" << endl;
    cout << "Ingrese bloque horario (0-6): "; cin >> fila;
    cout << "Ingrese dia (0-5): "; cin >> columna;

    if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS) {
        cout << "Nombre del curso: ";
        cin.ignore();
        getline(cin, nombre);

        string* celda = buscarEspacio(matriz, fila, columna);
        *celda = nombre;
        cout << "¡Curso registrado con exito!" << endl;
    }
    else {
        cout << "Error: Indices fuera de rango." << endl;
    }
}

// --- PARTE 3: REPORTES (Kevin) ---
void MostrarHorarioCompleto(string** Horario, int HorasTotales, int DiasTotales) {
    string DiasSemana[6] = { "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };

    cout << "\n\t==================== Horario Completo ====================\n";
    cout << "\tHora\tLunes\tMartes\tMierc.\tJueves\tViern.\tSabado\n";
    cout << "\t----------------------------------------------------------\n";

    for (int hora = 0; hora < HorasTotales; hora++) {
        cout << "\t" << (hora + 8) << ":00\t";
        for (int dia = 0; dia < DiasTotales; dia++) {
            cout << Horario[hora][dia] << "\t";
        }
        cout << "\n";
    }
    cout << "\t==========================================================\n";
}

// --- PARTE 4: PROCESAMIENTO (Haylie) ---
void contar_horas(string** matriz, int filas, int columnas) {
    string buscar;
    int contador = 0;

    cout << "\n¿De que curso quieres contar las horas?: ";
    cin.ignore();
    getline(cin, buscar);

    for (int hora = 0; hora < filas; hora++) {
        for (int dia = 0; dia < columnas; dia++) {
            if (matriz[hora][dia] == buscar) {
                contador++;
            }
        }
    }
    cout << "Resultado: " << buscar << " tiene " << contador << " horas." << endl;
}

// --- MAIN ---
int main() {
    string** horarioPrincipal = crearMatriz();
    inicializar(horarioPrincipal);

    int opcion;
    do {
        cout << "\n>>> SISTEMA CHRONO CLASS <<<\n";
        cout << "1. Registrar Curso\n2. Ver Horario Completo\n3. Contar Horas\n4. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: registrarCurso(horarioPrincipal); break;
        case 2: MostrarHorarioCompleto(horarioPrincipal, FILAS, COLUMNAS); break;
        case 3: contar_horas(horarioPrincipal, FILAS, COLUMNAS); break;
        case 4: cout << "Saliendo..."; break;
        }
    } while (opcion != 4);

    liberarMemoria(horarioPrincipal);
    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
