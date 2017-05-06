#include "U.h"
#include <iostream>
using namespace std;
const string errorfile = "error";
int main() {

    // Testing error for invalid byte sequence  
    try{
    	U foo;
        foo.readfile(errorfile); 
    }
    catch(string caught)
    {
        cout << "Throws: " << caught << endl;
    }

    return 0;
}
