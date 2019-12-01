#ifndef PRIORITYNODE_H
#define PRIORITYNODE_H

#include "Queue.h"

class PriorityNode {

private:

    Queue* queue;
    PriorityNode* next;
    PriorityNode* previous;
    int priority;
public:

    PriorityNode(){
        this->queue = nullptr;
        this->next = this->previous = nullptr;
    }

    PriorityNode(Queue* queue, int priority){
        this->priority = priority;
        this->queue = queue;
        this->next = this->previous = nullptr;
    }

    Queue* getQueue() {
        return this->queue;
    }

    void setQueue(Queue* queue) {
        this->queue = queue;
    }

    PriorityNode *getNext() {
        return this->next;
    }

    void setNext(PriorityNode *next) {
        this->next = next;
    }

    PriorityNode *getPrevious() {
        return this->previous;
    }

    void setPrevious(PriorityNode *previous) {
        this->previous = previous;
    }

    int getPriority() {
        return this->priority;
    }

    void setPriority(int priority) {
        this->priority = priority;
    }
};

#endif
