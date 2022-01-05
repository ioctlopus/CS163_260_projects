#include "stack.h"

int main(){
    Stack s;
    Event e1(1, WIND);
    Event e2(3, SOLAR);
    Event e3(90, WATER);

    s.push(e1);
    s.push(e2);
    s.push(e3);

    s.display();
    
    return 0;
}
