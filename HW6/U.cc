//Habeeb Mohammed
//15-04-2017
//HW6 -- Split!

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
#include <sstream>

using namespace std;

U::U(){
	acc = "";
	sizeVal = 0;
	callCount = 0;
}

U::U(const U &rhs){
	acc = rhs.acc;
	prop = rhs.prop;
	properties = rhs.properties;
	sizeVal = rhs.sizeVal;
	symArray = rhs.symArray;
	hexArray = rhs.hexArray;
	acc_vector = rhs.acc_vector;
	acc_str = rhs.acc_str;
	propmap = rhs.propmap;
	outmap = rhs.outmap;
}

const U& U::operator=(const U &rhs) {	
	acc = rhs.acc;
	prop = rhs.prop;
	properties = rhs.properties;
	sizeVal = rhs.sizeVal;
	symArray = rhs.symArray;
	hexArray = rhs.hexArray;
	acc_vector = rhs.acc_vector;
	acc_str = rhs.acc_str;
	propmap = rhs.propmap;
	outmap = rhs.outmap;
	
	return rhs;
}


U::U(string data){
	acc = "";
	sizeVal = 0;
	readfile(data);
	callCount = 0;	
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

vector<string> U::long2uni(vector<long> vl){
	int low = 0;
	int lower = 0;
	int lowerer = 0;
	int hi = 0;
	int decoded = 0;
	char tempchar;
	string tempstr = "";
	vector<string> str_vec;
	for(size_t i = 0; i < vl.size(); i++){
		if((vl.at(i) > 0) && (vl.at(i) < 127)){
			tempchar = vl.at(i);
			tempstr.push_back(tempchar);
			str_vec.push_back(tempstr);
			tempstr = "";
			continue;
		}

		if((vl.at(i) > 128) && (vl.at(i) < 2047)){
			low = (vl.at(i) & 0x003F);
			low = low + 0x0080;
			hi = (vl.at(i) & 0x07C0) << 2;
			hi = hi + 0xC000;
			decoded = (low | hi);
			char t1,t2;
			t1 = low;
			t2 = hi;
			tempstr.push_back(t2);
			tempstr.push_back(t1);
			str_vec.push_back(tempstr);
			tempstr = "";
			continue;
		}

		if((vl.at(i) > 2048) && (vl.at(i) < 65535)){
			lower = (vl.at(i) & 0x003F);
			low = (vl.at(i) & 0x0FC0) << 2;
			hi = (vl.at(i) & 0xF000) << 4;
			decoded = (hi | low | lower) + 0xE0A0A0;
			tempchar = decoded;
			tempstr.push_back(tempchar);
			str_vec.push_back(tempstr);
			tempstr = "";
			continue; 
		}
		
		if((vl.at(i) > 65536) && (vl.at(i) < 1114111)){
			lowerer = (vl.at(i) & 0x003F);
			lower = (vl.at(i) & 0x0FC0) << 2;
			low = (vl.at(i) & 0x03F0) << 4;
			hi = (vl.at(i) & 0x7000) << 6;
			decoded = (hi | low | lower | lowerer) + 0xF0A0A0A0;
			tempchar = decoded;
			tempstr.push_back(tempchar);
			str_vec.push_back(tempstr);
			tempstr= "";
			continue;
		}

	}

	return str_vec;	
}

void U::readfile(const string filename){
	ifstream input(filename);

	if((input.is_open()) && (filename != "")){
		char tempc;
		string temps;
		while(input.get(tempc)){
			temps.push_back(tempc);
		}
		if((callCount == 0) || (acc == "")){
			acc += temps;
			callCount++;
		}
		if((callCount > 0) && (acc != "")){
		vector<long> finalArray = uni2long(temps);
		acc_str = long2uni(finalArray);
		for(long element : finalArray){
			if(propmap.count(element) > 0){
				properties.push_back(propmap.at(element));
				acc_vector.push_back(outmap.at(element));
			}
		}
	input.close();	
	}
	}
	else {
		if(!(input.is_open()) && (filename != "")){
			if((callCount == 0) || (acc == "")){
				acc += filename;
				callCount++;
			}
			if((callCount > 0) && (acc != "")){
			vector<long> finalArray = uni2long(acc);
			acc_str = long2uni(finalArray);
			for(long element : finalArray){
				if(propmap.count(element) > 0){
					properties.push_back(propmap.at(element));
					acc_vector.push_back(outmap.at(element));
				}
			}
			input.close();
			}
		}
		else{
			throw string("U::readfile: can't open " + filename);
		}	
	}
}

/*void U::propfile(const string properties){
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
}*/



int U::size() const {
	
	return acc_vector.size();
}

string U::get() const {
	return acc;
}

string U::get(int index) const {
	return acc_str[index];
}

string U::get(int start, int limit) const {
	return acc.substr(start+1, limit-2);
} 

void U::append(string utf_str){
	//if((callCount == 0) || (acc == "")){
		acc += utf_str;
		readfile(acc);
		callCount++;
	/*if((prop == true) && (acc != "")){
	vector<long> finalArray = uni2long(acc);
	acc_str = long2uni(finalArray);
	for(long element : finalArray){
		if(propmap.count(element) > 0){
			properties.push_back(propmap.at(element));
			acc_vector.push_back(outmap.at(element));
		}

		}
	}*/
}

int U::codepoint(int index){
	string s = "";
	s.push_back(acc[index]);
	vector<long> result;
	result = uni2long(s);
	int res = result[0];
	cout << hex << res << '\n';
	return res;
	
}

bool U::empty() const{
	if(acc == ""){
		return true;
	}
	else return false;
}

void U::clear(){
	acc = "";
	prop = false;
	sizeVal = 0;
	propmap.clear();
	outmap.clear();

}

