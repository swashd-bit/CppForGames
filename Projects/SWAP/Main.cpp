#include <iostream>

void SWAP(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	std::cout << "After swap: a = " << *a << ", b = " << *b << std::endl;

	return;
}

void SWAPReference(int a, int b)
{
	int& ar = b;
	int& br = a;

	std::cout << "After swapReference: a = " << ar << ", b = " << br << std::endl;
}

int main()
{
	int a = 3;
	int b = 5;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

	// SWAP(&a, &b);
	SWAPReference(a, b);

	return 0;
}