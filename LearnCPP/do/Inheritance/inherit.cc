#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Write an inheritance hierarchy with three classes: Base, Child and Grandchild.
class Base 
{
	int m_base = 5;
public:
	virtual void print() const { cout << "Base: " << m_base << endl; }
};

class Child : public Base
{
	int m_child = 3;
public:
	void print() const { cout << "Child: " << m_child << endl; }
};

class Grandchild : public Child
{
	int m_grandchild = 1;
public:
	void print() const { cout << "Grandchild: " << m_grandchild << endl; }
};

int main()
{
	// Create a vector of Base pointers and add a Base, Child and Grandchild to it.
	vector<Base*> v;
	v.push_back(new Base);
	v.push_back(new Child);
	v.push_back(new Grandchild);

	// Iterate through the vector and call print() on each element.
	for (auto& e : v)
		e->print();

	// Delete all the elements in the vector.
	for (auto& e : v)
		delete e;

	return 0;
}