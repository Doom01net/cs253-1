#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
	Complex zero;
	Complex five(5.0);
	{
	Complex five2(five);
	Complex five3;
	five3 = five;
	Complex five4;
	five4 = 5.0;
	Complex one_plus_twoi(1,2);

	cout << __func__ << " begins\n";
	cout << "Should be 0+0i: " << zero << '\n';
	cout << "Should be 1+2i: " << one_plus_twoi << '\n';;
	cout << "Should be 5+0i: " << five << '\n';
	cout << "Should be 5+0i: " << five2 << '\n';
	cout << "Should be 5+0i: " << five3 << '\n';
	cout << "Should be 5+0i: " << five4 << '\n';

	double d = five4.real();
	cout << "Should be 5: " << d << '\n';
	}

	Complex a(1.1,2.2), b(3.3, 4.4);
	Complex c = a+b;
	cout << "Should be 4.4+6.6i: " << c << '\n';

	cout << "Should be 2.1+2.2i: " << ++a << '\n';
	cout << "Should be 2.1+2.2i: " << a++ << '\n';
	cout << "Should be 3.1+2.2i: " << a << '\n';

	cout << "Should be 10+20i: " << Complex(1.0,2.0)*10.0 << '\n';
	cout << "Should be 4+2i: " << Complex(44,22)/11.0 << '\n';

	cout << "Count is " << Complex::get_count() << '\n';
	cout << "Count is " << zero.get_count() << '\n';
	cout << __func__ << " ends\n";
}
