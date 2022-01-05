#include "linkedlist.h"

int main(){
    LinkedList ll;
    Event x(1, WIND);
    Event y(7, WATER);
    Event z(2, SOLAR);

    ll.insertFront(x);
    ll.insertFront(y);
    ll.insertFront(z);

    Event result;
    ll.removeBack(result);

    return 0;
}
