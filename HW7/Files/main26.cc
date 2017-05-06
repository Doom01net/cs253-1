#include "U.h"
#include "P.h"
#include <iostream>
#include <cassert>

using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";

int main() {

    // Testing for Comparison 
    try {
    	U u;
        u.append("\u0B67 Jack Applin"); 

	assert(u == u);
	
	U u1;
	u1.append("\u0B6B Pratik Warade");
	const string test = "\u0B6B Pratik Warade";
	assert(u1 == test);

	U u2;
        u2.append("\u0B6E Sam Maxwell");
        const string test1 = "\u0B6E Sam Maxwell";
        assert(u2 == test1);

	const U u4 = u;
	assert(u4);
	assert(u4 != u1);
	assert(u1 != test1);
	assert(test != u2);

	P p;
	p.readfile(pub+"UnicodeData.txt");
	
	for (int i=0; i<u2.size(); i++)
            p.count(u2.codepoint(i));

        assert(p.count("Lu")==2);
        assert(p.count("Mn")==0);
        assert(p.size() == 29);
        cout << "There are " << p.size() << " distinct properties.\n";

    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }


    return 0;
}
