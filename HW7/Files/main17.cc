#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Boolean evaluation
    try{
    	U u;
	u.readfile("story.txt");

	if(u)
	{
	    cout << "First True" << '\n';
	}
	
	U u1;
	if(!u1)
        {
            cout << "Second False" << '\n';
        }

	P p;
	p.readfile("UnicodeDataV3.txt");
	
	if(p)
        {
            cout << "Third True" << '\n';
        }

	P p1;
	if(!p1)
        {
            cout << "Fourth False" << '\n';
        }

    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
