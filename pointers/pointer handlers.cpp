#include <iostream>
#include <memory>
#include <ostream>
using namespace std;

class Test
{
	int data;

public:
	Test(int data)
	{
		this->data = data;
		cout << "Constructor invoked\n";
	}
	~Test() { cout << "Destructor invoked\n"; }
};

int main(int argc, char const *argv[])
{
	{
		unique_ptr<Test> uptr = make_unique<Test>(54);
	}

	return 0;
}