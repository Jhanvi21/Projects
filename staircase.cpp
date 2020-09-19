//============================================================================
// Name        : Project_1
// Author      : Jhanvi Shah
// Version     :
// Date        : 2020-09-16
// Copyright   : Your copyright notice
// Description : Staircase Function
//============================================================================
#include <iostream>

int main();

int main() {
  double x{};

  std::cout << "Enter value of x: ";
  std::cin >> x;

  int stair{};

  if (x > 0) {
	  int i{1};
	  while (x >= i) {
		  stair = i;
		  ++i;
	  }
  }

   if (x <= 0) {
	   int j{0};
	   while (x < j) {
		   stair = j-1;
		   --j;
	   }
   }

  std::cout << "The value of stair(x) is: ";
  std::cout << stair;
  std::cout << std::endl;

  return 0;
}
