#include <string>

// Some horrible hash functions

class Hasher {
  public:
    unsigned operator()(int n) {
	return n % 8;
    }

    unsigned operator()(const std::string &s) {
	unsigned sum = 42;
	for (char c : s)
	    sum += c;
	return sum;
    }
};

