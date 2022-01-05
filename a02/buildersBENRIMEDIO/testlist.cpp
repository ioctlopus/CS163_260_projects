#include <iostream>
#include "linkedlist.h"
#include "event.h"
#include "structuretype.h"

using namespace std;

void printEvent(Event e)
{
    cout << "Sector: " << e.getSector() << " Structure: " << e.getType() << endl;
}

void dumpList(LinkedList &ll)
{
    cout << "Dumping the linkedlist" << endl;
    while (!ll.isEmpty())
    {
	Event result;
	ll.removeBack(result);
	printEvent(result);
    }
}

int main()
{
    LinkedList ll;
    Event e1(1,WIND);
    Event e2(2,WATER);

    cout << "dump list before adding" << endl;
    dumpList(ll);
    ll.insertFront(e1);
    dumpList(ll);
    ll.insertFront(e1);
    ll.insertFront(e2);
    dumpList(ll);
    
    return 0;
}
