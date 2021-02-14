#include "node.h"

class LinkedList{
    public:
        int currentSize;
        Node* head;
        LinkedList();
        bool isEmpty();
        bool contains(int data);
        void addLast(int data);
        void addFirst(int data);
        void addAt(int index, int data);
        void removeLast();
        void removeFirst();
        void removeAt(int index);
        int getSize();
        void printList();
};

LinkedList::LinkedList(){
    currentSize = 0;
    head = NULL;
}

bool LinkedList::isEmpty(){
    return head == NULL;
}

bool LinkedList::contains(int data){
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::addLast(int data){
    Node* newNode = new Node(data);
    if(isEmpty()){
        head = newNode;
        currentSize++;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    currentSize++;
}

void LinkedList::addFirst(int data){
    Node* newNode = new Node(data);
    if(isEmpty()){
        head = newNode;
        currentSize++;
        return;
    }
    newNode->next = head;
    head = newNode;
    currentSize++;
}

void LinkedList::addAt(int index, int data){
    if(index > getSize()){
        printf("Index out of bounds\n");
        return;
    }
    if(index == 0){
        addFirst(data);
        return;
    }
    Node* temp = head;
    Node* newNode = new Node(data);
    int i = 0;
    while(i != index-1){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    currentSize++;
}

void LinkedList::removeLast(){
    if(getSize() == 0){
        printf("Empty list");
        return;
    }
    if(getSize() == 1){
        currentSize--;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    currentSize--;
}

void LinkedList::removeFirst(){
    if(getSize() == 0){
        printf("Empty list");
        return;
    }

    head = head->next;
    currentSize--;
}

void LinkedList::removeAt(int index){
    if(index > getSize()){
        printf("Index out of bounds");
        return;
    }

    if(index == 0){
        removeFirst();
        return;
    }

    Node* temp = head;
    int i = 0;
    while(i != index-1){
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    currentSize--;
    // 0  1  2  3  4
    // a->b->c->d->e->NULL
}

int LinkedList::getSize(){
    return currentSize;
}

void LinkedList::printList(){
    if(getSize() == 0) return;

    Node* temp = head;
    while(temp->next != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->NULL", temp->data);
}


