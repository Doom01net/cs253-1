#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Testing for props() method and invalid count in property   
    // Testing error in filename constructor
 
    try
    {
    	U foo;
	foo.append("\u00B5 \u00A9 \u00AE \u0040");
    	P foo1("UnicodeDataV4.txt");
	for (int i=0; i<foo.size(); i++)
            foo1.count(foo.codepoint(i));
        cout << "Radiohead: " << foo1.count("Radiohead") << '\n';
    	for (const auto &p : foo1.props())
		cout << "Property: " << p << '\n';

        U u("cant_open.txt");
    }
    catch(string caught)
    {
        cout << "Throws: " << caught << endl;
    }
    return 0;
}
