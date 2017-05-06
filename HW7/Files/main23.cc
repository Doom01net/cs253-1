#include "U.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
const string propFile = "UnicodeDataV2.txt";
const string readfile = "data1";
int main() {

    // Testing for partially mutibyte UTF-8 Sequence 
    try{
    	U foo;
        foo.readfile("error2"); 
    }
    catch(string caught)
    {
        cout << "Throws: " << caught << endl;
    }

    return 0;
}
