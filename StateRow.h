
#ifndef STATEROW_H
#define STATEROW_H

#include <string> // for the states ID
#include <iostream>

using namespace std;

// this is the base idea I had to make managing the comparisons between the zipcodes a bit easier
// with each row of the table being an object it should be possible to only have to read through the ZipBuffers once
// If you are reading this before I have added the proper comments good morning
// tbh I could end up scrapping all this in the morning only uploading this for postarity
// did not write a cpp or doxygen tags becuase this might end up getting scrapped during group disccusion
class StateRow{


    private:

    string ID; //state id

    // the four required data points for each state
    double eastmost;

    double westmost;

    double northmost;

    double southmost;

    public:
    //consturctors
    StateRow();

    StateRow(string id, double e, double w, double n, double s);

    string getID();

    //getters and setters
    double geteast();

    double getwest();

    double getnorth();

    double getsouth();

    void setID(string id);

    void seteast(double east);

    void setwest(double south);

    void setnorth(double north);

    void setsouth(double south);

     //this will be the print function that dispalys a neat looking row
     friend ostream& operator<<(ostream& out, const StateRow& row);

};

#endif