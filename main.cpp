#include <iostream>

using namespace std;

#include "PriorityQueue.h"

int getMenu();

int getOption();

void insert(PriorityQueue *priorityQueue);

int main() {
    PriorityQueue *priorityQueue = new PriorityQueue();
    bool exit = false;
    do {
        system("cls");
        int option = getMenu();
        switch (option) {
            case 1: {
                priorityQueue->printPriorityQueue();
                system("pause");
            }
                break;
            case 2:
                insert(priorityQueue);
                system("pause");
                break;
            case 3:
                priorityQueue->pop();
                priorityQueue->printPriorityQueue();
                system("pause");
                break;
            case 4:{
                PriorityNode* priorityHead = priorityQueue->getHead();
                Node* head = priorityHead->getQueue()->getHead();
                cout << "El dato de primero es " << head->getData() << endl;
                system("pause");
            }
                break;
            case 5:{
                PriorityNode* priorityLast = priorityQueue->getLast();
                Node* last = priorityLast->getQueue()->getLast();
                cout << "El dato de ultimo es " << last->getData() << endl;
                system("pause");
            }
                break;
            case 6:
                exit = true;
        }

    } while (!exit);
    return 0;
}

void insert(PriorityQueue *priorityQueue) {
    int priority = 0, data = 0;
    do {
        cout << "\nIngrese una prioridad de 1 a N" << endl;
        cin >> priority;
        if(priority < 1){
            cout << "No se permite el numero de prioridad " << priority << endl;
        }
    }while(priority < 1);

    cout << "Ingrese el dato a poner en cola" << endl;
    cin >> data;
    Node *node = new Node(data);
    priorityQueue->pushNode(node, priority);
    cout << "\n\n\tSe ha insertado un nuevo nodo" << endl;
}

int getMenu() {
    cout << "\t**** MENU ****" << endl
         << "1- Mostrar cola" << endl
         << "2- Insertar nodo con Prioridad" << endl
         << "3- Eliminar primero" << endl
         << "4- Mostrar Primero" << endl
         << "5- Mostrar Ultimo" << endl
         << "6- Salir" << endl
         << "Opcion:  ";

    return getOption();
}

int getOption() {
    int option = 0;
    cin >> option;
    return option;
}

