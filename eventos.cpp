#include <iostream>
using namespace std;

#define MAXF 10
#define MAXC 12

 int asientos[MAXF][MAXC];

struct evento {
    string nombre;
    int tipo;      // 1 = concierto, 2 = teatro, 3 = festival, 4 = charlas
    string fecha;
    int zona;      // 1 = zona a, 2 = zona b, 3 = vip
    int asientosDisp[3];  // disponibles por zona: [zona a, zona b, vip]
    bool mas18;
};
const int MAX_EVENTOS = 100;
evento listaEventos[MAX_EVENTOS];
int numEventos = 0;  // contador de eventos


void mostrarEventos() {
    if (numEventos == 0) {
        cout << "\nno hay eventos registrados.\n";
    } else {
        cout << "\n--- lista de eventos ---" << endl;
        for (int i = 0; i < numEventos; i++) {
            cout << "evento " << (i + 1) << ":" << endl;
            cout << "nombre: " << listaEventos[i].nombre << endl;
            cout << "fecha: " << listaEventos[i].fecha << endl;
            cout << "tipo: " << listaEventos[i].tipo << endl;
            cout << "zona a: " << listaEventos[i].asientosDisp[0] << " asientos disponibles" << endl;
            cout << "zona b: " << listaEventos[i].asientosDisp[1] << " asientos disponibles" << endl;
            cout << "vip: " << listaEventos[i].asientosDisp[2] << " asientos disponibles" << endl;

            // en lugar del operador ternario uso if-else
            if (listaEventos[i].mas18) {
                cout << "mayor de 18 años: sí" << endl;
            } else {
                cout << "mayor de 18 años: no" << endl;
            }
            cout << "---------------------------\n";
        }
    }
}

void funcionFinal() {
    int opcion;
    cout << "\ndesea salir?: presione la opción de su preferencia: " << endl;
    cout << "1. volver al menú principal" << endl;
    cout << "2. salir del programa" << endl;
    cin >> opcion;

    if (opcion != 1 && opcion != 2) {
        cout << "opción inválida" << endl;
    } else if (opcion == 2) {
        exit(0);  // termina el programa
    }
}

void busqFecha(string fecha) {
    bool encontrado = false;
    for (int i = 0; i < numEventos; i++) {
        if (listaEventos[i].fecha == fecha) {
            cout << "nombre: " << listaEventos[i].nombre << ", tipo: " << listaEventos[i].tipo << ", zona: " << listaEventos[i].zona << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "no existe un evento en esa fecha." << endl;
    }
}

void busqTipo(int tipo) {
    bool encontrado = false;
    for (int i = 0; i < numEventos; i++) {
        if (listaEventos[i].tipo == tipo) {
            cout << "nombre: " << listaEventos[i].nombre << ", fecha: " << listaEventos[i].fecha << ", zona: " << listaEventos[i].zona << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "no existe un evento de ese tipo." << endl;
    }
}

void inicializarAsientos() {
    for (int i = 0; i < MAXF; i++) {
        for (int j = 0; j < MAXC; j++) {
            asientos[i][j] = 'O';  // todos los asientos disponibles
        }
    }
}

void mostrarAsientos() {
    cout << "\nmapa de asientos (O = disponible, X = ocupado):\n";
    for (int i = 0; i < MAXF; i++) {
        for (int j = 0; j < MAXC; j++) {
            cout << asientos[i][j] << " ";  
        }
        cout << endl;
    }
}

void reservarAsiento() {
    int fila, columna;
    cout << "\n--- reservar asiento ---" << endl;
    mostrarAsientos();

    cout << "ingrese la fila del asiento que desea reservar (0-9): ";
    cin >> fila;
    cout << "ingrese la columna del asiento que desea reservar (0-11): ";
    cin >> columna;

    if (asientos[fila][columna] == 'O') {
        asientos[fila][columna] = 'X';  // marcar asiento como ocupado
        cout << "asiento reservado con éxito.\n";
    } else {
        cout << "el asiento ya está ocupado. elija otro asiento.\n";
    }
    mostrarAsientos();
}

void crearEvento() {
    if (numEventos >= MAX_EVENTOS) {
        cout << "no se pueden agregar más eventos. límite alcanzado." << endl;
        return;
    }

    evento nuevoEvento;

    cout << "ingrese el nombre del evento (máximo 50 caracteres): ";
    cin >> nuevoEvento.nombre;

    cout << "ingrese el tipo de evento (1. concierto, 2. teatro, 3. festival, 4. charla): ";
    cin >> nuevoEvento.tipo;

    cout << "ingrese la fecha del evento (formato DD/MM/YYYY): ";
    cin >> nuevoEvento.fecha;

    cout << "ingrese los asientos disponibles para cada zona (a, b, vip):" << endl;
    cout << "zona a: "; cin >> nuevoEvento.asientosDisp[0];
    cout << "zona b: "; cin >> nuevoEvento.asientosDisp[1];
    cout << "vip: "; cin >> nuevoEvento.asientosDisp[2];

    cout << "¿es un evento solo para mayores de 18 años? (1 = sí, 0 = no): ";
    cin >> nuevoEvento.mas18;

    listaEventos[numEventos] = nuevoEvento;
    numEventos++;
    cout << "evento añadido exitosamente.\n";
}

void menuPrincipal() {
    int opciona, opcionb;
    do {
        cout << "\nbienvenido a eventos.com" << endl;
        cout << "menú principal: " << endl;
        cout << "1. mostrar todos los eventos" << endl;
        cout << "2. mostrar eventos por tipo" << endl;
        cout << "3. mostrar eventos +18" << endl;
        cout << "4. buscar eventos por fecha" << endl;
        cout << "5. mostrar mapa de asientos" << endl;
        cout << "6. comprar entrada" << endl;
        cout << "7. reservar asiento" << endl;
        cout << "8. calcular asientos disponibles" << endl;
        cout << "9. añadir nuevo evento" << endl;
        cout << "10. eliminar evento" << endl;
        cout << "11. salir del programa" << endl;
        cin >> opciona;

        switch (opciona) {
            case 1:
                mostrarEventos();
                break;

            case 2: {
                cout << "digite el tipo de evento (1. concierto, 2. teatro, 3. festival, 4. charlas): ";
                cin >> opcionb;
                busqTipo(opcionb);
                break;
            }

            case 3:
                for (int i = 0; i < numEventos; i++) {
                    if (listaEventos[i].mas18) {
                        cout << "nombre: " << listaEventos[i].nombre << endl;
                    }
                }
                break;

            case 4: {
                string fecha;
                cout << "digite la fecha (DD/MM/YYYY): ";
                cin >> fecha;1

                busqFecha(fecha);
                break;
            }

            case 5:
                mostrarAsientos();
                break;

            case 6:
                cout << "función de compra pendiente." << endl;
                break;

            case 7:
                reservarAsiento();
                break;

            case 8:
                cout << "función de cálculo de asientos disponible pendiente." << endl;
                break;

            case 9:
                crearEvento();
                break;

            case 10:
                cout << "función de eliminar evento pendiente." << endl;
                break;

            case 11:
                exit(1);
        }
        funcionFinal();
    } while (opciona != 11);
}


int main() {
    inicializarAsientos();
    menuPrincipal();
    return 0;
}
