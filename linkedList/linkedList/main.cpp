#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
    LinkedList l;
    l.addFirst(5);
    l.addFirst(4);
    l.addLast(2);
    l.addFirst(7);
    l.addLast(9);
    l.addAt(3, 34);
    l.removeAt(3);
    l.addAt(6, 450);
    l.printList();
    return 0;
}
