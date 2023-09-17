/**
 * \file ZipcodeBuffer.cpp
 * \author Andrew Clayton
 * \version 1.0
 * \brief Member function definitions for class ZipcodeBuffer
 * 
 * ZipcodeBuffer class:
 * - Allows reading from a CSV string and setting object attributes.
 * - Allows for easy input and output through overloaded operators.
 * - Holds information like zipcode, city, state, county, latitude, and longitude.
 * 
 * 
 */


#include "ZipcodeBuffer.h" 
#include <sstream> //For stringstream
#include <string> //For getline

//Default constructor------

//Constructor
ZipcodeBuffer::ZipcodeBuffer(int zipcode, string city, string state, string county, double latitude, double longitude) {
    this->zipcode = zipcode;
    this->city = city;
    this->state = state;
    this->county = county;
    this->latitude = latitude;
    this->longitude = longitude;
}

//Example of what needs to be taken in: 1222,Ashley Falls,MA,Berkshire,42.0596,-73.3202
void ZipcodeBuffer::setFromFile(string fileLine) {
    stringstream ss(fileLine);
    string field;

    //Read zipcode
    getline(ss, field, ',');
    zipcode = stoi(field);

    //Read city
    getline(ss, field, ',');
    city = field;

    //Read state
    getline(ss, field, ',');
    state = field;

    //Read county
    getline(ss, field, ',');
    county = field;

    //Read latitude
    getline(ss, field, ',');
    latitude = stod(field);

    //Read longitude
    getline(ss, field, ',');
    longitude = stod(field);

}

//OVERLOADED OPERATORS
//Overloaded input operator
istream& operator>>(istream& in, ZipcodeBuffer& buffer) {
    string fileLine;
    getline(in, fileLine);
    buffer.setFromFile(fileLine);
    return in;
}

//Overloaded output operator
ostream& operator<<(ostream& out, const ZipcodeBuffer& buffer) {
    out << buffer.zipcode << ", " << buffer.city << ", " << buffer.state << ", " << buffer.county << ", " << buffer.latitude << ", " << buffer.longitude;
    return out;
}