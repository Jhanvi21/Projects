#include <iostream>
int main();


int main() {
    int lnum;
    int hnum;
	bool is_prime = true;
	int count{0};

    std::cout <<"Enter first number: ";
	std::cin >> lnum;
    std::cout <<"Enter second number: ";
	std::cin >> hnum;


	for (int i{lnum}; i <= hnum; ++i) {
		is_prime = true;
		if ((i%2)==0) {
			is_prime = false;
		} else {
			for (int j{3}; j < i; j+=2 ) {
				if ((i%j)==0){
					is_prime = false;
					break;
				}
			}
		}

		if ((count == 0) && (is_prime == true)){
			std::cout <<"Primes in range: ";
			std::cout <<" " << i;
			++count;
		} else if ((count > 0) && (is_prime == true)){
			std::cout <<" " << i;
			++count;
		} else if ((i==hnum) && (count == 0)) {
			std::cout <<"No primes in range.";
		}

	}

	return 0;
}
