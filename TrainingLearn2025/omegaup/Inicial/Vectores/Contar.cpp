#include <iostream>
#include <vector>

void printSumProd(const std::vector<int>& val) {

	int sum{ 0 };
	int prod{ 1 };

	for (int i{ 0 }; i < val.size(); i++) {
		sum += val[i];
        prod *= val[i];
	}

	std::cout << "The sum is: " << sum << ".\n";
	std::cout << "The product is: " << prod << ".\n";

}

int main() {

	std::vector<int> values(3);

	std::cout << "Enter 3 integers: ";

	for (int i{ 0 }; i <= 2; i++) {
		std::cin >> values[i];
	}

	printSumProd(values);

	return 0;
}