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
#include <bitset>

using namespace std;

U::U(){
	acc = "";
	sizeVal = 0;
	//charCount = 0;
	prop = false;
}

U::U(const U &rhs){
	acc = rhs.acc;
	prop = rhs.prop;
	properties = rhs.properties;
	sizeVal = rhs.sizeVal;
	symArray = rhs.symArray;
	hexArray = rhs.hexArray;
	propmap = rhs.propmap;
}

U::U(string properties, string data){
	acc = "";
	sizeVal = 0;
	prop = true;
	propfile(properties);
	readfile(data);
	
}

U::~U(){}

vector<long> U::uni2long(string uni){

	vector<long> uniArray;	
	vector<long> byteArray;
	vector<long> asciiBytes;
	string whole = "";
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

vector<char> U::long2uni(vector<long> vl){
	int low = 0;
	int lower = 0;
	int lowerer = 0;
	int hi = 0;
	int decoded = 0;
	char tempchar;
	vector<char> char_vec;
	for(size_t i = 0; i < vl.size(); i++){
		if((vl.at(i) > 0) && (vl.at(i) < 127)){
			tempchar = vl.at(i);
			char_vec.push_back(tempchar);
			continue;
		}

		if((vl.at(i) > 128) && (vl.at(i) < 2047)){
			low = (vl.at(i) & 0x003F);
			hi = (vl.at(i) & 0x07C0) << 2;
			decoded = (low | hi) + 0xC080;	
			tempchar = decoded;
			char_vec.push_back(tempchar);
			continue;
		}

		if((vl.at(i) > 2048) && (vl.at(i) < 65535)){
			lower = (vl.at(i) & 0x003F);
			low = (vl.at(i) & 0x0FC0) << 2;
			hi = (vl.at(i) & 0xF000) << 4;
			decoded = (hi | low | lower) + 0xE0A0A0;
			tempchar = decoded;
			char_vec.push_back(tempchar);
			continue; 
		}
		
		if((vl.at(i) > 65536) && (vl.at(i) < 1114111)){
			lowerer = (vl.at(i) & 0x003F);
			lower = (vl.at(i) & 0x0FC0) << 2;
			low = (vl.at(i) & 0x03F0) << 4;
			hi = (vl.at(i) & 0x7000) << 6;
			decoded = (hi | low | lower | lowerer) + 0xF0A0A0A0;
			tempchar = decoded;
			char_vec.push_back(tempchar);
			continue;
		}

	}
	return char_vec;	
}

void U::readfile(const string filename){
	ifstream input(filename);

	if((input.is_open()) && (filename != "")){
		char tempc;
		string temps;
		while(input.get(tempc)){
			temps.push_back(tempc);
		}
		if((prop == false) || (acc == "")){
		acc += temps;
		}
		if((prop == true) && (acc != "")){
		//cout << "accumulated string size: " << acc.size() << '\n';
		vector<long> finalArray = uni2long(temps);
		acc_chars = long2uni(finalArray);
		//charCount += finalArray.size();
		for(long element : finalArray){
			//cout << "Element: " << element << '\n';
			if(propmap.count(element) > 0){
				properties.push_back(propmap.at(element));
				acc_vector.push_back(outmap.at(element));
				//acc += propmap.at(element);
				//outmap.at(propmap.at(element))++;
			}
		}
	input.close();	
	}
	}
	else if(!(input.is_open()) && (filename != "")){
		if((prop == false) || (acc == "")){
			acc += filename;
		}
		//cout << "accumulated string size2: " << acc.size() << '\n';
		if((prop == true) && (acc != "")){
		vector<long> finalArray = uni2long(acc);
		acc_chars = long2uni(finalArray);
		//charCount += finalArray.size();
		for(long element : finalArray){
			if(propmap.count(element) > 0){
				properties.push_back(propmap.at(element));
				acc_vector.push_back(outmap.at(element));
				//acc += propmap.at(element);
				//outmap.at(propmap.at(element))++;
			}
		}
	input.close();
	}
	}
	
	//cout << "Accumulated string: " << acc << '\n';
}

void U::propfile(const string properties){
	ifstream input(properties);

	if((input.is_open()) && (properties != "")){
	
         	//Store each line of properties file into vector

                vector<string> strArray;
		vector<string> unicodes;
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
				unicodes.push_back(s.substr(0,position1));
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
				string uni = unicodes[i];
                                propmap.insert( pair<long,string>(hexArray[i], symbol) );
				outmap.insert( pair<long,string>(hexArray[i], uni) );
                        }
	
	
		input.close();
		if(prop == false){
			prop = true;
			readfile(acc);
		}
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
	string tempstr = "";
	tempstr.push_back(acc_chars.at(index));
	return tempstr;
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
