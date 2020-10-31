//Finding a no. that is a perfect square, and is also the sum of the natural number series upto n
//Author: RaperTon
//Date: 10-30-2020 , 22:12:21 IST
#include <iostream>
#include<math.h>

//To check if a number is sqaureroot or not.
bool isPerSquare(int n) {
	auto sqrrt = sqrt(n);
	int whlno = (int)sqrrt;
	if ((whlno - sqrrt) == 0)
		return 1;
	else
		return 0;
}

//Sum of whole no:
/*int wholeSum(int n) {
	return (n * (n + 1)) / 2;
}*/

int main() {
	long long int  i = 1, sum=0;
	char c = ' ';
	do {
		sum = sum + i;
		if (isPerSquare(sum) == 1) {
			std::cout << "\n" << sum << " is the magic no and it is the sum of the natural number series upto " << i;
			std::cout<< "\nDo you wish to continue: (y/n):\t";
			std::cin >> c;
		}
		++i;
	} while (c != 'n');
	
}