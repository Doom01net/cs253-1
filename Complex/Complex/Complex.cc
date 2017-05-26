#include "Complex.h"
#include <cmath>			// for sqrt()

using namespace std;

// Got to define this somewhere.
int Complex::count = 0;

// Constructor
//
// This also functions as the zero-argument (default) ctor due to the
// default arguments specified in Complex.h.

Complex::Complex(double real, double imag) {
    re = real;
    im = imag;
    invalidate_absolute_value();
    count++;
}

// Copy constructor
//
// As a constructor, it has no return type.
// The argument must be a const reference.
// • const, because we have to be able to initialize from a read-only object
// • reference, because what’s the alternative?  Calling by value?
//   That would require COPYING the value.  But THIS is the copy ctor!
//
// Always use member initialization, unless you can’t.

Complex::Complex(const Complex &rhs) : re(rhs.re), im(rhs.im),
				       absolute_value(rhs.absolute_value) {
    count++;
}

// Destructor
//
// Since there is now one fewer Complex object, decrement the object count.
// Don’t bother clearing the member variables--they’re doomed to die
// in just a moment.  It would be like painting a condemned building.

Complex::~Complex() {
    count--;
}

// Assignment operator
//
// All assignment operators return a reference to the assigned object,
// so that we can chain assignments: a=b=c=d;
// The argument must be a const reference.
// • const, because we have to be able to copy a read-only object
// • reference, because passing by value is slow.

Complex &Complex::operator=(const Complex &rhs) {
    re = rhs.re;
    im = rhs.im;
    absolute_value = rhs.absolute_value;
	cout <<  this << '\n';
    return *this;
}

// A simple accessor (alias a “getter”).
//
// It’s declared const so that we can call it on a const object.
double Complex::real() const {
    return re;
}

double Complex::imag() const {
    return im;
}

// The complex conjuate of a+bi is a-bi.
// This is a const method.  It does NOT change the current object.
// It creates a new object and returns it by value.  Don’t return by
// reference, because the object retval vanishes when this function
// finishes.

Complex Complex::conj() const {
    Complex retval(re, -im);
    return retval;
}

// Return the absolute value of a complex number.
// The absolute value of a+bi is defined as the square root of a²+b².
double Complex::abs() const {
    // For educational purposes, assume that computing a square root is
    // very expensive, so remember the value once we compute it.

    // If the absolute value needs computing, compute it now.
    // Hey, this method is const--how can we change absolute_value?

    if (absolute_value < 0)			// First time?
	absolute_value = sqrt(re*re + im*im);	// Yes; do the hard work.
    return absolute_value;
}

// This method is private.  It’s used to invalidate our cached
// absolute value when the values in this object change.
//
// Sure, it seems silly to have a whole method to just assign -1
// to a variable.  However, which is easier to understand:
// calling a method named “invalidate_absolute_value”, or assigning
// -1 to a data member?
//
// If you’re concerned about execution speed, then measure it.
// Reasoning and guesswork are fine, but data is what counts.
// A decent compiler will inline the call to invalidate_absolute_value(),
// which means that calling it has NO runtime overhead.  Win!

void Complex::invalidate_absolute_value() {
    absolute_value = -1;
}

// This is a static method.  That means that it doesn’t access any
// non-static data members, and so may be called without an object.
// It doesn’t have be declared const, because it can’t access
// non-static data members.

int Complex::get_count() {
    return count;
}

// Implement the addition operator.  Since this is a member function,
// the left-hand operand is implicitly the current object (*this).
//
// It’s const because this operator does NOT change the current object.
// It creates a new one.
//
// By convention, the argument is called rhs for Right-Hand Side.
// The argument should be a const reference, for the same reasons
// given in assignment operator.
//
// It returns a new object, by value.  It can’t return by reference,
// because any local object will go away when the function finishes.

Complex Complex::operator+(const Complex &rhs) const {
    Complex retval;
    retval.re = re+rhs.re;
    retval.im = im+rhs.im;
    return retval;
}

