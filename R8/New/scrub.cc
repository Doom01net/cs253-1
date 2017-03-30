#include <iostream>
#include <cstdlib>		// for malloc(), free()
#include <cstring>		// for memset()

using namespace std;

void *operator new(size_t size) throw(bad_alloc) {
    void *p = malloc(size);
    cout << "new(" << size << ") returns " << p << '\n';
    return memset(p, 'q', size);	    // Fill memory with the letter 'q'
}

void operator delete(void *p) throw() {
    cout << "delete(" << p << ")\n";
    free(p);
}

// Perhaps we should be filling the memory with nonsense during
// delete, not new.  However, it’s harder to figure out what the
// size is when delete is called, so we compromise.

int main() {
    int *p = new int;
    cout << "Our int is: " << *p << '\n';
    delete p;
    return 0;
}
