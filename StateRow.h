/**
 * @file StateRow.h
 * @brief Declaration of the StateRow class.
 * @authors Tristan Adams and Preston Betz
 */

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
/**
 * @class StateRow
 * @brief A class representing a state with geographic data.
 */
class StateRow {
private:
    string ID; ///< State ID
    double eastmost; ///< Easternmost longitude
    double westmost; ///< Westernmost longitude
    double northmost; ///< Northernmost latitude
    double southmost; ///< Southernmost latitude

public:
    /**
     * @brief Default constructor.
     * Initializes a StateRow object with default values.
     * - State ID: "TEMP"
     * - Easternmost longitude: 00.00
     * - Westernmost longitude: 00.00
     * - Northernmost latitude: 00.00
     * - Southernmost latitude: 00.00
     */
    StateRow();

    /**
     * @brief Parameterized constructor.
     * Initializes a StateRow object with the specified values.
     * @param id The state's ID.
     * @param e Easternmost longitude.
     * @param w Westernmost longitude.
     * @param n Northernmost latitude.
     * @param s Southernmost latitude.
     */
    StateRow(string id, double e, double w, double n, double s);

    /**
     * @brief Get the state's ID.
     * @return The state's ID.
     */
    string getID();

    // Getter methods
    double getEast(); ///< Get the easternmost longitude.
    double getWest(); ///< Get the westernmost longitude.
    double getNorth(); ///< Get the northernmost latitude.
    double getSouth(); ///< Get the southernmost latitude.

    // Setter methods
    void setID(string id); ///< Set the state's ID.
    void setEast(double east); ///< Set the easternmost longitude.
    void setWest(double west); ///< Set the westernmost longitude.
    void setNorth(double north); ///< Set the northernmost latitude.
    void setSouth(double south); ///< Set the southernmost latitude.

    /**
     * @brief Overloaded operator to print StateRow objects.
     * @param out Output stream.
     * @param row StateRow object to print.
     * @return Reference to the output stream.
     */
    friend ostream& operator<<(ostream& out, const StateRow& row);
};
#include "StateRow.cpp"
#endif
