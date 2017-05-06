#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Test for default constructor, readfile calling twice, both count methods
    try{
    	U u; 
	P p;
    	u.readfile("story.txt");
    	u.readfile("story2.txt");
    	p.readfile("/s/bach/a/class/cs253/pub/UnicodeData.txt");
	for (int i=0; i<u.size(); i++)
            p.count(u.codepoint(i));
    	cout << "Lo: " << p.count("Lo") << '\n';

    }
    catch (const string &msg) {
        cout << "Thrown error: " << msg << '\n';
    }

    return 0;
}
