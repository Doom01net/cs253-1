#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
int main() {

    // Testing with filename constructor in both classes, size methods of both classes and the codepoint method
    // Testing invlid codepoint index
   
    try
    { 
    	U foo("data");
    	P foo1("UnicodeDataV4.txt");
    	for (int i=0; i<foo.size(); i++) 
    	{
        	foo1.count(foo.codepoint(i));
    	}
    	cout << "Size U: " << foo.size() << '\n'
   		<< "Size P: " << foo1.size() << '\n'
         	<< "Codepoint: " << foo.codepoint(8) << '\n';

	cout << "Invalid Codepoint: " << foo.codepoint(-1) << '\n';
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
