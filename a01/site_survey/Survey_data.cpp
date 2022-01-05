#include <iostream>
#include "Survey_data.h"

//Really straightforward class -- basically just holds three values:
Survey_data::Survey_data(){
    sector = 0;
    exposure = 0;
    speed = 0;
}

Survey_data::Survey_data(const int& aSector, const int& aExposure, const int& aSpeed){
    sector = aSector;
    exposure = aExposure;
    speed = aSpeed;
}

Survey_data::~Survey_data(){
    sector = 0;
    exposure = 0;
    speed = 0;
}

Survey_data& Survey_data::operator= (const Survey_data& aData){
    if(this != &aData){
        sector = aData.getSector();
        exposure = aData.getExposure();
        speed = aData.getSpeed();
    }
    return *this;
}

Survey_data::Survey_data(const Survey_data& aData){
    this->sector = 0;
    this->exposure = 0;
    this->speed = 0;
    *this = aData;
}

void Survey_data::setSector(const int& aSector){
    sector = aSector;
}

void Survey_data::setExposure(const int& aExposure){
    exposure = aExposure;
}

void Survey_data::setSpeed(const int& aSpeed){
    speed = aSpeed;
}

int Survey_data::getSector() const{
    return sector;
}

int Survey_data::getExposure() const{
    return exposure;
}

int Survey_data::getSpeed() const{
    return speed;
}

void Survey_data::printData() const{
    std::cout << "Sector: #" << sector << " " << exposure << "% exposure, " << speed
    << " km/hr windspeed" << std::endl;
}
