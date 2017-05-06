#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
const string readfile = "data1";
int main() {

    // Testing for constant methods
    try{
    	const U foo(readfile);
    	cout << "Size " << foo.size() << '\n';
    	cout << "Get(): " << foo.get() << '\n';
    	cout << "Get(5): " << foo.get(9) << '\n';
    	cout << "Get(6, 8): " << foo.get(6,8) << '\n';
    	cout << "Codepoint " << foo.codepoint(2) << '\n';
     
	const P foo1("UnicodeDataV4.txt");
	
	cout << "Size " << foo1.size() << '\n';
	cout << "Count " << foo1.count("Lo") << '\n';

    	for (const auto &p : foo1.props())
            cout << "Property: " << p << '\n';

	cout << "Empty " << foo1.empty() << '\n';
    	cout << "Empty " << foo.empty() << '\n';
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    
    return 0;
}
