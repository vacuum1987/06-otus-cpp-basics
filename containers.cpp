#include <iostream>
#include "dm_vector.hpp"
#include "dm_list_1_way.hpp"
#include "dm_list_2_way.hpp"

void main () {

// dm_vector container operations:
std::cout << std::endl << "dm_vector container operations" << std::endl;
Dm_vector<int> line_container {};
for (int i=0; i < 10; i++) {
    line_container.push_back (i);
}
line_container.printValue ();
std::cout << std::endl << "container size = " << line_container.size() << std::endl;
std::cout << "Delete 3d, 5th and 7th elements:" << std::endl;
line_container.erase (6);
line_container.erase (4);
line_container.erase (2);
line_container.printValue ();
std::cout << std::endl << "Add element '10' in the beginning:" << std::endl;
line_container.insert (10, 0);
line_container.printValue ();
std::cout << std::endl << "Add element '20' in the middle:" << std::endl;
line_container.insert (20, 4);
line_container.printValue ();
std::cout << std::endl << "Add element '30' in the end:" << std::endl;
line_container.insert (30, (line_container.size()));
line_container.printValue ();

/* Dm_vector<int> line_container_2 = line_container; // copy constructor call
std::cout << std::endl << "New container:" << std::endl;
line_container_2.printValue ();
line_container.erase (2);
std::cout << std::endl << "New container after erase 1 element of original container (it will be the same because it is a copy):" << std::endl;
line_container_2.printValue (); */

// Dm_list_2_way container operations:
std::cout << std::endl << "----------------------------------" << std::endl;
std::cout << std::endl << "dm_list_2_way container operations" << std::endl;
Dm_list_2_way <int> list_2_way_container {};
for (int i=0; i < 10; i++) {
    list_2_way_container.push_back (i);
}
list_2_way_container.printValue ();
std::cout << std::endl << "container size = " << list_2_way_container.size() << std::endl;
std::cout << "Delete 3d, 5th and 7th elements:" << std::endl;
list_2_way_container.erase (6);
list_2_way_container.erase (4);
list_2_way_container.erase (2);
list_2_way_container.printValue ();
std::cout << std::endl << "Add element '10' in the beginning:" << std::endl;
list_2_way_container.insert (10, 0);
list_2_way_container.printValue ();
std::cout << std::endl << "Add element '20' in the middle:" << std::endl;
list_2_way_container.insert (20, 4);
list_2_way_container.printValue ();
std::cout << std::endl << "Add element '30' in the end:" << std::endl;
list_2_way_container.push_back (30);
list_2_way_container.printValue ();

/* Dm_list_2_way<int> list_2_way_container_2 = list_2_way_container; // copy constructor call
std::cout << std::endl << "New container:" << std::endl;
list_2_way_container_2.printValue ();
list_2_way_container.erase (9);

std::cout << std::endl << "New container after erase 1 element of original container (it will be the same because it is a copy):" << std::endl;
list_2_way_container_2.printValue ();
std::cout << std::endl << "old container:" << std::endl;
list_2_way_container.printValue (); */

// Dm_list_1_way container operations:
std::cout << std::endl << "----------------------------------" << std::endl;
std::cout << std::endl << "dm_list_1_way container operations" << std::endl;
Dm_list_1_way <int> list_1_way_container {};
for (int i=0; i < 10; i++) {
    list_1_way_container.push_back (i);
}
list_1_way_container.printValue ();
std::cout << std::endl << "container size = " << list_1_way_container.size() << std::endl;
std::cout << "Delete 3d, 5th and 7th elements:" << std::endl;
list_1_way_container.erase (6);
list_1_way_container.erase (4);
list_1_way_container.erase (2);
list_1_way_container.printValue ();
std::cout << std::endl << "Add element '10' in the beginning:" << std::endl;
list_1_way_container.insert (10, 0);
list_1_way_container.printValue ();
std::cout << std::endl << "Add element '20' in the middle:" << std::endl;
list_1_way_container.insert (20, 4);
list_1_way_container.printValue ();
std::cout << std::endl << "Add element '30' in the end:" << std::endl;
list_1_way_container.push_back (30);
list_1_way_container.printValue ();

/* Dm_list_1_way<int> list_1_way_container_2 = list_1_way_container; // copy constructor call
std::cout << std::endl << "New container:" << std::endl;
list_1_way_container_2.printValue ();
list_1_way_container.erase (9);

std::cout << std::endl << "New container after erase 1 element of original container (it will be the same because it is a copy):" << std::endl;
list_1_way_container_2.printValue ();
std::cout << std::endl << "old container:" << std::endl;
list_1_way_container.printValue (); */ 
};