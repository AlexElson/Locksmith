#include <iostream>

using namespace std;

union unions
{
	int a;
	float b;
	char c;
	int* p;
};

/*A Union stores several different variable types
* on one memory address with the size of the largest
* variable in the union.
* The purpose of a union is to save memory.
*/

int main(){
	unions u;// = {0x12345}; 
	//a union is created with 
	//the address of 0x12345

	u.a = 5; //Member variables are initialized
	
	cout << "int a = " << u.a << endl;
	//This will print 5

	u.b = 10.13;
	u.c = 'M';
	u.p = &u.a;
	//After initializing the other variables
	//a no longer prints 5.
	//We are casting the union to the highest
	//variable bytes, distoring the variables.

	cout << "int a = "<< u.a << endl;
	cout << "float b = "<< u.b << endl;
	cout << "char c = "<< u.c << endl;
	cout << "int* p = "<< u.p << endl;
	


}

