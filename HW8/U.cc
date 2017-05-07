//Habeeb Mohammed
//06-05-2017
//HW8 -- Containers
#include "U.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <ostream>
using namespace std;

U::U(){
}
U::U(const U &rhs) : acc(rhs.acc), codepoints(rhs.codepoints){
}
U::U(const string filename){
        readfile(filename);
}
U::~U(){
}
//--------------------------------------------------------
U::iterator::iterator(){}
U::iterator::iterator(const U::iterator &rhs){
	current = rhs.current;
}
U::iterator::~iterator(){}

bool operator==(const U::iterator &lhs, const U::iterator &rhs){
	if((lhs.current == rhs.current)){
		return true;
	} else return false;
}
bool operator!=(const U::iterator &lhs, const U::iterator &rhs){
	return !(lhs == rhs);
}
U::iterator& U::iterator::operator++() {
	current++;
	return *this;
}
U::iterator U::iterator::operator++(int i){
	U::iterator iter = *this;
	++*this;
	return iter;
}
U::iterator& U::iterator::operator--(){
	current--;
	return *this;
}
U::iterator U::iterator::operator--(int i){
	U::iterator iter = *this;
	--*this;
	return iter;
}
int U::iterator::operator*(){
	return *this->current;
}


//--------------------------------------------------------
U::iterator U::end(){
	U::iterator iter;
	iter.current = &codepoints[codepoints.size()];
	return iter;
}

U::iterator U::begin(){
	U::iterator iter;
	iter.current = &codepoints[0];
	return iter;
}
int U::front(){
	return codepoint(0);
}
int U::back(){
	return codepoint(codepoints.size() - 1);
}

U& U::operator=(const U &rhs){
    acc = rhs.acc;
    codepoints = rhs.codepoints;
    return *this;
}
void U::operator=(string rhs){
	acc.clear();
	acc.push_back(rhs);
}
U U::operator+(const U &rhs){
	U u;
	u.acc = this->acc;
	for(string s : rhs.acc){
		u.acc.push_back(s);
	}
	u.codepoints = this->codepoints;
	return u;
}
U U::operator+(const string s){
	U u;
	u.acc = this->acc;
	u.acc.push_back(s);
	u.codepoints = this->codepoints;
	return u;
}
U operator+(const string lhs, const U &rhs){
	U u;
	u.acc.push_back(lhs);
	for(string a : rhs.acc){
		u.acc.push_back(a);
	}
	return u;
	
}
U U::operator+=(const string s){
	U u;
	u.acc = this->acc;
	u.acc.push_back(s);
	u.codepoints = this->codepoints;
	return u;
}
U U::operator+=(const U &rhs){
	U u;
	u.acc = this->acc;
	for(string s : rhs.acc){
		u.acc.push_back(s);
	}
	u.codepoints = this->codepoints;
	return u;
}
string U::operator[](int index) const{
	if(index < (int)this->acc.size()){
		return acc[index];
	}
	else throw string("U::operator[] given invalid index");
}
ostream& operator<<(ostream &out, const U &rhs){
	for(char s : rhs.get()){
		out << s;
	}
	return out;
}
U::operator bool() const{
	return !empty();
}

