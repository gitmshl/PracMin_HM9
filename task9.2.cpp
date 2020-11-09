#include <iostream>

using namespace std;

class Person
{
public:
	enum PESRON_TYPE
	{
		terrorist = 0, counter_terrorist
	};
	
	class Builder
	{
		
	public:
		PESRON_TYPE type_;
		int bulletproofvest_;
		int knife_;
		int grenade_;
		int pistole_;
		int automat_;
		bool sapper_;
		bool bomb_;


			Builder(PESRON_TYPE type) : 
			type_(type),
			bulletproofvest_(0),
			knife_(0),
			grenade_(0),
			pistole_(0),
			automat_(0),
			sapper_(false),
			bomb_(false) {}

		Builder& type(PESRON_TYPE type__) 
		{
			type_ = type__;
			return *this;
		}
		
		Builder& bulletproofvest(int bulletproofvest__=1)
		{
			bulletproofvest_ = bulletproofvest__;
			return *this;
		}
		
		Builder& knife(int knife__= 1)
		{
			knife_ = knife__;
			return *this;
		}

		Builder& grenade(int grenade__ = 1)
		{
			grenade_ = grenade__;
			return *this;
		}

		Builder& pistole(int pistole__ = 1)
		{
			pistole_ = pistole__;
			return *this;
		}		

		Builder& automat(int automat__ = 1)
		{
			automat_ = automat__;
			return *this;
		}		

		Builder& sapper(bool sapper__ = true)
		{
			sapper_ = sapper__;
			return *this;
		}

		Builder& bomb(bool bomb__ = true)
		{
			bomb_ = bomb__;
			return *this;
		}

		Person build()
		{
			Person p;
			p.create(*this);
			return p;
		}

	};

private:	
	
	PESRON_TYPE type;
	int bulletproofvest;
	int knife;
	int grenade;
	int pistole;
	int automat;
	bool sapper;
	bool bomb;


	void create(Builder& builder)
	{
		type = builder.type_;
		bulletproofvest = builder.bulletproofvest_;
		knife = builder.knife_;
		grenade = builder.grenade_;
		pistole = builder.pistole_;
		automat = builder.automat_;
		sapper = builder.sapper_;
		bomb = builder.bomb_;
	}

};

int main()
{

	Person p = Person::Builder(Person::PESRON_TYPE::counter_terrorist)
		.knife()
		.grenade(3)
		.automat(2)
		.bomb()
		.build();
	
	

	return 0;
}

