#include "U.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
    
int main() {
	U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
        cout << "Should be 8: " << foo.size() << '\n'
             << "Should be 2: " << foo.propcount("Sm") << '\n'
             << "Should be b³: " << foo.get(3,5) << '\n'
	     << "Should be a: " << foo.get(5) << '\n';
		
		
        return 0;
}
