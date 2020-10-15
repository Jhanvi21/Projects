#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

unsigned int add_checksum(unsigned int n);
void add_checksum(unsigned int array[], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum(unsigned int array[], std::size_t capacity);

#ifndef MARMOSET_TESTING
int main() {

	unsigned int value_to_protect{99999999};
	unsigned int protected_value = add_checksum(value_to_protect);

	std::cout << "The value " << value_to_protect
				<< " with the checksum added is " << protected_value
				<< "." << std::endl;

	if (verify_checksum(protected_value)) {
		std::cout << "The checksum is valid." << std::endl;
	}

	else   {
		std::cout << "The checksum is invalid." << std::endl;
	}

	std::size_t qty_values {3};
	unsigned int value_series[qty_values] {20201122, 20209913, 20224012};

	add_checksum(value_series, qty_values);

	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0}; series_index < qty_values; series_index++){
		std::cout << value_series[series_index] << " ";
	}
	std::cout << std::endl;

	return 0;
}
#endif

unsigned int add_checksum(unsigned int n){
	if (n <= 99999999){
		unsigned int sum{0};
		unsigned int value{n*10};

		for (unsigned int i{0}; i < 8; ++i) {
			if ((i%2) == 0) {
				if (((n%10)*2) > 9) {
					sum += 1 + (((n%10)*2)-10);
				} else {
					sum += (n%10)*2;
				}
			} else {
				sum += (n%10);
			}
			n = n/10;
		}
		sum = (sum*9)%10;
		return value+sum;

	} else {
		return UINT_MAX;
	}
}

void add_checksum(unsigned int array[], std::size_t capacity){
	for (unsigned int i{0}; i < capacity; ++i) {
		if (array[i] <= 99999999){
			array[i] = add_checksum(array[i]);
		} else {
			array[i] = UINT_MAX;
		}
	}
}

bool verify_checksum(unsigned int n) {
	unsigned int digit{};
	unsigned int rightnum{};

	digit= n%10;
	n = (add_checksum(n/10));
	rightnum = n%10;

	if ((rightnum == digit)&&(n <= 999999999)){
		return true;
	} else {
		return false;
	}
}

unsigned int remove_checksum(unsigned int n){
	if ((n <= 999999999)&&(verify_checksum(n))) {
		return n/10;
	} else {
		return UINT_MAX;
	}
	return 0;
}

void remove_checksum(unsigned int array[], std::size_t capacity){
	for (unsigned int i{0}; i < capacity; ++i) {
		if ((array[i] <= 999999999)&&(verify_checksum(array[i]))){
			array[i] = remove_checksum(array[i]);
		} else {
			array[i] = UINT_MAX;
		}
	}
}
