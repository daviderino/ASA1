#include <iostream>

int main() {
	std::string input1, input2;

	getline(std::cin, input1, ',');
	getline(std::cin, input2);
	
	const int N = std::stoi(input1);
	const int M = std::stoi(input2);

	std::cout << "N: " << N << "\nM: " << M << std::endl;

    return 0;
}