bool U::operator!(){
	return empty();
}
bool operator==(const U &lhs, const U &rhs){
	return (lhs.get() == rhs.get());
}
bool operator!=(const U &lhs, const U &rhs){
	return !(lhs == rhs);
}
bool operator==(const U &lhs, const string rhs){
	return (lhs.get() == rhs);
}
bool operator==(const string lhs, const U &rhs){
	return (lhs == rhs.get());
}
bool operator!=(const U &lhs, const string rhs){
	return !(lhs == rhs);
}
bool operator!=(const string lhs, const U &rhs){
	return !(rhs == lhs);
}
void U::readfile(const string filename){
    ifstream read(filename);
        if(!read.is_open()){
            throw string("U:readfile(string filename): Failed to read file: " + filename);
        }
        char c;
        while(read.get(c)){
            string ret = "";
            ret += c;
            int byteCount = countBytes(c);
            int thisByte = c;
            if(byteCount == -1){break;}
            thisByte &= 0x0FF;
            for(int i = 0; i < byteCount; i++){
                thisByte <<= 8;
                if(!read.get(c)){
                    stringstream ss;
                    ss << "U::readfile(string filename): Invalid Unicode characters given: " << hex << (thisByte) << dec;
                    throw string(ss.str());
                }
                int x = c;
                if((x & 0xC0) != 0x80){
                    stringstream ss;
                    ss << "U::readfile(string filename): Invalid byte: " << hex << (x & 0xFF) << dec;
                    throw string(ss.str());
                }
                ret += c;
                thisByte = (thisByte | 0x0FF) & x;
            }
            if(byteCount != 0)
                thisByte = decoder(thisByte, byteCount);
            codepoints.push_back(thisByte);
            acc.push_back(ret);
        }
}

void U::append(const string literal){
    reader(literal);
}
string U::get() const{
    string ret = "";
    for(auto a: acc)
        ret += a;
    return ret;
}
string U::get(const int index) const{
    if(index < 0 || index >= (int)acc.size())
        throw string("Index out of range.");
    return acc.at(index);
}
string U::get(const int start, const int end) const{
    if(start < 0 || start >= (int)acc.size())
        throw string(("U::get(int start, int end): Invalid index given"));
    if(end < 0 || end > (int)acc.size())
        throw string("U::get(int start, int end): Invalid index given");
    if(start > end)
        throw string("U::get(int start, int end): Invalid arguments given");
    string ret = "";
    for(int i = start; i < end; i++){
        ret += acc.at(i);
    }
    return ret;
}
int U::codepoint(const int index) const{
    if(index < 0 || index >= (int)codepoints.size())
        throw string("U::codepoint(int index): index out of range.");
    return codepoints.at(index);
}
int U::size() const{
    return acc.size();
}
bool U::empty() const{
    if(size() == 0){
	return true;
    }
    else return false;
}
void U::clear(){
    acc.clear();
    codepoints.clear();
}

//_________________________________________

int U::countBytes(const char c){
    int i = c;
    if((i & 0x80) == 0){ return 0;}
    else if((i & 0xE0) == 0xC0){ return 1;}
    else if((i & 0xF0) == 0xE0){ return 2;}
    else if((i & 0xF8) == 0xF0){ return 3;}
    else {
        stringstream ss;
        ss << "U::countBytes given invalid byte: " << hex << (i & 0xFF) << dec;
        throw string("U::countBytes given invalid UTF-8 format: '" + ss.str());
        return -1;
    }
}

int U::decoder(int coded, const int bytes){
    switch(bytes){
        case 1:
            return ((((coded & 0x1F00) >> 2) | (coded & 0x003F)) & 0x07FF);
        case 2:
            return ((((coded & 0x0F0000) >> 4) | ((coded & 0x003F00) >> 2) | (coded & 0x00003F)) & 0x0FFFF);
        case 3:
            return ((((coded & 0x03000000) >> 6) | ((coded & 0x003F0000) >> 4) | ((coded & 0x00003F00) >> 2) | (coded & 0x0000003F)) & 0x01FFFFF);
        default:
            return -1;
    }
}

void U::reader(const string data){

    acc.clear();
    for(int i = 0; i < (int)data.size(); i++){
        char c = data.at(i);
        string ret = "";
        ret += c;
        int byteCount = countBytes(c);
        int thisByte = c;
        if(byteCount == -1){break;}
        thisByte &= 0x0FF;
        for(int j = 0; j < byteCount; j++){
            thisByte <<= 8;
            char a = data.at(++i);
            int x = a;
            ret += a;
            thisByte = (thisByte | 0x0FF) & x;
        }
        if(byteCount != 0)
                thisByte = decoder(thisByte, byteCount);
        codepoints.push_back(thisByte);
        acc.push_back(ret);
    }
}

