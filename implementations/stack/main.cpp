#include <iostream>
#define MAX_SIZE 10
using namespace std;

class Stack{
public:
    int top;
    int data[MAX_SIZE];
    Stack();
    void push(int data);
    int pop();
    int peek();
    void printStack();
};

Stack::Stack(){
    top = 0;
}

void Stack::push(int d){
    if(top == MAX_SIZE){
        printf("Full stack\n");
        return;
    }
    data[top] = d;
    top++;
}

int Stack::pop(){
    if(top == 0){
        printf("Empty stack\n");
        return -1;
    }

    return data[--top];
}

int Stack::peek(){
    return data[top];
}

void Stack::printStack(){
    for(int i = 0; i < top; i++){
        printf("%d->", data[i]);
    }
}

int main()
{
    Stack s;
    s.push(1);
    s.pop();
    return 0;
}
