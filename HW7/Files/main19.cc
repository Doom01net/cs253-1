#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
int main() {

    // Testing for clear() method in both classes

    try {
        U u;
        u.append("இது cs253 வகுப்பு.");
        P p(pub+"UnicodeData.txt");
        for (int i=0; i<u.size(); i++)
            p.count(u.codepoint(i));
        cout << "Size of U before: " << u.size() << '\n'
             << "Size of P before: " << p.size() << '\n'
             << "Count: " << p.count("Mc") << '\n'
             << "get: " << u.get(2,4) << '\n';

        u.clear();
        p.clear();
	cout << "Size of U after: " << u.size() << '\n';
	cout << "Size of P after: " << p.size() << '\n';
        return 0;
    }
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
    }
}

