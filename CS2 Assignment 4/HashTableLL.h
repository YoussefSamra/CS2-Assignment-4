#pragma once
#include "Employees.h"




//==================================================================================================================\\
   // Hastables Using LinkedList [Linear Probing]:

template <class T> class HashTablesLLLP {

private:

	static const int HashGroups = 10;
	list<pair<int, T>> Table[HashGroups];
	int CollisionCounter = 0;

public:

	
	bool isEmpty();
	int HashFunc(int ID);
	void InsertEmployee(int ID, T);
	void RemoveEmployee(int ID);
	void SearchTable(int ID);
	void PrntTable();
	int CollisionRate();

};

template <typename T>
bool HashTablesLLLP<T>::isEmpty() {
	int checker = 0;

	for (int i = 0; i < HashGroups; i++) {
		checker += Table[i].size();
	}

	if (!checker) {
		return true;
	}
	else return false;
}

template <typename T>
int HashTablesLLLP<T>::HashFunc(int ID) {
	return ID % HashGroups;
}

template <typename T>
void HashTablesLLLP<T>::InsertEmployee(int ID, T E) {

	int HValue = HashFunc(ID);
	auto& cell = Table[HValue];
	auto bItr = begin(cell);
	bool IDExists = false;
	
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == ID) {
			IDExists = true;
			int NewID = ID + 1;
			CollisionCounter++;
			InsertEmployee(NewID, E);
	
		}
	}

	if (!IDExists) {
		cell.emplace_back(ID, E);
		
		return;

	}
}

template <typename T>
void HashTablesLLLP<T>::RemoveEmployee(int ID) {

	int HValue = HashFunc(ID);
	auto& cell = Table[HValue];
	auto bItr = begin(cell);
	bool IDExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == ID) {
			IDExists = true;
			cell.erase(bItr);
			cout << "==================================================" << endl;
			cout << " [ID " << ID << " Exists, and the Employee has been removed]" << endl;
			cout << "==================================================" << endl << endl;
			break;
		}
	}	

	if (!IDExists) {
		cout << "[ID " << ID << " does not exist]" << endl;
		
	}

	return;

}

template <typename T>
void HashTablesLLLP<T>::SearchTable(int ID) {

	int HValue = HashFunc(ID);
	auto& cell = Table[HValue];
	auto bItr = begin(cell);
	bool IDExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == ID) {
			IDExists = true;
			cout << "ID " << ID << " Exists, and the Employee is" << endl; bItr->second.PrntInfo();
			break;
		}
	}

	if (!IDExists) {
		cout << "[ID " << ID << " does not exist]" << endl;
	}

}

template <typename T>
void HashTablesLLLP<T>::PrntTable() {

	cout << "==================================================" << endl;
	cout << "   [HashTable Using LinearProbing Linked List]" << endl;
	cout << "==================================================" << endl;

	for (int i = 0; i < HashGroups; i++) {

		if (Table[i].size() == 0) continue;

		auto btIr = Table[i].begin();

		for (; btIr != Table[i].end(); btIr++) {

			cout << "ID: " << btIr->first << "   ";
			btIr->second.PrntInfo();

		}

	}

	cout << "==================================================" << endl; 
	cout << "[Collision Rate: " << CollisionCounter << "]" << endl;

	char xt;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> xt;

	if (xt == 'Y') {
		system("CLS");
	}
	else exit(0);

}

template <typename T>
int HashTablesLLLP<T>::CollisionRate() {
	return CollisionCounter;
}


//==================================================================================================================\\
   // Hastables Using LinkedList [Separate Chaining]:



struct Node
{
	int key;
	Employees value;
	Node* next;
	Node* previous;
};


template <class Class> class HashTableLLSC {

private:
	int HashGroups;
	int CollisionRate = 0;
	Node* Table[10];
	int HashFunction(int ID);

public:

	HashTableLLSC();
	int CollisionCounter();
	void InsertOBJ(int ID, Class type);
	void RemoveOBJ(int ID);
	void PrintTableContent();


};


template <typename Class>
HashTableLLSC<Class>::HashTableLLSC() {

	for (int i = 0; i < 10; i++)
		Table[i] = NULL;

	//Emptying the node and make them NULL equivalent to int =  0;

}

template <typename Class>
int HashTableLLSC<Class>::HashFunction(int ID) {

	return ID % 10;
}



template <typename Class>
void HashTableLLSC<Class>::InsertOBJ(int ID, Class type) {

	Node* temp = new Node;
	temp->key = ID;
	temp->value = type;
	temp->next = NULL; 
	
	int index = HashFunction(ID);

	if (Table[index] == NULL) {
		Table[index] = temp;
		HashGroups++;
	}
	else {
		CollisionRate++;
		cout << endl << "[Employee with ID: " << ID << " already exists [Collision +1]]" << endl << "New Collision Rate: " << CollisionRate << endl;
		Node* temp2 = Table[index];
		while (temp2->key != ID && temp2->next != NULL)
			temp2 = temp2->next;
		if (temp2->key == ID) {

			temp2->next = temp;
			temp->previous = temp2;
			HashGroups++;

		}


	}


}

template <typename Class>
void HashTableLLSC<Class>::RemoveOBJ(int ID) {
	int IndexGetter = HashFunction(ID);

	if (Table[IndexGetter] == NULL) {
		cout << "[ID: " << ID << " Does Not Exist]" << endl;
	}
	else if (Table[IndexGetter]->key == ID) {

		Node* temp = Table[IndexGetter];
		if (Table[IndexGetter] != NULL)
			Table[IndexGetter]->next->previous = Table[IndexGetter];

		Table[IndexGetter] = Table[IndexGetter]->next;
		delete temp;
		cout << "==================================================" << endl;
		cout << " [ID " << ID << " Exists, and the Employee has been removed]" << endl;
		cout << "==================================================" << endl << endl;
		
		HashGroups--;

	}
	else {

		Node* T = Table[IndexGetter];
		Node* T2 = Table[IndexGetter];
		while (T2->key != ID && T2 != NULL) {
			T = T2;
			T2 = T2->next;
		}
		if (T2 == NULL) {
			cout << "[ID: " << ID << " Does Not Exist]" << endl;
		}
		else {
			cout << "==================================================" << endl;
			cout << " [ID " << ID << " Exists, and the Employee has been removed]" << endl;
			cout << "==================================================" << endl << endl;
		T2->next->previous = T;
		T->next = T2->next;
		delete T2;
		HashGroups--;

	}
}






	



}

template <typename Class>
void HashTableLLSC<Class>::PrintTableContent() {

	cout << "==================================================" << endl;
	cout << "[HashTable Using LinkedList Separate Chaining] " << endl;
	cout << "==================================================" << endl;


	for (int i = 0; i < 10; i++) {
		if (Table[i] != NULL) {
			Node* temp = Table[i];
			while (temp != NULL) {
				cout << "ID: " << temp->key << "   ";
				temp->value.PrntInfo();
				temp = temp->next;

			}



		}
	}









	cout << "==================================================" << endl;
	cout << "[Collision Rate: " << CollisionRate << "]" << endl;

	char xt;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> xt;

	if (xt == 'Y') {
		system("CLS");
	}
	else exit(0);
}




template <typename Class>
int HashTableLLSC<Class>::CollisionCounter() {


	return CollisionRate;


}


