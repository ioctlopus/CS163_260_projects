#include <iostream>
#include "datalogger.h"

//Datalogger only seeks to meet the functionality requirements of process. If this were to be used for more general use cases,
//other functionality would be added. Here, we just insert, remove, and print data:
datalogger::datalogger(){
    data = LinkedList();
}

datalogger::~datalogger(){
    ;
}

void datalogger::addData(int aSector, int aExposure, int aSpeed){
    if(aSector > 0)
        data.insert(aSector, aExposure, aSpeed);
}

void datalogger::removeSector(int sectToRemove){
    while(data.hasSector(sectToRemove)){
    data.removeBySector(sectToRemove);
    }
}

void datalogger::printReport() const{
    std::cout << "----------------------------------------------------------------------\n"
              << "Data values\n"
              << "----------------------------------------------------------------------"
              << std::endl;
    std::cout << "Data by Sector" << std::endl;
    data.printBySector();
    std::cout << "Data by Exposure" << std::endl;
    data.printByExposure();
    std::cout << "Data by Speed" << std::endl;
    data.printBySpeed();
    std::cout << "----------------------------------------------------------------------\n"
              << "Averages per sector\n"
              << "----------------------------------------------------------------------"
              << std::endl;
    data.printAverages();
    std::cout << "----------------------------------------------------------------------\n"
              << "Histogram data for exposure\n"
              << "----------------------------------------------------------------------"
              <<std::endl;
    data.printHistogramExposure();
    std::cout << "----------------------------------------------------------------------\n"
              << "Histogram data for speed\n"
              << "----------------------------------------------------------------------"
              <<std::endl;
    data.printHistogramSpeed();
}

void datalogger::printSectorList() const{
    data.printSectors();
}

bool datalogger::containsSector(int aSector){
    return data.hasSector(aSector);
}
