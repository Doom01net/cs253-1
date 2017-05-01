#include "hset.h"
#include <cstdlib>			// for srand() and rand()
#include <iostream>
#include <time.h>			// for time() (duh)

using namespace std;

int main() {
    hset<int> h;

    srand(time(nullptr));		// Seed the random number generator

    for (int j=0; j<20; j++)		// Put some random numbers into the set
	h.insert(rand() % 100);		// Each number is 0-99
    h.dump();				// Let’s see what’s in there

    cout << "size=" << h.size() << ':';
    for (hset<int>::iterator i=h.begin(); i!=h.end(); ++i)
	cout << ' ' << *i;
    cout << '\n';

    hset<string> hs;

    hs.insert("alpha");
    hs.insert("beta");
    hs.insert("gamma");
    hs.insert("delta");
    hs.insert("epsilon");
    hs.dump();

    cout << "size=" << hs.size();
    for (hset<string>::iterator i=hs.begin(); i!=hs.end(); ++i)
	cout << ' ' << *i;
    cout << '\n';
}
