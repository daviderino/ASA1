#include <iostream>

int main() {
	std::string input, input_aux;

	getline(std::cin, input, ',');
	getline(std::cin, input_aux);
	
	const int N = std::stoi(input_aux);
	const int M = std::stoi(input);

	std::cout << "N: " << N << "\nM: " << M << std::endl;

    return 0;
}
