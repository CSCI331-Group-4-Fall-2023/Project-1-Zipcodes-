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


        //Getters
        /**
         * \brief Getter for zipcode
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Integer value of zipcode
        */
        int getZipcode() const;

        /**
         * \brief Getter for city
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return String value of city
        */
        string getCity() const;

        /**
         * \brief Getter for state
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return String value of state
        */
        string getState() const;

        /**
         * \brief Getter for county
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return String value of county
        */
        string getCounty() const;

        /**
         * \brief Getter for latitude
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Double value of latitude
        */
        double getLatitude() const;

        /**
         * \brief Getter for longitude
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Double value of longitude
        */
        double getLongitude() const;

        //Setters
        /**
         * \brief Setter for zipcode
         * \param zipcode Integer value of zipcode
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's zipcode attribute is set to the given value
        */
        void setZipcode(int zipcode);

        /**
         * \brief Setter for city
         * \param city String value of city
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's city attribute is set to the given value
        */
        void setCity(string city);

        /**
         * \brief Setter for state
         * \param state String value of state
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's state attribute is set to the given value
        */
        void setState(string state);

        /**
         * \brief Setter for county
         * \param county String value of county
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's county attribute is set to the given value
        */
        void setCounty(string county);

        /**
         * \brief Setter for latitude
         * \param latitude Double value of latitude
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's latitude attribute is set to the given value
        */
        void setLatitude(double latitude);

        /**
         * \brief Setter for longitude
         * \param longitude Double value of longitude
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's longitude attribute is set to the given value
        */
        void setLongitude(double longitude);


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
