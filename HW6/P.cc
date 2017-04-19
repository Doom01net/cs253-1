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
#include "P.h"
#include <bitset>
#include <sstream>

using namespace std;

P::P(){
	acc = "";
	sizeVal = 0;
	prop = false;
}

P::P(const P &rhs){
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

const P& P::operator=(const P &rhs) {	
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

P::P(string properties){
	prop = true;
	sizeVal = 0;
	acc = "";
	readfile(properties);

}

void P::readfile(const string properties){
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

                input.close();
                if(prop == false){
                        prop = true;
                        readfile(acc);
                }
        }
        else throw string("Invalid properties file given to propfile()!");

}

P::~P(){}

void P::count(int codepoint){
	for(auto h : hexArray){
		if(codepoint == h){
			//count++;
		}
	}
}

int P::count(string prop_name){
	//needs a map analysis
}
set<string> P::props(){

	set<string> props_set;
	for(auto p : symArray){
		props_set.insert(p);
	}
	return props_set;
}

bool P::empty() const{
	if(symArray.empty()){
		return true;
	}
	else return false;
}

void P::clear(){
	acc = "";
	sizeVal = 0;
	prop = false;
	symArray.clear();
}


