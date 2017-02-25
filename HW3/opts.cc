//Habeeb Mohammed
//2017-01-30
//CS253 HW2 -- Reading Multiple Files

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){


	//Read all the options into a vector of strings	
	vector<string> options;
	vector<string> arguments;
	string filename = "";
	bool isAll = false;
if(argc != 1){

	if(argv[1][0] == '-'){
	
		for(int i = 1; i < argc; i++){
			string option = "";
			if(!isAll){
				//if argv has options, store them
				if(argv[i][0] == '-'){
					option.push_back(argv[i][1]);
					option.push_back(argv[i][2]);
					options.push_back(option);
					
					if(argv[i][1] == 'a' && argv[i][2] == 'l' && argv[i][3] == 'l'){
						option = "all";
						options.clear();
						options.push_back(option);
						isAll = true;
						continue; 
					
					}
				}
			
			
				//if argv has a filename and the filename string is empty, store it, else complain and die
				if(argv[i][0] != '-'){
					if((argv[i][0] != '-') && (filename == "")){
						filename = argv[i];
					}
					else{
					arguments.push_back(argv[i]);
					//cerr << "No filename provided!" << '\n';
					//exit(EXIT_FAILURE);
					}
				}	

			}
			else{
				if((argv[i][0] != '-') && (filename == "")){
					filename = argv[i];
				}
				else 
					arguments.push_back(argv[i]);
				

		}	
		
	

		}
	
	}

	else{
	
		cerr << "No options provided!" << '\n';
		exit(EXIT_FAILURE);


		
	}
		

		cout << options.size() << '\n';
		cout << filename << '\n';
		cout << arguments.at(0) << '\n';

	
	
	ifstream input (filename);

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

		vector<string> asciiArray;

		for( size_t i = 0; i < hexArray.size(); i++){
			char tempc = (char) hexArray[i];
			string temps;
			temps.push_back(tempc);
			asciiArray.push_back( temps );
		}

		
		input.close();
		
		//Make and populate a map with ascii and property symbol(s) (i.e. Cc to C for now, perhaps tuple in the future?)

		map<string, string> propmap;		

		for( size_t i = 0; i < symArray.size(); i++ ){

			string symbol = symArray[i];
			propmap.insert( pair<string,string>(asciiArray[i], symbol) );
		}


			//For each char in std in, compare to elements in map corresponding to those char keys, then increment counter
			
		
		string index;
		int cCount = 0;
	
		if(argc > 1){

			for( size_t i = 0; i < arguments.size(); i++){
	
			ifstream in (arguments[i]);
			//bool isok = false;

				if(in.is_open()){

					while( getline(in, index) ){
						for(size_t j = 0; j < index.size(); j++){
						string jdex;
						jdex.push_back(index[j]);
						//cout << jdex << '\n';
						if( propmap.count(jdex) > 0 ){
							
							for(size_t k = 0; k < options.size(); k++){
	
								if( options.at(k) == propmap.at(jdex) ){
					
									cCount++;
						
								}
								
							}
						}
				
					    	}
						
						}
				}	
						else {	
		
							cerr 	<< "Error! File cannot be read." << '\n'
								<< "Program: " << argv[0] << '\n'
								<< "Unreadable file: " << argv[i] << '\n';	
							return 0;

						//stopping: check for c. so if c does not exist in the map, throw ^	
						}	
							

					}
	
				cout << "Count: " << cCount << endl;
				}
			
				
		
		//Output		

		}
	
		else		
		cerr << "Usage: " << argv[0] << " <file1> | <file2> | ... " << '\n';
	}
	

	//File not found exception
	
	else cout << "Error! ASCII-properties file not found." << '\n';
}
//	else{
//		cout << "no args" << '\n';
//	}
		
//	return 0;
//}
