// This class is certainly inadequate.  It has no include guards,
// is missing several ctors, no assignment operator, etc.
#include <iostream>
template <typename T, int N>
class fix {
  public:
    typedef unsigned int size_type;
    class iterator {
      public:
	iterator() : base(nullptr), index(0) {}
	iterator(fix *b, size_type i) : base(b), index(i) {}
        iterator &operator++() {
	    if(index > base->size()){
		std::cerr << "Index out of bound" << '\n';	
		exit(0);
	    }
            else{
	    index++;
	    }
	    return *this;
	}
	T &operator*() {
	    return (*base)[index];
	}
      private:
	fix *base;
	size_type index;
    };

    size_type size() const {
	return N;
    }
    T &operator[] (size_type index) {
	return data[index];
    }
    iterator begin() {
	return iterator(this, 0);
    }
    iterator end() {
	return iterator(this, N);
    }
  private:
    T data[N];
};
