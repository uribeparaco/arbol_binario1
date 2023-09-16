#include <iostream>

struct nodo {
    int valor;
    nodo* izquierda;
    nodo* derecha;

    nodo(int val) : valor(val), izquierda(NULL), derecha(NULL) {}
};

nodo* insertar(nodo* raiz, int valor) {
    if (raiz == NULL) {
        return new nodo(valor);
    } else {
        if (valor <= raiz->valor) {
            raiz->izquierda = insertar(raiz->izquierda, valor);
        } else {
            raiz->derecha = insertar(raiz->derecha, valor);
        }
        return raiz;
    }
}

void imprimirEnOrden(nodo* raiz) {
    if (raiz != NULL) {
        imprimirEnOrden(raiz->izquierda);
        std::cout << raiz->valor << " ";
        imprimirEnOrden(raiz->derecha);
    }
}

void menu() {
    nodo* raiz = NULL;
    int opcion;

    do {
    	std::cout << "MENU:" << std::endl;
        std::cout << "(1). INSERTAR NODO" << std::endl;
        std::cout << "(2). IMPRIMIR ARBOL EN ORDEN" << std::endl;
        std::cout << "(3). SALIR" << std::endl;
        std::cout << "INGRESE UNA DE LAS OPCIONES: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                std::cout << "Ingrese el valor del nodo a insertar: ";
                std::cin >> valor;
                raiz = insertar(raiz, valor);
                break;
            }
            case 2:
                std::cout << "EL ARBOL EN ORDEN: ";
                imprimirEnOrden(raiz);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "SALIR DEL PROGRAMA." << std::endl;
                break;
            default:
                std::cout << "OPCION NO VALIDAD, INTENTE DE NUEVO REY." << std::endl;
                break;
        }

    } while (opcion != 3);
}

int main() {
    menu();
    return 0;
}

