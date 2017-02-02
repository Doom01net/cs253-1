#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
	
	vector<int> intArr;
	string bigstring;
	multiset<char> charMulti;
	set<char> charSet;

	int i;
	while(cin >> i){
	
		if(i != 0){
			intArr.push_back(i);
		}
		else
			break;	
	}
	
	ifstream in ("/etc/resolv.conf");

	while( in.is_open() ){
		char c;
		while(in.get(c)){
	
		bigstring.push_back(c);
		}	
	}

	for( char c : bigstring ){

		charMulti.insert(c);
	}

	for( char c : charMulti ){

		charSet.insert(c);
	}

	cout << intArr.size() << '\n';
	cout << bigstring.size() << '\n';
	cout << charMulti.size() << '\n';
	cout << charSet.size() << '\n';



}









