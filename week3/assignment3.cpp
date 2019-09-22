#include <iostream>
#include <string>
int main() {
	char target[] = "Kim SooMin"; 
	long b[144]; //long(8byte) type 배열 => stack 
	int a = 17; //지역변수(4byte) => stack
	int i = 1190; 
	int *c = new int[704]; // 포인터(8byte) => stack
	const char * copy = "is no no"; // 포인터 => stack
	char name = 'a'; //지역 변수(1byte) => stack
	
	std::cout << &name+i << std::endl;
}

