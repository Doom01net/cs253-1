#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
const string readfile = "data1";
int main() {

    // Test for Assignment operator
    // Testing Append method in U class
    // Testing get method with a single argument
    // Test for concatenation of U objects

    try{ 
    	U u;
    	u.readfile(readfile);
   	U u2;
    	u2 = u;
    	u2.append("Black metal is an extreme subgenre and subculture of heavy metal music.");
    	P p;
    	p.readfile(pub+"UnicodeData.txt"); 
    	P p2;
    	p2 = p; 
    	cout << "Get: " << u2.get(16) << '\n';

	U u3;
	u3.readfile("data2");
	
	cout << "u2 + u3: " << u2 + u3 << endl;
	cout << "No chage u2: " << u2 << endl;
	cout << "No chage u3: " << u3;
	
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }


    return 0;
}
