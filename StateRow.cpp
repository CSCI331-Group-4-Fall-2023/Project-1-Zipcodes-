// Authors: Tristan Adams and Preston Betz

#include "StateRow.h"

#include <string> // for the states ID
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for StateRow.
 * Initializes a StateRow object with default values.
 * - State ID: "TEMP"
 * - Easternmost longitude: 00.00
 * - Westernmost longitude: 00.00
 * - Northernmost latitude: 00.00
 * - Southernmost latitude: 00.00
 */
StateRow::StateRow(){
    ID = "TEMP";
    eastmost = 00.00;
    westmost = 00.00;
    northmost = 00.00;
    southmost = 00.00;
}

/**
 * @brief Parameterized constructor for StateRow.
 * Initializes a StateRow object with the specified values.
 * @param id The state's ID.
 * @param e Easternmost longitude.
 * @param w Westernmost longitude.
 * @param n Northernmost latitude.
 * @param s Southernmost latitude.
 */
StateRow::StateRow(string id, double e, double w, double n, double s){
    this->ID = id;
    this->eastmost = e;
    this->westmost = w;
    this->northmost = n;
    this->southmost = s;
}

/**
 * @brief Get the easternmost longitude of the state.
 * @return The easternmost longitude.
 */
double StateRow::getEast(){
    return eastmost;
}

/**
 * @brief Get the westernmost longitude of the state.
 * @return The westernmost longitude.
 */
double StateRow::getWest(){
    return westmost;
}

/**
 * @brief Get the northernmost latitude of the state.
 * @return The northernmost latitude.
 */
double StateRow::getNorth(){
    return northmost;
}

/**
 * @brief Get the southernmost latitude of the state.
 * @return The southernmost latitude.
 */
double StateRow::getSouth(){
    return southmost;
}

/**
 * @brief Get the state's ID.
 * @return The state's ID.
 */
string StateRow::getID(){
    return ID;
}

/**
 * @brief Set the easternmost longitude of the state.
 * @param e The easternmost longitude to set.
 */
void StateRow::setEast(double e){
    this->eastmost = e;
}

/**
 * @brief Set the westernmost longitude of the state.
 * @param w The westernmost longitude to set.
 */
void StateRow::setWest(double w){
    this->westmost = w;
}

/**
 * @brief Set the northernmost latitude of the state.
 * @param n The northernmost latitude to set.
 */
void StateRow::setNorth(double n){
    this->northmost = n;
}

/**
 * @brief Set the southernmost latitude of the state.
 * @param s The southernmost latitude to set.
 */
void StateRow::setSouth(double s){
    this->southmost = s;
}

/**
 * @brief Set the state's ID.
 * @param id The state's ID to set.
 */
void StateRow::setID(string id){
    this->ID = id;
}

/**
 * @brief Overloaded operator to print StateRow objects.
 * @param out Output stream.
 * @param row StateRow object to print.
 * @return Reference to the output stream.
 */
ostream& operator<<(ostream& out, const StateRow& row){
    out << "[" << row.ID << "]" << "[" << row.eastmost << "]" << "[" << row.westmost << "]" << "[" << row.northmost << "]" << "[" << row.southmost << "]";
    return out;
}
