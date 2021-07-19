#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	string data;
	Test(string data)
	{
		this->data = data;
		cout << "Constructor invoked\n";
	}
	~Test() { cout << "Destructor invoked\n"; }
};

int main(int argc, char const *argv[])
{
	{
		unique_ptr<Test> uptr = make_unique<Test>("Unique");
		cout << uptr->data << "\n";
	}

	{
		shared_ptr<Test> sptr = make_shared<Test>("Shared");
		cout << sptr->data << "\n";
	}

	return 0;
}