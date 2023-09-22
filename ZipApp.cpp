#include <iostream>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> // For stringstream
#include <string> // For getline
#include <fstream> // For file reading
//authors Tristan Adams and Preston Betz
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
        // cout << "State " << z << " was set to " << zipTable[z].getID() << endl;
        z++;
    }

    // Call buff class and waterfall comparisons

    // Print the final table
    cout << "-------Table of States Final-------" << endl;
    for (int i = 0; i < 50; i++) {
        cout << zipTable[i] << endl;
    }

    return 0;
}
