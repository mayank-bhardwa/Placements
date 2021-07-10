#include <iostream>
#include <memory>
#include <ostream>
using namespace std;

class Employee
{
	int empid;
	string empName;

public:
	Employee(string name, int empid)
	{
		this->empid = empid;
		this->empName = name;
	}

	~Employee()
	{
		cout << "\nDestructor";
	}

	friend void operator<<(ostream &, Employee);
};

void operator<<(ostream &out, Employee e)
{
	out << e.empName << " " << e.empid << " ";
}

int main(int argc, char const *argv[])
{
	{
		Employee *emp = new Employee("Ram", 243);
		unique_ptr<Employee> uptr(emp);
		cout << *emp;
	}

	{
		Employee *emp = new Employee("Ram", 234);
		auto_ptr<Employee> aptr(emp);
		cout << *emp;
	}
	return 0;
}