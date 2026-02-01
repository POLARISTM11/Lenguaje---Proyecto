// Lenguaje - Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>

#define FILAS 7
#define COLUMNAS 6

using namespace std;

// --- PARTE 1: MEMORIA ---
string** crearMatriz() {
    string** matriz = new string * [FILAS];
    for (int i = 0; i < FILAS; i++) matriz[i] = new string[COLUMNAS];
    return matriz;
}

void inicializar(string** matriz) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) matriz[i][j] = "---";
    }
}

// --- PARTE 2: REGISTRO (XAVI) ---
string* buscarEspacio(string** matriz, int f, int c) {
    return &matriz[f][c];
}

void registrarCurso(string** matriz) {
    int f, c;
    string nombre;
    cout << "\n--- Registrar Curso ---\n";
    cout << "Bloque (0-6): "; cin >> f;
    cout << "Dia (0-5): "; cin >> c;

    if (f >= 0 && f < FILAS && c >= 0 && c < COLUMNAS) {
        cout << "Nombre del curso: ";
        cin.ignore(); // LIMPIEZA: Quita el 'enter' anterior
        getline(cin, nombre); // SOLUCIÓN: Permite nombres con espacios

        string* celda = buscarEspacio(matriz, f, c);
        *celda = nombre;
        cout << "¡Registrado con exito!\n";
    }
    else cout << "Error: Fuera de rango.\n";
}

// --- PARTE 3: REPORTES (KEVIN) ---
void MostrarHorarioCompleto(string** Horario) {
    string dias[6] = { "Lun", "Mar", "Mie", "Jue", "Vie", "Sab" };
    cout << "\n\tHORA\t";
    for (int i = 0; i < 6; i++) cout << dias[i] << "\t";
    cout << "\n\t--------------------------------------------------\n";

    for (int i = 0; i < FILAS; i++) {
        // CAMBIO: (+8) para que empiece a las 8:00 AM
        cout << "\t" << (i + 8) << ":00\t";
        for (int j = 0; j < COLUMNAS; j++) cout << Horario[i][j] << "\t";
        cout << endl;
    }
}

// --- PARTE 4: PROCESAMIENTO (HAYLIE) ---
void contar_horas(string** matriz) {
    string buscar;
    int contador = 0;
    cout << "\n¿Curso a contar?: ";
    cin.ignore(); // LIMPIEZA: Evita que se salte la pregunta
    getline(cin, buscar);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == buscar) contador++;
        }
    }
    cout << "Resultado: [" << buscar << "] tiene " << contador << " bloque(s).\n";
}

int main() {
    string** horarioPrincipal = crearMatriz();
    inicializar(horarioPrincipal);

    int opcion;
    do {
        cout << "\n>>> CHRONO CLASS <<<\n1. Registrar\n2. Ver Todo\n3. Contar\n4. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1: registrarCurso(horarioPrincipal); break;
        case 2: MostrarHorarioCompleto(horarioPrincipal); break;
        case 3: contar_horas(horarioPrincipal); break;
        }
    } while (opcion != 4);

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
