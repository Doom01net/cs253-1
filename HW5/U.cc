//Habeeb Mohammed
//27-03-2017
//HW5 -- Classes

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ostream>
#include <istream>
#include <map>
#include <set>
#include "U.h"

using namespace std;

U::U(){
	acc = "";
	sizeVal = 0;
	charCount = 0;
}

U::U(const U &rhs){
	acc = rhs.acc;
	properties = rhs.properties;
	sizeVal = rhs.sizeVal;
	symArray = rhs.symArray;
	hexArray = rhs.hexArray;
	propmap = rhs.propmap;
}

U::U(string properties, string data){
	propfile(properties);
	readfile(data);
	
}

U::~U(){}

vector<long> U::uni2long(string uni){

	vector<long> uniArray;	
	vector<long> byteArray;
	vector<long> asciiBytes;
	for(char i : uni){
		long bits = 0;
		int cleared = 0;
		bits = i;
		if(bits >= 0 && bits < 128){
			uniArray.push_back(bits);
		}
		cleared = bits & 0x000000ff;
		byteArray.push_back(cleared);
	}
	long masked1, masked2, masked3, masked4;
	long byte;
	for(size_t i = 0; i < byteArray.size(); i++){
	
		if((byteArray[i] & 0x80) == 0){
		
		}
	 
		else if(((byteArray[i] & 0xF0) == 0xF0) && (byteArray[i] & 0x08) == 0){
			masked1 = (byteArray[i] & 0x07);
			byte = byteArray[i];
			i++;

			if((byteArray[i] & 0x80) == 0x80) {
				masked2 = (byteArray[i] & 0x3F) << 12; 
				byte = byteArray[i];
				i++;

				if((byteArray[i] & 0x80) == 0x80) {
					masked3 = (byteArray[i] & 0x3F) << 6;
					byte = byteArray[i];
					i++;

					if((byteArray[i] & 0x80) == 0x80) {
						masked4 = (byteArray[i] & 0x3F);
						byte = byteArray[i];	
					}
					else{
		
						throw string("Invalid UTF-8 character given!");
							
					}

				
				}
				else{

					throw string("Invalid UTF-8 character given!");
				}
				
			}
			else{

				throw string("Invalid UTF-8 character given!");

			}	
			byte = masked1 | masked2 | masked3 | masked4;
			uniArray.push_back(byte);
		}
		else if((byteArray[i] & 0xE0) == 0xE0){
			masked1 = (byteArray[i] & 0x07) << 12;
			byte = byteArray[i];
			i++;

			if((byteArray[i] & 0x80) == 0x80) {
				masked2 = (byteArray[i] & 0x3F) << 6;
				byte = byteArray[i];
				i++;

				if((byteArray[i] & 0x80) == 0x80) {
					masked3 = (byteArray[i] & 0x3F);
					byte = byteArray[i];
				}
				else{
				
					throw string("Invalid UTF-8 character given!");
				}
			}
			else{
				throw string("Invalid UTF-8 character given!");
			}

			byte = masked1 | masked2 | masked3;
			uniArray.push_back(byte);
		}
		else if(((byteArray[i] & 0xC0) == 0xC0) && (byteArray[i] & 0x20) == 0){
			masked1 = (byteArray[i] & 0x1F) << 6;
			byte = byteArray[i];
			i++;

			if((byteArray[i] & 0x80) == 0x80) {
				masked2 =(byteArray[i] & 0x3F);
				byte = byteArray[i];
			}
			else{
				throw string("Invalid UTF-8 character given!");
			}
			
			byte = masked1 | masked2;
			uniArray.push_back(byte);
		}
			
	}
	return uniArray;
}

void U::readfile(const string filename){
	ifstream input(filename);

	if((input.is_open()) && (filename != "")){
		char tempc;
		string temps;
		while(input.get(tempc)){
			temps.push_back(tempc);
		}
		acc += temps;
		cout << "accumulated string size: " << acc.size() << '\n';
		vector<long> finalArray = uni2long(acc);
		charCount += finalArray.size();
		for(long element : finalArray){
			cout << "Element: " << element << '\n';
			if(propmap.count(element) > 0){
				properties.push_back(propmap.at(element));
			}
		}
	input.close();	
	}
	else if(!(input.is_open() && (filename != ""))){
		acc += filename;
		cout << "accumulated string size2: " << acc.size() << '\n';
		vector<long> finalArray = uni2long(acc);
		charCount += finalArray.size();
		for(long element : finalArray){
			cout << "Element2: " << element << '\n';
			if(propmap.count(element) > 0){
				properties.push_back(propmap.at(element));
			}
		}
	input.close();
	}

	cout << "Accumulated string: " << acc << '\n';
}

void U::propfile(const string properties){
	ifstream input(properties);

	if((input.is_open()) && (properties != "")){
	
         	//Store each line of properties file into vector

                vector<string> strArray;
                string line;

                        while( getline(input, line) ){

                                strArray.push_back(line);

                        }

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

                        for( size_t i = 0; i < symArray.size(); i++ ){

                                string symbol = symArray[i];
                                propmap.insert( pair<long,string>(hexArray[i], symbol) );
                        }

	input.close();
	}
	else throw string("Invalid properties file given to propfile()!");
}

int U::size() const {
	return properties.size();
}

string U::get() const {
	return acc;
}

string U::get(int index) const {
	string result = "" + acc.at(index);
	return result;
}

string U::get(int start, int limit) const {
	return acc.substr(start+1, limit-2);
} 

int U::propcount(const string property) const {
	int result = 0;
	for(string s : properties){
		if(property == s){
			result++;
		}	
	}
	return result;	
}

set<string> U::props(){
	set<string> allprops;

	for(string property : symArray){
		allprops.insert(property);
	}
	
	return allprops;
}
