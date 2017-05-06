#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string propFile = "UnicodeDataV2.txt";
int main() {

    // Testing for Append of U objects
    try{ 
    	U u; 
    	P p;
    	p.readfile("UnicodeDataV2.txt");
    	u.readfile("data3");


	U u1;
	u1.append("Only I can change my life. No one can do it for me.");

	u += u1;
	cout << "u: " << u << endl; 
	cout << "No change u1: " << u1 << endl;
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
