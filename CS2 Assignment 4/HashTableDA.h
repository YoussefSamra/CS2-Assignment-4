#pragma once
#include"Employees.h"



class HashTablesDA {

private:
	
    int HashGroups = 10;
	Employees *Tables;
	int collisionRate = 0;
	int hashFunc(int key);

public:

	HashTablesDA();
	void insertOBJ(int index, Employees OBJ);
	void deleteOBJ(int index);
	void printlist();
	void searchtable(int index);
	int getCollisionRate();


};

int HashTablesDA::hashFunc(int key) {

	return key % HashGroups;

}

HashTablesDA::HashTablesDA() {

	Tables = new Employees[HashGroups];
	for (int i = 0; i < HashGroups; i++) {
		Tables[i] = Employees();
	}

}

void HashTablesDA::insertOBJ(int ID, Employees OBJ) {

	int index = hashFunc(ID);
	if (Tables[index].getName() == "") {

		Tables[index] = OBJ;

	}
	else {
		collisionRate++;
		cout << endl << "[Employee with ID: " << ID << " already exists [Collision +1]]" << endl << "New Collision Rate: " << collisionRate << endl;
		int newIndex = index + 1;
		insertOBJ(newIndex, OBJ);
	}


}

void HashTablesDA::deleteOBJ(int ID) {

	int index = hashFunc(ID);
	if (Tables[index].getName() != "") {
		Tables[index] = Employees();
		cout << "==================================================" << endl;
		cout << " [ID " << ID << " Exists, and the Employee has been removed]" << endl;
		cout << "==================================================" << endl << endl;
	}
	else
		cout << "[ID: " << ID << " Does Not Exist]" << endl;

}

void HashTablesDA::printlist() {
	cout << "==================================================" << endl;
	cout << "[HashTable Using Dynamic Array Linear Probing] " << endl;
	cout << "==================================================" << endl;

 
	for (int i = 0; i < HashGroups; i++) {
		if (Tables[i].getName() != "") {
			cout << "ID: " << i << " Exists, "; Tables[i].PrntInfo();


		}
	}
	
	


	cout << "==================================================" << endl;
	cout << "[Collision Rate: " << collisionRate << "]" << endl;

	char xt;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> xt;

	if (xt == 'Y') {
		system("CLS");
	}
	else exit(0);
}

void HashTablesDA::searchtable(int ID) {
	int index = hashFunc(ID);

	if (Tables[index].getName() != "") {
		cout << "ID " << ID << " Exists, and the Employee is" << endl; Tables[index].PrntInfo();


	} else
		cout << "[ID " << ID << " does not exist]" << endl << endl;


}

int HashTablesDA::getCollisionRate() {
	return collisionRate;
}