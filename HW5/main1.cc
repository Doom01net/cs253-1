#include "U.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
    
int main() {
	U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
	const U test = foo;
        cout << "Should be 8: " << test.size() << '\n'
             << "Should be 2: " << test.propcount("Sm") << '\n'
             << "Should be b³: " << test.get(3,5) << '\n';
        return 0;
}
