#include <iostream>

using namespace std;

void foo() {
    // Holy smokes--the next line contains both
    // predefined identifiers, AND adjacent string constant pasting!
    // Note the lack of << where you might otherwise expect them.

    cout << "Hi from " << __func__ << " at " __FILE__ ":" << __LINE__ << '\n';
}
