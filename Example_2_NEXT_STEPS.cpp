//Exercise 2 of google education C++ Next Step
//https://developers.google.com/edu/c++/next-steps
//Author: RaperTon
//Date: 02-11-2020, 17:22:18 IST

#include<iostream>
#include<iomanip>

#define NewCompSub 0.90               //rate of sale for new compulsory subject
#define UsedCompSub 0.65              //rate of sale for used compulsory subject
#define	NewOptSub 0.40                //rate of sale for new optional subject
#define UsedOptSub 0.20               //rate of sale for used optional subject
#define PriceSaving 0.20              //rate of profit made from the sales

//class book which contains all the necessary function
class books {
	std::string sub = " ",status = " "; //used for displaying compulsory/optional and old/used in later sentences 
	int bk_No;                          //book id or book code
	float bk_Price;                     //individual book prices
	int tbk_Req;                        //book requirement including those in inventory
	int bk_Inv;                         //book in inventory
	int bk_Req;                         //book requirement excluding inventory
	int pro_En;                         //prospective enrollment
	int bk_Sub_type;                    //is the subject compulsory or optional?
	int bk_Status;                      //is the sub new or used before
public:
	static float bk_profit;             //profit from selling all the books
	static float bk_total_cost;         //total cost book require
	void readData();									  //function use to read data about the book
	void printData();								    //function use to print the data about the book
	void bookReq();											//function to calculate book requirement
	void bookCost();                    //function to calculate total book cost of the book required and total cost of all the book required combined
	static void bookProf();             //function to calculate the profit from all the books required
};

float books::bk_total_cost = 0;       //initialization of book cost all subjects combined
float books::bk_profit = 0;           //initialization of profit all subjects combined

//readData() function definition//

void books::readData() {
	std::cout << "\nPlease enter the book code:\t";
	std::cin >> bk_No;
	std::cout << "Single copy price:\t";
	std::cin >> bk_Price;
	std::cout << "Number on hand:\t";
	std::cin >> bk_Inv;
	std::cout << "Prospective enrolment:\t";
	std::cin >> pro_En;
	std::cout << "1 for reqd/ 0 for optional:\t";
	std::cin >> bk_Sub_type;
	std::cout << "1 for new/ 0 for used:\t";
	std::cin >> bk_Status;
}

//printData() function definition//

void books::printData() {
	std::cout << "\nBooks:\t" << bk_No;
	std::cout << "\nPrice:\tRs " << bk_Price;
	std::cout << "\nInventory:\t" << bk_Inv;
	std::cout << "\nEnrollment:\t" << pro_En;
	if (bk_Sub_type == 1)
		sub = "required";
	else
		sub = "optional";
	if (bk_Status == 1)
		status = "new";
	else
		status = "used";
	std::cout << "\n\nThis book is " << sub << " and " << status << "\n";
}

//bookReq() function definition//

void books::bookReq() {
	if ((bk_Sub_type == 1) && (bk_Status == 1)) {
		tbk_Req = (int)pro_En * NewCompSub;
		bk_Req = tbk_Req - bk_Inv;
	}
	else if((bk_Sub_type == 1) && (bk_Status == 0)) {
		tbk_Req = (int)pro_En * UsedCompSub;
		bk_Req = tbk_Req - bk_Inv;
	}
	else if ((bk_Sub_type == 0) && (bk_Status == 1)) {
		tbk_Req = (int)pro_En * NewOptSub;
		bk_Req = tbk_Req - bk_Inv;
	}
	else if ((bk_Sub_type == 0) && (bk_Status == 0)) {
		tbk_Req = (int)pro_En * UsedOptSub;
		bk_Req = tbk_Req - bk_Inv;
	}
	std::cout << "\nNeed to order:\t" << bk_Req;
}

//bookCost() function definition//

void books::bookCost() {
	std::cout << "\nTotal cost: Rs " << bk_Req * bk_Price << "\n";
	bk_total_cost = bk_Req * bk_Price + bk_total_cost;
}

//bookProf() function definition//

void books::bookProf() {
	bk_profit = bk_total_cost * PriceSaving;
	std::cout << "\nProfit: Rs" << bk_profit << "\n";
}

//main function//

int main() {
	int n = 1;
	books* subjects;
	while (n != 0) {
		std::auto_ptr<books> subjects(new books);
		subjects->readData();
		std::cout << "***************************************************";
		subjects->printData();
		std::cout << "***************************************************";
		subjects->bookReq();
		subjects->bookCost();
		std::cout << "***************************************************";
		std::cout << "\nEnter 1 to do another book, 0 to stop:\t";
		std::cin >> n;
		std::cout << "***************************************************";
	}
	std::cout << "\nTotal for all orders: Rs" << books::bk_total_cost;
	books::bookProf();
	std::cout << "***************************************************";
}
