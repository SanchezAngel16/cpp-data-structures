#include <iostream>
#define MAX_SIZE 10
using namespace std;

class Queue{
public:
    int queueSize = MAX_SIZE;
    int currentSize;
    int data[MAX_SIZE];
    int head;
    int tail;
    Queue();
    void enqueue(int d);
    int dequeue();
    int peek();
    bool isEmpty();
    void printQueue();
};

Queue::Queue(){
    head = tail = currentSize = 0;
}

void Queue::enqueue(int d){
    if(head == tail && currentSize == queueSize){
        printf("Queue full");
        return;
    }
    data[tail] = d;
    printf("Data ->%d ", d);
    printf("Head ->%d ", head);
    printf("Tail ->%d\n", tail);
    if(tail+1 == queueSize){
        tail = 0;
    }else{
        tail++;
    }
    currentSize++;
}

int Queue::dequeue(){
    if(isEmpty()){
        printf("Queue empty\n");
        return -1;
    }

    int dequeuedData = data[head];
    printf("Head->%d ", head);
    printf("Tail->%d", tail);
    if(head+1 == queueSize){
        head = 0;
    }else{
        head++;
    }
    currentSize--;
    return dequeuedData;
}

int Queue::peek(){
    return data[head];
}

bool Queue::isEmpty(){
    return currentSize == 0 && head == tail;
}

void Queue::printQueue(){
    int tempHead = head;
    for(int i = 0; i < currentSize; i++){
        printf("%d->", data[tempHead]);
        if(tempHead+1 == queueSize){
            tempHead = 0;
        }else{
            tempHead++;
        }
    }
}

int main()
{
    Queue q;
    q.enqueue(1);
    printf("%d\n", q.dequeue());
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    for(int i = 0; i < 10; i++){
        printf("\n%d\n", q.dequeue());
    }
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    printf("\n%d\n", q.dequeue());
    printf("%d", q.peek());
    //q.printQueue();
    return 0;
}
