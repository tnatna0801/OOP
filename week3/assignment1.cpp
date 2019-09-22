#include <iostream>

void code() {

}

int data = 3;
int bss;

int main() {
	const char * rodata = "abc";
	int* heap = new int[2];
	int stack = 22;

	std::cout << "code\t" << (void*) code << std::endl;
	std::cout << "Rodata\t" << (void*) rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
	std::cout << "Kim SooMin" << std::endl;
}


