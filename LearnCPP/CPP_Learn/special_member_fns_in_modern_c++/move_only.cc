#include <iostream>

using namespace std;

class Test {
public:
	// Default constructor
	Test() = default;
	/*
	// In effect, the copy operators are declared as deleted
	// Copy constructor 
	Test(const Test&other) = delete;
	
	// Copy assignment operator
	Test& operator =(const Test& other) = delete;
	*/
	
	// Move constructor
    Test(Test&& other) noexcept {
		cout << "Move constructor called" << endl;
    }
	
	// Move assignment operator
	Test& operator =(Test&& other) noexcept {
		cout << "Move assignment operator called" << endl;
		return *this;
	}
};

int main() {
	Test test;                         // OK - uses default constructor
	Test test2(std::move(test));       // OK - uses move constructor
	Test test3 = std::move(test);      // OK - uses move constructor
	//Test test4(test);                // Error! Use of deleted function
}