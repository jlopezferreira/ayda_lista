#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <typename T>
class Lista
{
private:
    // Definicion de estructura
    struct Nodo {
        T elemento;
        Nodo * siguiente;
    };
    // Atributos de clase
    Nodo * puntero_lista;
    // Métodos auxiliares
    void vaciar();
    void inicLista(T elemento);
public:
    Lista();
    ~Lista();
    void agregarLista(int pos, T elemento);
    int longLista();
    bool eliminarLista(int pos);
    T recuperarLista(int pos);
};
#endif // LISTA_H_INCLUDED
