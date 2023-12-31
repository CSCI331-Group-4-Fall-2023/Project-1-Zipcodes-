#include <iostream>
#include <map>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> //for string stream
#include <string> //for getline
#include <fstream> //for file reading
//Authors: Tristan Adams, Andrew Clayton, Preston Betz, and Zachary Sunder
using namespace std;

/**
 * @brief Main function to populate and display a table of StateRow objects using a map.
 * 
 * The main function reads from a CSV file, populates a map with StateRow objects
 * indexed by state ID, and displays the final table of states with their easternmost, 
 * westernmost, northernmost, and southernmost zip codes.
 * 
 * @return 0 on successful execution, -1 on error.
 */
int main() {
    //Makes a hashmap to hold state IDs
    map<string, StateRow> stateMap;

    //Buffer to extract CSV data
    ZipcodeBuffer zipHolder; 
    ifstream inFile("us_postal_codes.csv");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return -1;
    }

    bool first = true;
    string line;
    while (getline(inFile, line)) {
        // Skip header line
        if(first) {
            zipHolder.setHeaderMap(line);
            first = false;
            continue;
        }

        // Set values from the current CSV line
        zipHolder.setFromFile(line);
        string stateId = zipHolder.getState();

        // Initialize or get reference to the StateRow object for the current state
        StateRow& currentRow = stateMap[stateId];
        if (currentRow.getFresh()) {
            currentRow.setID(stateId);
            currentRow.setEast(zipHolder.getLongitude());
            currentRow.setEastZ(zipHolder.getZipcode());
            currentRow.setWest(zipHolder.getLongitude());
            currentRow.setWestZ(zipHolder.getZipcode());
            currentRow.setNorth(zipHolder.getLatitude());
            currentRow.setNorthZ(zipHolder.getZipcode());
            currentRow.setSouth(zipHolder.getLatitude());
            currentRow.setSouthZ(zipHolder.getZipcode());
            currentRow.setFresh(false);
        } else {
            // Update values if current zip code represents an extreme for the state
            if(currentRow.getEast() > zipHolder.getLongitude()){
                currentRow.setEast(zipHolder.getLongitude());
                currentRow.setEastZ(zipHolder.getZipcode());
            }
            if(currentRow.getWest() < zipHolder.getLongitude()){
                currentRow.setWest(zipHolder.getLongitude());
                currentRow.setWestZ(zipHolder.getZipcode());
            }
            if(currentRow.getNorth() < zipHolder.getLatitude()){
                currentRow.setNorth(zipHolder.getLatitude());
                currentRow.setNorthZ(zipHolder.getZipcode());
            }
            if(currentRow.getSouth() > zipHolder.getLatitude()){
                currentRow.setSouth(zipHolder.getLatitude());
                currentRow.setSouthZ(zipHolder.getZipcode());
            }
        }
    }

    // Display the final table
    cout << "StateID, East Zip, West Zip, North Zip, South Zip" << endl;
    for (const auto& pair : stateMap) {
        if(!pair.second.getFresh()){
            cout << pair.second << endl;
        }
    }

    return 0;
}
