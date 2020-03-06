#include <iostream>

int main() {
	const std::string delimiter = ",";
	std::string input, input_aux;
	size_t comma = 0;

	getline(std::cin, input);

	std::cout << input << std::endl;
	
	comma = input.find(delimiter);
	input_aux = input.substr(0, comma);
	input.erase(0, comma + delimiter.length());

	const int N = std::stoi(input_aux);
	const int M = std::stoi(input);

	std::cout << "N: " << N << "\nM: " << M << std::endl;

    return 0;
}