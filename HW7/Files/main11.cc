#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string propFile = "UnicodeDataV2.txt";
int main() {

    // Test for Concatenation of a String object and U object and vice-versa
    
    try{
    	U u; 
	P p;
    	u.readfile("data1");
    	p.readfile(propFile);

	const string test = "\u266a";

	cout << "u + test: " << u + test << endl;
	cout << "No change u: " << u << endl;
	cout << "No change test: " << test << endl;

	U u1;
	u1.readfile("data2");
	
	const string test1 = "Extract the std::string representing a single code point, as UTF-8 characters, like .get(int index):";
	
	cout << "test1 + u1: " << test1 + u1 << endl;
	cout << "No change u1: " << u1 << endl;
	cout << "No change test1: " << test1 << endl;
	
    }
    catch(string caught)
    {
	cout << "Throws: " << caught << std::endl;
    }
    return 0;
}
