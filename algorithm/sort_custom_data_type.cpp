#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
	Person(const string& name, int age): name_(name), age_(age) {}
	const string& getName() const { return name_; }
	const int getAge() const { return age_; }
	bool operator < (const Person& other) const {
		return this->getName() < other.getName();
	}
	static bool compareNameDESC(const Person& a, const Person& b) {
		return b.getName() < a.getName();
	}
private:
	string name_;
	int age_;
};

void output(const string& title, vector<Person>& person)
{
	cout<<title<<endl;
	for(const auto& p : person)
		cout<<"Name = "<<p.getName()<<" age = "<<p.getAge()<<endl;
	cout<<string(40,'-')<<endl;
}

int main() {
	
	vector<Person> person = { 
		Person("John", 35), 
		Person("Amay", 27),
		Person("Bob", 18)
		};
	
	auto ps1 = person;
	std::sort(ps1.begin(), ps1.end());
	output("sort by name using < operator", ps1);
	
	auto ps2 = person;
	std::sort(ps2.begin(), ps2.end(), 
		[](const Person & a, const Person & b) -> bool {
			return a.getAge() < b.getAge();
		});
	output("sort by age using lambda", ps2);
	
	auto ps3 = person;
	std::sort(ps3.begin(), ps3.end(), Person::compareNameDESC);
	output("sort by name DESC using comparison function", ps3);
	
	return 0;
}

/// output
sort by name using < operator
Name = Amay age = 27
Name = Bob age = 18
Name = John age = 35
----------------------------------------
sort by age using lambda
Name = Bob age = 18
Name = Amay age = 27
Name = John age = 35
----------------------------------------
sort by name DESC using comparison function
Name = John age = 35
Name = Bob age = 18
Name = Amay age = 27
----------------------------------------
