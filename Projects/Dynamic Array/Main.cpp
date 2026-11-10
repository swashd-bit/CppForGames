#include <iostream>

int main()
{

	int* value = new int[10];

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> value[i];

		while (value[i] <= 0 || value[i] > 10 || std::cin.fail())
		{
			std::cout << "ERROR: Not in range of 1-10, or not a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> value[i];
		}
	}

	std::cout << "\n" << "Your beautiful array:" << "\n" << "["
		<< value[0] << ", " << value[1] << ", " 
		<< value[2] << ", " << value[3] << ", " 
		<< value[4] << ", " << value[5] << ", " 
		<< value[6] << ", " << value[7] << ", " 
		<< value[8] << ", " << value[9] << "]" 
		<< std::endl;

	std::qsort(value, 10, sizeof(int), [](const void* a, const void* b) -> int
	{
		return (*(int*)a - *(int*)b);
	});

	std::cout << "\n" << "But now even more beautiful:" << "\n" << "["
		<< value[0] << ", " << value[1] << ", "
		<< value[2] << ", " << value[3] << ", "
		<< value[4] << ", " << value[5] << ", "
		<< value[6] << ", " << value[7] << ", "
		<< value[8] << ", " << value[9] << "]"
		<< std::endl;

	std::cout << "\n" << "minimum: " << value[0] << std::endl;
	std::cout << "maximum: " << value[9] << std::endl;
	std::cout << "Average: " << (value[0] + value[1] + value[2] + value[3] + value[4] + value[5] + value[6] + value[7] + value[8] + value[9]) / 10.0 << "\n" << std::endl;
	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	

	delete[] value;

	return 0;
}