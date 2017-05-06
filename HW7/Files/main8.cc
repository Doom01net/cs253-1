#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
const string propFile = "UnicodeDataV2.txt";
int main() {

    // Test for both Copy Constructors and get method with two arguments
    // Test for Assignment operator and get method

    try{ 
    	U u;
    	P p;
    	u.readfile("story.txt");
    	p.readfile(propFile);
    	U u1 = u;
    	P p1 = p;
    	cout << "Get: " << u1.get(56, 96) << '\n'; 
	
	const string test = "the mystic mountains of himalaya";
	u1 = test;
	cout << "Get: " << u1.get() << endl;

    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;

}
