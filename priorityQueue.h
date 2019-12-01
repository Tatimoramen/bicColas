#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "PriorityNode.h"

class PriorityQueue {
private:
    PriorityNode *head;
    PriorityNode *last;
    int length;
public:

    PriorityQueue() {
        this->head = this->last = nullptr;
        this->length = 0;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    void push(PriorityNode *priorityNode) {
        if (!this->isEmpty()) {
            last->setNext(priorityNode);
            priorityNode->setPrevious(last);
            last = priorityNode;
        } else {
            head = last = priorityNode;
        }
        this->sort();
        length++;
    }

    void *pop() {
        if (!this->isEmpty()) {
            PriorityNode *aux = this->head;
            Queue* queue = aux->getQueue();
            queue->pop();
            if(queue->isEmpty()){
                if (this->last == this->head) {
                    this->head = this->last = nullptr;
                } else {
                    this->head = this->head->getNext();
                }
                length--;
                delete aux;
            }
        }
        return nullptr;
    }

    void pushNode(Node* node, int priority){
        bool founded = false;
        if(!this->isEmpty()){
            PriorityNode* aux = this->head;
            while(aux){
                if(aux->getPriority() == priority){
                    aux->getQueue()->push(node);
                    founded = true;
                    break;
                }
                aux = aux->getNext();
            }
            if(!founded){
                createPriority(node, priority);
            }
            this->sort();
        } else {
            createPriority(node, 1);
        }
    }

    void createPriority(Node *node, int priotity) {
        Queue* queue = new Queue();
        queue->push(node);
        PriorityNode* priorityNode = new PriorityNode(queue, priotity);
        this->push(priorityNode);
    }

    void printPriorityQueue(){
        if(!this->isEmpty()){
            PriorityNode* aux = this->head;
            int cola = 1;
            while(aux){
                cout << "\n--------------------------------------\n";
                cout << "Prioridad " << aux->getPriority() << endl << endl;
                Queue* queue = aux->getQueue();
                queue->printQueue();
                cout << "\nFin de la prioridad " << aux->getPriority() << endl << endl;
                cout << "\n--------------------------------------\n";
                cola++;
                aux = aux->getNext();
            }
        } else {
            cout << "\nNo hay nada en cola de prioridades\n\n";
        }
    }

    void sort(){
        if( !this->isEmpty() ) {
            PriorityNode* aux = this->head;
            while(aux->getNext()) {
                PriorityNode* next = aux->getNext();
                while(next) {
                    if( aux->getPriority() > next->getPriority()) {
                        Queue* queue = next->getQueue();
                        int priority = next->getPriority();
                        next->setQueue( aux->getQueue() );
                        next->setPriority( aux->getPriority() );
                        aux->setQueue( queue );
                        aux->setPriority( priority );
                    }
                    next = next->getNext();
                }
                aux = aux->getNext();
                next = aux->getNext();
            }
        }
    }

    PriorityNode *getHead() {
        return this->head;
    }

    PriorityNode *getLast() {
        return this->last;
    }

    int getLength() {
        return this->length;
    }
};
#endif
