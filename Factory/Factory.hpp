#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Object
{
	public:
		Object()
		{
		}
		~Object()
		{
		}

		virtual void Test() = 0;
};

class Object1: public Object
{
	public:
		Object1()
		{
			cout << "Object1 is created" << endl;
		}
		~Object1()
		{
			cout << "Object1 is destroyed" << endl;
		}
		void Test()
		{
			cout <<"Test Object1" << endl;
		}
};

class Object2:public Object
{
	public:
		Object2()
		{
			cout << "Object2 is created" << endl;
		}
		~Object2()
		{
			cout << "Object2 is created" << endl;
		}
		void Test()
		{
			cout <<"Test Object2" << endl;
		}
};

class Factory
{

	public:
		Factory()
		{
			cout << "Factory is created" << endl;
		}
		~Factory()
		{
			cout <<"Factory is destroyed" << endl;
		}

		void NewObject()
		{
			Object *wObject = CreateObject();
			wObject->Test();
		}

		virtual Object* CreateObject() = 0;

};

class Factory1: public Factory
{
	public:
		Factory1()
		{
			cout << "Factory1 is created" << endl;
		}
		~Factory1()
		{
			cout << "Factory1 is destroyed" << endl;
		}

		Object* CreateObject()
		{
			return new Object1;
		}
};

class Factory2: public Factory
{

	public:
		Factory2()
		{
			cout << "Factory2 is created" << endl;
		}
		~Factory2()
		{
			cout << "Factory2 is destroyed" << endl;
		}

		Object* CreateObject()
		{
			return new Object2;
		}
};
