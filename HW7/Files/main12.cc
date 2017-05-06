#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string propFile = "UnicodeDataV2.txt";
int main() {

    // Testing for Concatenation and Subscripting 
    try{ 
    	U u; 
    	P p;
    	p.readfile("UnicodeDataV2.txt");
    	u.readfile("data");

	const string test = "There is only one happiness in this life, to love and be loved.";

	u += test;
	cout << "u: " << u << endl; 
	cout << "No change test: " << test << endl;

	cout << "u[17]: " << u[17] << endl;
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
