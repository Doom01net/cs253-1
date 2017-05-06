#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
int main() {

    // Error check for bad index in subscrpting

    try{
    	U u;
        u.readfile("data3");
	
	cout << "u[2112034]" << u[2112034] << endl; 
    }
    catch(string caught)
    {
        cout << "Throws: " << caught << endl;
    }
 
    
    return 0;
}
