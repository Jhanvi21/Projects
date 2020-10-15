#include <iostream>
int main();

void shift_capital (unsigned char letter, int shift);
void shift_lowercase (unsigned char letter, int shift);


int main() {
	unsigned char initial[1]{};
	int num{};
	unsigned char phrase[100]{};


	std::cout<< "Enter command: ";
	std::cin>> initial;

	while (initial[0] != 'Q'){
		std::cin >> num;
		std::cin>> phrase;

		//std::cout << to_string (phrase, num) << std::endl;

		for (int i{0}; phrase[i] != '.'; ++i){
			if (phrase[i] <= 90){
				//capital shift
				shift_capital (phrase[i], num);
			} else {
				//lowercase shift
				shift_lowercase (phrase[i], num);
			}
		}
		std::cout<<std::endl;

		std::cout<< "Enter command: ";
		std::cin>> initial;
	}
	return 0;
}

void shift_capital (unsigned char letter, int shift) {
	if((letter + shift) < 65) { //-ve shift
		letter = letter + shift + 26;
	} else if ((letter + shift) > 90){ //+ve shifted out of bound
		letter = letter + shift - 26;
	} else {
		letter = letter + shift;
	}
	std::cout << letter;
}

void shift_lowercase (unsigned char letter, int shift) {
	if ((letter + shift) > 122) { //lowercase and +ve shift
		letter = letter + shift - 26;
	} else if ((letter + shift) < 97) {
		letter = letter + shift + 26;
	} else {
		letter = letter + shift;
	}
	std::cout << letter;
}
