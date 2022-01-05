#ifndef SURV_DAT_H
#define SURV_DAT_H

class Survey_data{
public:
    Survey_data();
    Survey_data(const int& aSector, const int& aExposure, const int& aSpeed);
    ~Survey_data();
    //Accessors:
    void setSector(const int& aSector);
    void setExposure(const int& aExposure);
    void setSpeed(const int& aSpeed);
    int getSector() const;
    int getExposure() const;
    int getSpeed() const;
    //Helpers and Miscellaneous:
    void printData() const;
    //Rule of Three stuff:
    void operator= (const Survey_data& aData);
    Survey_data(const Survey_data& aData);
private:
    int sector;
    int exposure;
    int speed;
};

#endif
