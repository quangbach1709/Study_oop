#pragma once
#include <iostream>
#include <string>

using namespace std;
class Human
{
private:
	int age;
	string name;
	public:
		Human()
		{
			age = 0;
			name = "";
		}
		Human(int age, string name)
		{
			this->age = age;
			this->name = name;
		}
		~Human()
		{
			cout<<"Da huy Human"<<endl;
		}
		void setAge(int age)
		{
			this->age = age;
		}
		void setName(string name)
		{
			this->name = name;
		}
		int getAge()
		{
			return age;
		}
		
		void showInfo()
		{
						cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
		}
		void inputInfo()
		{
			cout << "Name: ";
			cin >> name;
			cout << "Age: ";
			cin >> age;
		}
		void outputInfo()
		{
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
		}
};



