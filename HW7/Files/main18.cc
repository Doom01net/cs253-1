#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Testing for constant argument in readfile 
    
    try{ 
    	U foo;
	P foo1;
    	const string filename = "data1";
    	const string prop_filename = "UnicodeDataV2.txt";
    	foo.readfile(filename);    
    	foo1.readfile(prop_filename);    
    	cout << "Testing for constant argument in readfile" << '\n';
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
