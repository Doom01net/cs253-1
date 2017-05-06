#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Sending U and P to the output streams
 
    try{

	U u;
	u.append("#$:;Programming is an art and Music is science.:;$#");
	cout << "u: " << u << '\n';

    	P p;
        p.readfile("TestPropertyFile.txt");
	for (int i=0; i<u.size(); i++)
            p.count(u.codepoint(i));

	cout << "p: " << p;
    }
    catch(string caught)
    {
        cout << "Throws: " << caught << endl;
    }
 
    return 0;
}
