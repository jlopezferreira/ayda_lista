#include <iostream>
#include "Lista.h"

// Constructor
template <typename T>
Lista<T>::Lista()
{
    puntero_lista = NULL;
}

// Destructor
template <typename T>
Lista<T>::~Lista()
{
    vaciar();
}

template <typename T>
void Lista<T>::agregarLista(int pos, T elemento)
{
    if (puntero_lista == NULL) {
        inicLista(elemento);
        return;
    }
    int ctrl_pos = 1;
    Nodo * cursor = puntero_lista;
    Nodo * anterior = NULL;
    while (ctrl_pos < pos) {
        anterior = cursor;
        cursor = cursor->siguiente;
        ctrl_pos++;
    }
    Nodo * nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->siguiente = cursor;
    if (anterior == puntero_lista)
        puntero_lista->siguiente = nuevo;
    else
        anterior->siguiente = nuevo;
}

template <typename T>
int Lista<T>::longLista() {
    Nodo * cursor = puntero_lista;
    int contador = 0;

    while (cursor != NULL) {
        contador++;
        cursor = cursor->siguiente;
    }
    return contador;
}

template <typename T>
T Lista<T>::recuperarLista(int pos)
{
    int ctrl_pos = 1;
    Nodo * cursor = puntero_lista;

    while (cursor != NULL) {
        if (ctrl_pos == pos)
            return cursor->elemento;
        cursor = cursor->siguiente;
        ctrl_pos++;
    }
}

template <typename T>
bool Lista<T>::eliminarLista(int pos)
{
    bool is_deleted = false;
    int ctrl_pos = 1;
    if (puntero_lista != NULL) {
        Nodo * cursor = puntero_lista;
        Nodo * anterior = NULL;
        while (cursor != NULL && !is_deleted) {
            if (ctrl_pos == pos) {
                if (anterior != NULL)
                    anterior->siguiente = cursor->siguiente;
                is_deleted = true;
            }
            anterior = cursor;
            cursor = cursor->siguiente;
            ctrl_pos++;
        }
        if (anterior == puntero_lista)
            puntero_lista = NULL;
        if (is_deleted)
            delete anterior;
    }
    return is_deleted;
}

// Método auxiliar
template <typename T>
void Lista<T>::vaciar()
{
    Nodo * aux;
    while (puntero_lista != NULL) {
        aux = puntero_lista->siguiente;
        delete puntero_lista;
        puntero_lista = aux;
    }
    puntero_lista = NULL;
}

template <typename T>
void Lista<T>::inicLista(T elemento)
{
    if (puntero_lista == NULL) {
        Nodo * nuevo = new Nodo;
        nuevo->elemento = elemento;
        nuevo->siguiente = NULL;
        puntero_lista = nuevo;
    }
}

template class Lista<int>;
