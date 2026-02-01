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
    for (int i = 0; i < FILAS; i++) {
        matriz[i] = new string[COLUMNAS];
    }
    return matriz;
}

void inicializar(string** matriz) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = "---";
        }
    }
}

void liberarMemoria(string** matriz) {
    for (int i = 0; i < FILAS; i++) {
        delete[] matriz[i];
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
        cout << "Nombre del curso (una sola palabra): ";
        cin >> nombre;
        string* punteroCelda = buscarEspacio(matriz, fila, columna);
        *punteroCelda = nombre;
        cout << " ¡Curso registrado con exito! " << endl;
    }
    else {
        cout << " Error: Indices fuera de rango. " << endl;
    }
}

// --- PARTE 3: REPORTES (Kevin) ---
void MostrarHorarioCompleto(string** Horario, int HorasTotales, int DiasTotales) {
    string DiasSemana[6] = { "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };
    int anchoColumna = 10;

    cout << "\n\t=======================================Horario Completo====================================================\n";
    cout << "\tHora\t";

    for (int dias = 0; dias < DiasTotales; dias++) {
        string nombreDia = DiasSemana[dias]; // Corregido 'd' por 'dias'
        int espacios = anchoColumna - nombreDia.length();
        cout << nombreDia;
        for (int espacio = 0; espacio < espacios; espacio++) cout << " ";
        cout << "\t";
    }
    cout << "\n\t-------------------------------------------------------------------------------------------------------";
    cout << "\n";

    for (int fila = 0; fila < HorasTotales; fila++) {
        cout << "\t" << (fila + 16) << ":00\t";

        for (int columna = 0; columna < DiasTotales; columna++) {
            string curso = Horario[fila][columna];
            int espaciosCurso = anchoColumna - curso.length();

            cout << curso;
            for (int espacio = 0; espacio < espaciosCurso; espacio++) cout << " ";
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "\n\t===========================================================================================================\n";
}

void MostrarDia(string** Horario, int Horas, int Dias) {
    int Dia;
    string DiasSemana[6] = { "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado" };

    do {
        cout << "\n\tIngrese dia (1=Lunes ... " << Dias << "=Sabado): ";
        cin >> Dia;
        if (Dia < 1 || Dia > Dias) {
            cout << "\tDia invalido, porfabor vuelva a ingresar el numero dentro del rango.\n";
        }
    } while (Dia < 1 || Dia > Dias);

    cout << "\n\tClases de " << DiasSemana[Dia - 1] << ":\n";
    for (int hora = 0; hora < Horas; hora++) {
        cout << "\t" << (hora + 16) << ":00 - " << Horario[hora][Dia - 1] << "\n";
    }
}

// --- PARTE 4: PROCESAMIENTO (Haylie)---
void contar_horas(string** matriz) {
    string buscar;
    int contador = 0;
    cout << "\n¿De que curso quieres contar las horas?: ";
    cin >> buscar;

    for (int hora = 0; hora < FILAS; hora++) {
        for (int dia = 0; dia < COLUMNAS; dia++) {
            if (matriz[hora][dia] == buscar) {
                contador++;
            }
        }
    }
    cout << "Resultado: " << buscar << " tiene " << contador << " horas." << endl;
}

// Programa Principal 
int main() {
    string** horarioPrincipal = crearMatriz();
    inicializar(horarioPrincipal);

    int opcion;
    do {
        cout << "\n>>> SISTEMA CHRONO CLASS <<<" << endl;
        cout << "1. Registrar Curso" << endl;
        cout << "2. Ver Horario Completo" << endl;
        cout << "3. Ver Clases por Dia" << endl;
        cout << "4. Contar Horas de un Curso" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: registrarCurso(horarioPrincipal); break;
        case 2: MostrarHorarioCompleto(horarioPrincipal, FILAS, COLUMNAS); break;
        case 3: MostrarDia(horarioPrincipal, FILAS, COLUMNAS); break;
        case 4: contar_horas(horarioPrincipal); break;
        case 5: cout << "Saliendo y liberando memoria..."; break;
        }
    } while (opcion != 5);

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