Complex Complex::operator-(const Complex &rhs) const {
    // Rather than create a new named object and return it,
    // it’s easier to create a temporary object and return that.
    return Complex(re-rhs.re, im-rhs.im);
}

Complex Complex::operator+(double d) const {
    return Complex(re+d, im);
}

Complex Complex::operator-(double d) const {
    return Complex(re-d, im);
}

Complex Complex::operator*(double factor) const {
    return Complex(re*factor, im*factor);
}

Complex Complex::operator/(double factor) const {
    return Complex(re/factor, im/factor);
}

// Unlike operator+, this += operator indeed changes the current object.
// Therefore, it’s not const.
//
// Like the plain assignment operator:
// All assignment operators return a reference to the assigned object,
// so that we can chain assignments: a=b=c=d;
// The argument must be a const reference.
// • const, because we have to be able to copy a read-only object
// • reference, because passing by value is time-consuming

Complex &Complex::operator+=(const Complex &rhs) {
    re += rhs.re;
    im += rhs.im;
    invalidate_absolute_value();
    return *this;
}

Complex &Complex::operator-=(const Complex &rhs) {
    re -= rhs.re;
    im -= rhs.im;
    invalidate_absolute_value();
    return *this;
}

// The previous operator += added a Complex to a Complex.
// This += adds a double to a Complex.

Complex &Complex::operator+=(double d) {
    re += d;
    invalidate_absolute_value();
    return *this;
}

// For -=, just negate the value and invoke +=.
// That way, += does all the real work.  This avoids duplicating code.

Complex &Complex::operator-=(double d) {
    return *this += -d;			// Let += do the work
}

Complex &Complex::operator*=(double d) {
    re *= d;
    im *= d;
    invalidate_absolute_value();
    return *this;
}

Complex &Complex::operator/=(double d) {
    // I suppose that we could implement this via *=, but that
    // would require inverting d, which strikes me as inefficient.
    re /= d;
    im /= d;
    invalidate_absolute_value();
    return *this;
}

// This is the pre-increment operator, because it has no argument.
// It invokes += to do the real work.

const Complex &Complex::operator++() {
    *this += 1.0;			// Let += do the work
    return *this;
}

// This is the post-increment operator, because it has a dummy int argument.
// Crazy, huh?
//
// It must return the value as it was before incrementing.
// Therefore, save the value, increment the object using pre-increment,
// and then return the saved value.
// Since it uses pre-increment to do the actual work of incrementing,
// then we have no duplication of code.  Happy happy joy joy!

Complex Complex::operator++(int) {    	// Post-increment
    const Complex temp = *this;		// Save old value
    ++*this;				// Invoke pre-increment
    return temp;			// Return old value
}

const Complex &Complex::operator--() { 	// Pre-decrement
    *this -= 1.0;			// Let -= do the work
    return *this;
}

Complex Complex::operator--(int) {    	// Post-decrement
    const Complex temp = *this;		// Save old value
    --*this;				// Invoke pre-decrement
    return temp;			// Return old value
}

// This is the insertion (output) operator, a non-member function.
// It must be a non-member function.  If it were a member function,
// it would have to be a member of the ostream class, because that’s
// the left-hand argument.  You can’t modify the ostream class, because
// you didn’t write it, so that’s not possible.
//
// The first argument is a non-const ostream reference:
// • non-const because we’re changing the stream by writing to it
// • a reference because you can’t copy an I/O stream.
//
// The second argument is a const reference.
// • const, because we have to be able to insert a read-only object
// • reference, because passing by value is time-consuming
//
// Why don’t we insert a space or a newline after the 1+2i?
// Because that’s not our job.  Imagine how annoying it would be
// if the statement cout << 5; inserted "5 " or "5\n".  NO!!!
// It should just insert the value, AND THAT IS ALL.

std::ostream &operator<<(std::ostream &stream, const Complex &val) {
    return stream << val.real() << '+' << val.imag() << 'i';
}
