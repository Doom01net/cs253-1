#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string propFile = "UnicodeDataV3.txt";
const string readfile = "data2";
int main() {

    // Test for checking several instance of class must be able to co-exist 
    try{

    	U u;
	P p; 
    	p.readfile(propFile);
    	u.readfile(readfile);
        for (int i=0; i<u.size(); i++)
            p.count(u.codepoint(i));

    	cout << "Size of U before: " << u.size() << '\n';
    	cout << "Ll before: " << p.count("Ll") << '\n';
   
    	U u1;
	P p1; 
    	p1.readfile("UnicodeDataV4.txt");
    	u1.readfile("data2");

    	cout << "Size of U after: " << u.size() << '\n';
        cout << "Ll after: " << p.count("Ll") << '\n';

        for (int i=0; i<u1.size(); i++)
            p1.count(u1.codepoint(i));

    	cout << "Cc: " << p1.count("Cc") << '\n';
	

    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
