#include <iostream>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> // For stringstream
#include <string> // For getline
#include <fstream> // For file reading
//authors Tristan Adams, Preston Betz, and achary Sunder
using namespace std;

/**
 * @brief Main function to populate and display a table of StateRow objects.
 * 
 * The main function reads state IDs from a CSV file, initializes an array of StateRow objects,
 * and displays the final table of states.
 * 
 * @return 0 on successful execution, -1 on error.
 */
int main() {
    // Make an array to hold state rows
    StateRow zipTable[50];

    // Populate the array with default state rows
    for (int i = 0; i < 50; i++) {
        StateRow pass = StateRow();
        zipTable[i] = pass;
    }

    // Set state IDs (0-49) to the 50 states from CSV
    ifstream inFile("ID.csv");

    if (!inFile) {
        cout << "Error opening file" << endl;
        return -1;
    }

    string line;
    int z = 0;
    while (getline(inFile, line)) {
        zipTable[z].setID(line);
        z++;
    }
    zipTable[0].setID("AL");
    // Call buff class and waterfall comparisons

    ZipcodeBuffer zipHolder;
    ifstream inFile2("us_postal_codes.csv");
     if (!inFile2) {
        cout << "Error opening file" << endl;
        return -1;
    }
    bool first = true;
    int count = 0;
    //loop that will feed the array piece by piece
    while (getline(inFile2, line)) { 
        count++;
        if(first == true){
            zipHolder.setHeaderMap(line);
            first = false;
            continue;
        }
        
        zipHolder.setFromFile(line);

        //itterate through the array and match the state ID
        for (int i = 0; i < 50; i++) {

            //populate stateRow if its unused
            if(zipHolder.getState() == zipTable[i].getID()){
                if(zipTable[i].getFresh() == true){
                    zipTable[i].setEast(zipHolder.getLongitude());
                    zipTable[i].setEastZ(zipHolder.getZipcode());
                    zipTable[i].setWest(zipHolder.getLongitude());
                    zipTable[i].setWestZ(zipHolder.getZipcode());
                    zipTable[i].setNorth(zipHolder.getLatitude());
                    zipTable[i].setNorthZ(zipHolder.getZipcode());
                    zipTable[i].setSouth(zipHolder.getLatitude());
                    zipTable[i].setSouthZ(zipHolder.getZipcode());
                    zipTable[i].setFresh(false);
                     break;
                // comparisons for if the row has been touched
                }else{
                    if(zipTable[i].getEast() > zipHolder.getLongitude()){
                        zipTable[i].setEast(zipHolder.getLongitude());
                        zipTable[i].setEastZ(zipHolder.getZipcode());
                    }
                    if(zipTable[i].getWest() < zipHolder.getLongitude()){
                        zipTable[i].setWest(zipHolder.getLongitude());
                        zipTable[i].setWestZ(zipHolder.getZipcode());
                    }
                    if(zipTable[i].getNorth() < zipHolder.getLatitude()){
                        zipTable[i].setNorth(zipHolder.getLatitude());
                        zipTable[i].setNorthZ(zipHolder.getZipcode());
                    }
                    if(zipTable[i].getSouth() > zipHolder.getLatitude()){
                        zipTable[i].setSouth(zipHolder.getLatitude());
                        zipTable[i].setSouthZ(zipHolder.getZipcode());
                    }
                     break;
                }
                
               
            }
            
        }
    }



    // Print the final table
    cout << "-------Table of States Final-------" << endl;
    for (int i = 0; i < 50; i++) {
        if(zipTable[i].getFresh() == false){
            cout << zipTable[i] << endl;
        }
    }

    return 0;
}
