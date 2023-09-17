/**
 * \file ZipcodeBuffer.h
 * \author Andrew Clayton
 * \version 1.0
 * \brief Class ZipcodeBuffer header file. This class is used to take in and store the data from the Zipcode CSV file
 * 
 * ZipcodeBuffer class: File to work with Zipcode CSV file
 * - Function to take in a line of the CSV file as a string and set the attributes of the object
 * - Overloaded input and output operators
 * - 
 * \note: A valid CSV line must be provided to set the attributes correctly
 */

#ifndef ZIPCODEBUFFER_H
#define ZIPCODEBUFFER_H

#include <iostream>
using namespace std;



class ZipcodeBuffer {
    private:
        //Commenting probably needed for attributes? -------------------------------------
        int zipcode;
        string city;
        string state;
        string county;
        double latitude;
        double longitude;

  
  //Comentation style: Doxygen
    /**
     * \brief Overloaded input operator for Array
     * \param in Input stream
     * \param a Array to fill
     * \pre a.ptr must point to an array with size at least a.size
     * \post The first a.size elements of a.ptr are filled with integers read from input
     * \return Updated input stream
     */


    public:
        //Default constructor
        /**
         * \brief Default constructor
         * \pre None
         * \post ZipcodeBuffer object is created with default values
        */
        ZipcodeBuffer();

        /**
         * \brief Constructor
         * \param zipcode Integer value of zipcode
         * \param city City as a string
         * \param state State as a string
         * \param county County as a string
         * \param latitude Latitude as a double
         * \param longitude Longitude as a double
         * \pre None
         * \post ZipcodeBuffer object is created with the given values
        */
        ZipcodeBuffer(int zipcode, string city, string state, string county, double latitude, double longitude);

        //Function using getline to take in all of the attributes, separated by commas CSV style, and set them to the object
        void setFromFile(string fileLine);


        //OVERLOADED OPERATORS
        /**
         * \brief Overloaded input operator for ZipcodeBuffer to read in a line of a CSV file as a string
         * \param in Input stream
         * \param a ZipcodeBuffer to fill
         * \pre A ZipcodeBuffer object must exist
         * \post The first a.size elements of a.ptr are filled with integers read from input
         * \return Updated input stream
         */
        friend istream& operator>>(istream& in, ZipcodeBuffer& buffer);

        /**
         * \brief Overloaded output operator for ZipcodeBuffer
         * \param out Output stream
         * \param a ZipcodeBuffer to display
         * \pre None
         * \post The first a.size elements of a.ptr are displayed to output
         * \return Updated output stream
         */
        friend ostream& operator<<(ostream& out, const ZipcodeBuffer& buffer);

    
};









#endif