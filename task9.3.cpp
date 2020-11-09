#include <iostream>

using namespace std;

class Person
{
public:
	
    enum PESRON_TYPE
	{
		terrorist = 0, counter_terrorist, hostage
	};
	
private:


    Person(Person::PESRON_TYPE type) : type(type) {}



	PESRON_TYPE type;


	friend ostream& operator<<(ostream&, Person&);
    friend class Factory;
};

class Factory
{
public:

    Person createPerson(Person::PESRON_TYPE type)
    {
        return Person(type);
    }

};

ostream& operator<<(ostream& out, Person& p)
{
    out << "type: " << (p.type == Person::PESRON_TYPE::terrorist ? "terrorist" 
    : (p.type == Person::PESRON_TYPE::counter_terrorist ? "counter-terrorist" : "hostage")) << "\n";
    
    return out;
}

int main()
{

    Person p = Factory().createPerson(Person::PESRON_TYPE::hostage);

    cout << p;

	return 0;
}

