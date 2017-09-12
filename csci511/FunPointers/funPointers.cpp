#include <iostream>

using namespace std;

float add(float a, float b){
	return a+b;
}

float subtract(float a, float b){
	return a-b;
}

float divide(float a, float b){
	return a/b;
}

float multiply(float a, float b){
	return a*b;
}

int main(){

	float (*fun)(float, float);
	fun = &add;
	cout << (*fun)(2,3) << endl;

	typedef float (*FP)(float, float);
	static FP array[4] = {&add, &subtract, &divide, &multiply};

	for(int n = 0; n < 4; n++){
		cout << array[n](2,3) << endl;
	}
	
	return 0;
}
