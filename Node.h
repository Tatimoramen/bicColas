#ifndef NODE_H
#define NODE_H
class Node {

private:

    int data;
    Node* next;
    Node* previous;

public:

    Node(){
        this->data = 0;
        this->next = this->previous = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = this->previous = nullptr;
    }

    int getData() {
        return this->data;
    }

    void setData(int data) {
        this->data = data;
    }

    Node *getNext() {
        return this->next;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    Node *getPrevious() {
        return this->previous;
    }

    void setPrevious(Node *previous) {
        this->previous = previous;
    }
};
#endif
