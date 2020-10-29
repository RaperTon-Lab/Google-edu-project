#include <iostream>
#include<math.h>
#include<time.h>
#include<random>

void StartUp() {
	std::cout << "Welcome to Artillery.\nYou are in the middle of a war and being charged by thousands of enemies.\nYou have one cannon, which you can shoot at any angle.\nYou only have 10 cannonballs for this target..\nLet's begin...";
}

double randomNum() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1.0,375.6);
	return dist(mt);
}

double HorizTraj(double angle) {
	double R, time_in_air;
	//std::cout << "\n\tsin0" << sin(angle);
	time_in_air = (2.0 * 60.96 * sin(angle)) / 9.8;
	//std::cout << "\nTime in air\t" << time_in_air;
	//std::cout << "\ncos0\t" << cos(angle);
	R = (60.96 * cos(angle)) * time_in_air;
	//::cout << "\n Debug " << R;
	return R;
}
int Fire() {
	int i = 0, flag = 0;
	double randomno, angle, range;
	randomno = randomNum();
	std::cout << "\nThe enemy is " << randomno << " meter away!!!";
	while ((i != 10)) {
		std::cout << "\nWhat angle? ";
		std::cin >> angle;
		angle = (3.14 * angle) / 180;
		range = HorizTraj(angle);
		std::cout << "\n" << range;
		++i;
		if (abs(range - randomno) < 2) {
			flag = 1;
			if (range == randomno)
				std::cout << "Direct Hit!!!";
			else
				std::cout << "You Hit Him!!!";
			break;
		}
		else {
			if (range < randomno)
				std::cout << "You undershot by " << abs(range - randomno) << " meter";
			else
				std::cout << "You overshot by " << abs(range - randomno) << " meter";
			std::cout << "\n" << randomno;
		}
	}
	if (flag == 1) {
		std::cout << "\nIt took you " << i << " shot(s)";
		std::cout << "\nYou have killed 1 enemy";
		return 1;
	}
	else {
		std::cout << "\nYou run out of cannonballs.... GAME OVER!!!!";
		return 0;
	}
}


int main() {
	int killed = 0, flag;
	char done=' ';
	StartUp();
	do {
		flag = 0;
		flag = Fire();
		if (flag == 1)
			++killed;
		std::cout << "\nI see another one, care to shoot again? (y/n) \t";
		std::cin >> done;
	} while (done != 'n');
	std::cout << "\nYou have killed " << killed << " of the enemy.";
}