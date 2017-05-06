//Habeeb Mohammed
//29-04-2017
//HW7 -- Operators
#include "P.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

P::P(){}
P::P(string propfile){
	readfile(propfile);
	counter = 0;
}
P::P(const P &rhs){
	propmap = rhs.propmap;
	symArray = rhs.symArray;
	hexArray = rhs.hexArray;
	unicodes = rhs.unicodes;
	counter = rhs.counter;
}
P& P::operator=(const P &rhs){
	propmap = rhs.propmap;
	symArray = rhs.symArray;
	hexArray = rhs.hexArray;
	unicodes = rhs.unicodes;
	counter = rhs.counter;
	return *this;
}
P::~P(){}

P::operator bool(){
	if(this->symArray.empty()){
		return true;
	}
	else return false;
}
bool P::operator!(){
	if(this->symArray.empty()){
		return false;
	}
	else return true;
}
void P::readfile(const string properties){
	ifstream input(properties);
	if(input.is_open()){
		vector<string> strArray;
		string line;
		while(getline(input, line)){
			strArray.push_back(line);
		}
		for(auto s : strArray){
			string delim = ";";
			string key;
			
			//populate hexArray which holds int values of UTF8 codepoints
			//populate unicodes which holds string values of UTF8 codepoints
			long hexVal;
			size_t position1 = s.find(delim);
			hexVal = stol(s.substr(0,position1).c_str(),nullptr,16);
			unicodes.push_back(s.substr(0,position1));
			hexArray.push_back(hexVal);
			
			//populate symArray which holds property strings
			string s1 = s.substr(position1);
			size_t position2 = s1.find(delim);
			string s2 = s1.substr(position2+1);
			size_t position3 = s2.find(delim);
			string s3 = s2.substr(position3+1);
			key = s3.substr(0,2);
			symArray.push_back(key);	
		}
		for(size_t i = 0; i < symArray.size(); i++){
			propmap.insert(pair<long,string>(hexArray[i], symArray[i]));
			countmap.insert(pair<string,int>(symArray[i], 0));
		}
	}
	else throw string("P::readfile given invalid properties file!");

}

set<string> P::props(){
	set<string> retset;
	for(string s : symArray){
		retset.insert(s);
	}
	return retset;
}
void P::count(int codepoint){
	if(propmap.count(codepoint) > 0){
		 countmap.at(propmap.at(codepoint))++;
	}
}
int P::count(string prop_name){
	return countmap.at(prop_name);
}
int P::size() const {
	set<string> retset;
	for(string s : symArray){
		retset.insert(s);
	}
	return retset.size();
}
bool P::empty() const {
	if(symArray.size() == 0){
		return true;
	}
	else return false;
}
void P::clear(){
	propmap.clear();
	symArray.clear();
	hexArray.clear();
	unicodes.clear();
	countmap.clear();
	counter = 0;
}
