//Habeeb Mohammed
//2017-01-27
//CS253 HW1 -- Character Properties

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main(){
	
	//Read in ASCII-properties file
	
	ifstream input ("/s/bach/a/class/cs253/pub/ASCII-properties");

	//If access to ASCII-properties file is possible
	
	if(input.is_open()){

		//Store each line of ASCII-properties file into vector

		vector<string> strArray;			
		string line;

		while( getline(input, line) ){ 
			
			strArray.push_back(line);		
		
		}

		
		//Stores ascii char properties (i.e. Cc) corresponding to decimal values into a string vector
		
		vector<string> symArray;
	
		for( size_t i = 0; i < strArray.size(); i++){

			symArray.push_back( strArray[i].substr(3,2) );
		}


		//Converts from hex to decimal (i.e. 4A --> 74) and stores the values in a long vector
		
		vector<long> hexArray;

		for( size_t i = 0; i < strArray.size(); i++){

			hexArray.push_back( stol(strArray[i].substr(0,2).c_str(), nullptr, 16) );
		}
		

		//Stores ascii chars corresponding to decimal values (i.e. 37 --> %) into a char vector

		vector<char> asciiArray;

		for( size_t i = 0; i < hexArray.size(); i++){
			
			asciiArray.push_back( (char) hexArray[i] );
		}

		
		input.close();
		
		//Make and populate a map with ascii and property symbol(s) (i.e. Cc to C for now, perhaps tuple in the future?)

		map<char, char> propmap;		

		for( size_t i = 0; i < symArray.size(); i++ ){

			char firstChar = symArray[i][0];
			propmap.insert( pair<char,char>(asciiArray[i], firstChar) );
		}


			//For each char in std in, compare to elements in map corresponding to those char keys, then increment counter
			
			char c;	
			int cCount = 0; int lCount = 0; int nCount = 0; int pCount = 0; int sCount = 0; int zCount = 0;

			while( cin >> noskipws >> c ){
				
					if( propmap.at(c) == 'C' ){

						cCount++;
					}

					if( propmap.at(c) == 'L' ){

						lCount++;
					}

					if( propmap.at(c) == 'N' ){

						nCount++;
					}
		
					if( propmap.at(c) == 'P' ){

						pCount++;

					}

					if( propmap.at(c) == 'S' ){

						sCount++;
					}

					if( propmap.at(c) == 'Z' ){

						zCount++;
					}

			}

		
		//Output		

		cout << "Control: " << cCount << '\n';

		cout << "Letter: " << lCount << '\n';

		cout << "Number: " << nCount << '\n';

		cout << "Punctuation: " << pCount << '\n';

		cout << "Symbol: " << sCount << '\n';

		cout << "Space: " << zCount << '\n';

	}
	
	//File not found exception
	
	else cout << "ERROR! THE ASCII TABLE HAS VANISHED! WHAT HAVE YOU DONE!?" << '\n';
		
	return 0;
}
