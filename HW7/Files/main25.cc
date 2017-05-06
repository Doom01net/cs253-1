#include "U.h"
#include "P.h"
#include <iostream>

using namespace std;

const string pub="/s/bach/a/class/cs253/pub/";

int main() {

    // Testing with a large file with one minute time limit 
    try{

	U u(pub+"hamlet.txt");
        P p(pub+"UnicodeData.txt");
        for (int i=0; i<u.size(); i++)
            p.count(u.codepoint(i));	
	cout << "Success" << '\n';

    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }

    return 0;
}
