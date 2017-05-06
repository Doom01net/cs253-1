#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Testing for constant argument in copy constructor and assignment operator
    try{ 
    	const U foo;
    	U u1 = foo;
 
    	cout << "Testing constant argument in copy constructor in U" << '\n';

    	U u2;
    	u2 = foo;
 
    	cout << "Testing constant argument in assignment operator in U" << '\n';
	
	const P foo1;
	P p1 = foo1;

        cout << "Testing constant argument in copy constructor in P" << '\n';

        P p2;
        p2 = foo1;

        cout << "Testing constant argument in assignment operator in P" << '\n';

    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
