#include <iostream>
#include <sstream>

using namespace std;

class Number {
  public:
    Number() : value(0) {}
    Number(int v) : value(v) {}
    Number &operator=(int n) { value = n; return *this; }
    Number &operator=(string s){ yourstring = s; return *this;}
    operator int() const { return value; }
  private:
    int value;
    string yourstring;
};

istream &operator>>(istream &is, Number &rhs) {
    int n;
    string strang;
    is >> n;
	if(is.fail()){
		is >> strang;
	        rhs = strang;
		return is;
	}
     rhs = n;
    return is;
}


int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    while (ss >> n)
	cout << n << ' ';
    cout << '\n';
}
