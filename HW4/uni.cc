//Habeeb Mohammed
//2017-03-04
//CS253 HW4 -- Unicode

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <set>
#include <bitset>
#include <sstream>

using namespace std;
void uni2long(string uni){
	long bits;
	stringstream buffer;
	string buff_str;
	vector<long> byteArray;
	for(char i : uni){
		bits = i;
		buffer << hex << bits << '\n';
		buff_str = buffer.str();
	}
	cout << buff_str[i];
}

int main(int argc, char *argv[]){


	//Read all the options into a vector of strings	
	vector<string> options;
	vector<string> arguments;
	string filename = "";
	bool isAll = false;
	bool passed_opts = false;
	if(argc > 1){

		if(argv[1][0] == '-'){

			for(int i = 1; i < argc; i++){
				string option = "";
				if(!isAll){
					//if argv has options, store them
					if((argv[i][0] == '-') && (passed_opts == false)){
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
						else continue;
					}


					//if argv has a filename and the filename string is empty, store it, else complain and die
					else if((argv[i][0] != '-')){
						passed_opts = true;
						if((argv[i][0] != '-') && (filename == "")){
							filename = argv[i];
						}
						else{
							arguments.push_back(argv[i]);
							//cerr << "No properties file provided!" << '\n';
							//exit(EXIT_FAILURE);
						}
					}
					else{
						cerr 	<< "Error! File cannot be read." << '\n'
							<< "Program: " << argv[0] << '\n'
							<< "Unreadable file: " << argv[i] << '\n';	
						exit(EXIT_FAILURE);

					}	

				}
				else{
					if((argv[i][0] != '-') && (filename == "")){
						filename = argv[i];
					}
					else{ 
						arguments.push_back(argv[i]);
					}

				}	

			}

		}

		else{

			cerr << "No options provided!" << '\n';
			cerr << "Usage: " << argv[0] << "<-option1> | <-option2> | ... <properties_file> <file1> | <file2> | ... " << '\n';
			exit(EXIT_FAILURE);



		}


//		cout << options.size() << '\n';
//		cout << filename << '\n';
//		cout << arguments[0] << '\n';



		ifstream input (filename);

		//If access to ASCII-properties file is possible

		if((input.is_open()) && (filename != "")){

			//Store each line of ASCII-properties file into vector
			
			vector<string> strArray;			
			string line;

			while( getline(input, line) ){ 

				strArray.push_back(line);		

			}
			
			vector<string> symArray;
			vector<long> hexArray;
			for(auto s : strArray){

				string delim = ";";
				string key;
				
				//convert uni values to long, then store in a  long vector
				long hexVal;
				size_t position1 = s.find(delim);
				hexVal = stol(s.substr(0,position1).c_str(), nullptr, 16);
				hexArray.push_back(hexVal);				
				
				//store character properties into a vector
				string s1 = s.substr(position1);
				size_t position2 = s1.find(delim);
				string s2 = s1.substr(position2+1);
				size_t position3 = s2.find(delim);
				string s3 = s2.substr(position3+1);
				key = s3.substr(0, 2);
				symArray.push_back(key);
			
			

			}
			//Stores ascii char properties (i.e. Cc) corresponding to decimal values into a string vector
		/*	
			vector<string> symArray;

			for( size_t i = 0; i < strArray.size(); i++){

				symArray.push_back( strArray[i].substr(3,2) );
			}

		*/
			//Converts from hex to decimal (i.e. 4A --> 74) and stores the values in a long vector

			/*vector<long> hexArray;

			for( size_t i = 0; i < strArray.size(); i++){

				hexArray.push_back( stol(strArray[i].substr(0,2).c_str(), nullptr, 16) );
			}*/


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


			map<string, int> outmap;

			for(auto sym : symArray){
				outmap.insert(pair<string, int>(sym, 0));
			}

			if(argc > 1){
				if(options[0] == "all"){
					options.clear();
					set<string> temp_set;
					for(auto sym : symArray){
						temp_set.insert(sym);
					
					}
					for(auto elem : temp_set){
						options.push_back(elem);
					}
				}

				for( size_t i = 0; i < arguments.size(); i++){
					string index = "";		
					ifstream in (arguments[i]);
					//bool isok = false;

					if(in.is_open()){
						char tempc;
						while( in.get(tempc) ){
							index.push_back(tempc);
							}
							//cout << index << "\n";
							for(size_t j = 0; j < index.size(); j++){
								string jdex;
								jdex.push_back(index[j]);
								//cout << jdex << '\n';
								uni2long(jdex);
								if( propmap.count(jdex) > 0 ){
									
									for(size_t k = 0; k < options.size(); k++){

										if( options.at(k) == propmap.at(jdex) ){

											outmap.at(options.at(k))++;

										}

									}
								}

							}
					}	
					else {	

						cerr 	<< "Error! File cannot be read." << '\n'
							<< "Program: " << argv[0] << '\n'
							<< "Unreadable file: " << arguments[i] << '\n';	
						exit(EXIT_FAILURE);

						//stopping: check for c. so if c does not exist in the map, throw ^	
					}	


				}
				
				map<string,int>::const_iterator iter = outmap.cbegin();
				
				for(auto option : options){
					if(option == "all"){outmap.erase(outmap.begin()); isAll = true; continue;}

					if(outmap.count(option) > 0 || isAll){
							if(isAll){
							
								if(iter != outmap.cend()){
								//cout << iter->first << ": " << iter->second << '\n';
								++iter;
								}
	
							}
							else{
								//cout << option << ": " << outmap.at(option) << '\n';

							}

							
					}
					else{
						cerr << "Invalid option provided: " << option << '\n';
						exit(EXIT_FAILURE);
					}
				}
			}



			//Output

		}

		else{		
			cerr << "Unreadable properties file provided!" << '\n';
			cerr << "Usage: " << argv[0] << "<-option1> | <-option2> | ... <properties_file> <file1> | <file2> | ... " << '\n';
			exit(EXIT_FAILURE);
		}
	}


	//File not found exception

	else{ 
		cerr << "Not enough arguments provided!" << '\n';	
		cerr << "Usage: " << argv[0] << "<-option1> | <-option2> | ... <properties_file> <file1> | <file2> | ... " << '\n';
		exit(EXIT_FAILURE);
	}
	return 0;
}

