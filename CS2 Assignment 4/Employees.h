#pragma once
#include<iostream>
#include<list>
#include<Cstring>
#include <string>

using namespace std;

class Employees {
	
private:
	string name;
	int age;
	int salary;
	int EXP;

public:

	Employees();
	Employees(string N, int A, int S, int E);
	void PrntInfo();
	string getName();
	

};

void Employees::PrntInfo() {

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Salary: " << salary << endl;
	cout << "Experience In Years: " << EXP << endl << endl;


}

Employees::Employees() {
	name = "";
	age = 0;
	salary = 0;
	EXP = 0;
}

Employees::Employees(string N, int A, int S, int E) {
	name = N;
	age = A;
	salary = S;
	EXP = E;
}


string Employees::getName() {
	return name;
}