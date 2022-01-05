#include "linkedlist.h"
class datalogger{
public:
	datalogger();
	~datalogger();
	void removeSector(int sectToRemove);
	void printReport() const;
	void addData(int aSector, int aExposure, int aSpeed);
	bool containsSector(int aSector);
	void printSectorList() const;
private:
    LinkedList data;
};
