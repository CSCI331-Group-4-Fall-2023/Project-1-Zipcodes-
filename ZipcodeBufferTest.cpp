#include <iostream>
#include <sstream>
#include <string>
#include "ZipcodeBuffer.h"
#include <fstream> //For file reading

using namespace std;

// Main function to test ZipcodeBuffer functionalities
int main() {
    cout << "=== ZipcodeBuffer Class Test ===" << endl;
    
    // Test constructor and output operator
    ZipcodeBuffer zip1(1222, "Ashley Falls", "MA", "Berkshire", 42.0596, -73.3202);
    cout << "Test constructor and output operator: " << zip1 << endl;
    
    // Test setFromFile function
    string fileLine = "1223,Ashley Ridge,NC,Wake,35.7721,-78.6386";
    ZipcodeBuffer zip2;
    zip2.setFromFile(fileLine);
    cout << "Test setFromFile function: " << zip2 << endl;
    
    //Test input operator reading in from a file named 'test.csv'
    ZipcodeBuffer zip3;
    ifstream inFile("test.csv");

    if (!inFile) {
        cout << "Error opening file" << endl;
        return -1;
    }

    string line;
    //Reading from file
    while (getline(inFile, line)) { 
        zip3.setFromFile(line);
        cout << "Read from file: " << zip3 << endl;
    }

    //Test getters and setters
    zip3.setState("IL");
    cout << zip3.getState();
    
    return 0;
}
