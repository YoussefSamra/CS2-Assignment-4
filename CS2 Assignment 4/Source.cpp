#include "HashTableLL.h"
#include "HashTableDA.h"
#include "Employees.h"


int main() {

	//==================================================================================================================\\

	Employees Mina("Mina", 30, 10000, 4);
	Employees Fawzy("Fawzy", 45, 5000, 8);
	Employees Yara("Yara", 19, 2000, 0);
	Employees Mariam("Mariam", 32, 8000, 2);
	Employees Ayman("Ayman", 33, 4000, 8);
	Employees Roshdy("Roshdy", 28, 9000, 3);
	Employees Aya("Aya", 26, 6000, 3);
	Employees Abdallah("Abdallah", 29, 7000, 4);
	Employees Fatma("Fatma", 21, 3000, 1);

	//==================================================================================================================\\

/*

	// HashTables using Linked List [Linear Probing]:
	
	HashTablesLLLP<Employees> LinkedListTableLinearProbing;
	LinkedListTableLinearProbing.InsertEmployee(1, Mina);
	LinkedListTableLinearProbing.InsertEmployee(1, Fawzy);       // First three have the same ID
	LinkedListTableLinearProbing.InsertEmployee(1, Yara);
	LinkedListTableLinearProbing.InsertEmployee(4, Mariam);
	LinkedListTableLinearProbing.InsertEmployee(5, Ayman);
	LinkedListTableLinearProbing.InsertEmployee(6, Roshdy);
	LinkedListTableLinearProbing.InsertEmployee(7, Aya);
	LinkedListTableLinearProbing.InsertEmployee(8, Abdallah);
	LinkedListTableLinearProbing.InsertEmployee(9, Fatma);

	

	LinkedListTableLinearProbing.PrntTable();                  // Prints the whole list with the collision rate

	LinkedListTableLinearProbing.RemoveEmployee(4);

	LinkedListTableLinearProbing.SearchTable(1);
	LinkedListTableLinearProbing.SearchTable(2);              // To make sure they are searchable and are allocated the next available slot
	LinkedListTableLinearProbing.SearchTable(3);
	LinkedListTableLinearProbing.SearchTable(4);



	cout << endl << "==================================================" << endl;                        // Prints collision rate
	cout << "[Collision Rate: " << LinkedListTableLinearProbing.CollisionRate() << "]" << endl;

	char xt;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> xt;

	if (xt == 'Y') {
		system("CLS");
	}
	else exit(0);
*/



	// ^^ Linear Probing Using List Libray <Pair> ^^ \\
   //                                                 \\
  //                 Assignment [4]:                   \\





	//==================================================================================================================\\
   // Hastables Using LinkedList [Separate Chaining]:
	        
	HashTableLLSC<Employees> LinkedListTableSeparateChaining;
	LinkedListTableSeparateChaining.InsertOBJ(1, Mina);
	LinkedListTableSeparateChaining.InsertOBJ(1, Fawzy);
	LinkedListTableSeparateChaining.InsertOBJ(2, Yara);
	LinkedListTableSeparateChaining.InsertOBJ(5, Mariam);
	LinkedListTableSeparateChaining.InsertOBJ(5, Ayman);
	LinkedListTableSeparateChaining.InsertOBJ(6, Roshdy);
	LinkedListTableSeparateChaining.InsertOBJ(7, Aya);
	LinkedListTableSeparateChaining.InsertOBJ(8, Abdallah);
	LinkedListTableSeparateChaining.InsertOBJ(9, Fatma);

	LinkedListTableSeparateChaining.PrintTableContent();

	LinkedListTableSeparateChaining.RemoveOBJ(5);

	


	cout << endl << "==================================================" << endl;                        // Prints collision rate
	cout << "[Collision Rate: " << LinkedListTableSeparateChaining.CollisionCounter() << "]" << endl;


	char xt;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> xt;

	if (xt == 'Y') {
		system("CLS");
	}
	else exit(0);





	//==================================================================================================================\\
   // Hastables Using Dynamic Array: \\
	
	HashTablesDA DynamicArrayTable;



	DynamicArrayTable.insertOBJ(1, Mina);
	DynamicArrayTable.insertOBJ(1, Fawzy);
	DynamicArrayTable.insertOBJ(1, Yara);
	DynamicArrayTable.insertOBJ(4, Mariam);
	DynamicArrayTable.insertOBJ(5, Ayman);
	DynamicArrayTable.insertOBJ(6, Roshdy);
	DynamicArrayTable.insertOBJ(7, Aya);
	DynamicArrayTable.insertOBJ(8, Abdallah);
	DynamicArrayTable.insertOBJ(9, Fatma);



	DynamicArrayTable.printlist();
	DynamicArrayTable.deleteOBJ(3);
	DynamicArrayTable.deleteOBJ(4);

	DynamicArrayTable.searchtable(1);
	DynamicArrayTable.searchtable(2);
	DynamicArrayTable.searchtable(3);
	DynamicArrayTable.searchtable(6);



	cout << endl << "==================================================" << endl;                        // Prints collision rate
	cout << "[Collision Rate: " << DynamicArrayTable.getCollisionRate() << "]" << endl;

	char lm;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> lm;

	if (lm == 'Y') {
		system("CLS");
	}
	else exit(0);

}