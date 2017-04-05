#include <iostream>
using namespace std;

class Worker {
  public:
    Worker() { clog << __PRETTY_FUNCTION__ << '\n'; }
    int ss_num;
};

class CSU_Employee : public Worker {
  public:
    int employee_id;
};

class FCC_Employee : public Worker {
  public:
    int employee_id;
};

class Jack : public CSU_Employee, public FCC_Employee {
  public:
    int number_of_comics;
};

int main() {
    Jack j;
    j.number_of_comics = 1000003;	// OK
    //j.employee_id = 3;			// ambiguous
    j.ss_num = 362269871;		// ambiguous
    // Worker *w = &j;
    // CSU_Employee *c = &j;
    // FCC_Employee *f = &j;
}

