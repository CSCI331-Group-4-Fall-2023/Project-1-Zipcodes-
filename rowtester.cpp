#include "StateRow.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    cout << "---- Testing the StateRow class ------" << endl;

    //testing the default constructor
    StateRow test1 = StateRow();
    cout<< "Test of the default constructor:\n" << test1 << endl;
    cout<< "Test of the default constructor get:\n" << test1.getID() << endl;

    //testing the data driven constructor
    StateRow test2("MN", 42.05, 55.05, 65.05, 75.05);
    cout<< "Test of the data driven constructor:\n" << test2 << endl;

    return 0;

}