#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    // Carga datos
    int num;
    cout << "Ingrese numero: " << endl;
    cin >> num;
    for (int i = 1; i <= num; i++)
        lista.agregarLista(i, i * 10);
    // Recorre, muestra y elimina
    int index = 1;
    cout << "Lista: " << endl;
    while (lista.longLista() > 0 && index < lista.longLista()) {
        cout << "Elemento " << index << ": " << lista.recuperarLista(index) << endl;
        index++;
    }
    lista.eliminarLista(num/2);
    index = 1;
    cout << "Lista: " << endl;
    while (lista.longLista() > 0 && index < lista.longLista()) {
        cout << "Elemento " << index << ": " << lista.recuperarLista(index) << endl;
        index++;
    }
    return 0;
}
