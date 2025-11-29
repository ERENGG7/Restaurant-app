// November 6.0.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<map>
#include<fstream>

//Text colors ANSII:
#define RESET "\033[0m"//for default color,background color &font.
#define RED "\033[31m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

//Background colors ANSII: 
#define REDB "\033[41m"
#define YELLOWB  "\033[43m"
#define BLUEB  "\033[44m"

//Fonts ANSII: 
#define BOLD "\033[1m"
#define ITALIC_STYLE "\033[3m"

const std::string PHONE_NUMBER = "088_230_6840";

//structs:
struct Meal {
	std::string name;
	double price;
	bool isSalad;
	bool isChickenMeal;
	bool isBeef;
	bool isPork;
	bool isFish;
};
struct Drink {
	std::string name;
	double price;
	bool containsAlcohol;
	bool carbonated;
	bool isCocktail;
};
struct Desert {
	std::string name;
	double price;
};
//Database for meals:
const std::map<int, Meal>MEALS = {
	{121,{"Shposka salad",11.99,true,false,false,false,false}},
	{122,{"Caesar salad",14.60,true,false,false,false,false}},
	{123,{"Corsican salad",13.90,true,false,false,false,false}},
	{124,{"Selska salad",12.20,true,false,false,false,false}},
	{125,{"Caprese salad",14.30,true,false,false,false,false}},
	{126,{"Greek salad",13.20,true,false,false,false,false}},
	{127,{"Chicken steak",16.20,false,true,false,false,false}},
	{128,{"Chicken nuggets",14.20,false,true,false,false,false}},
	{129,{"Chicken carolina",18.49,false,true,false,false,false}},
	{130,{"Chicken soup",13.20,false,true,false,false,false}},
	{131,{"Beef steak",16.10,false,false,true,false,false}},
	{132,{"Beef meatballs",13.20,false,false,true,false,false}},
	{133,{"Beef kebabs",13.10,false,false,true,false,false}},
	{134,{"Kebabs Balkanturist",13.15,false,false,true,false,false}},
	{135,{"Beef wine kebab",15.50,false,false,true,false,false}},
	{136,{"Grilled pork",13.50,false,false,false,true,false}},
	{137,{"Pork knuckle",14.00,false,false,false,true,false}},
	{138,{"Pork with potatoes",13.80,false,false,false,true,false}},
	{139,{"Fish soup",11.25,false,false,false,false,true}},
	{140,{"Trout with vegetables",11.40,false,false,false,false,true}},
	{141,{"Grilled trout",12.20,false,false,false,false,true}},
	{142,{"Sea bass",20.10,false,false,false,false,true}},
	{143,{"Breaded fish with potato chips",13.20,false,false,false,false,true}},

};
//Database for desserts:
const std::map<int, Desert>DESSERTS = {
	{221,{"Chocolate cake",9.90}},
	{222,{"Vanilla cake",9.90}},
	{223,{"Balaton cake",10.90}},
	{224,{"Chocolate souffle",8.90}},
	{225,{"Biscuit cake",7.40}},
	{226,{"Noiset Pancakes",18.90}},
};
//Database for drinks: 
const std::map<int, Drink>DRINKS = {
	{1,{"Water",0.90,false,false,false}},
	{2,{"Prisun Apple",1.15,false,false,false}},
	{3,{"Prisun Strawberry and banana",1.25,false,false,false}},
	{4,{"Prisun Orange",1.25,false,false,false}},
	{5,{"Prisun Sour Cherry",1.25,false,false,false}},
	{6,{"Prisun Mango",1.30,false,false,false}},
	{7,{"Pepsi-cola",1.50,false,true,false}},
	{8,{"Soda Evervess",1.50,false,true,false}},
	{9,{"Tonik Evervess",1.50,false,true,false}},
	{10,{"Tonik Evervess Pink",1.50,false,true,false}},
	{11,{"Mirinda Orange",1.50,false,true,false}},
	{12,{"Mirinda Lemon",1.50,false,true,false}},
	{13,{"Mirinda Strawberry and lychee",1.50,false,true,false}},
	{14,{"Fresh Orange",2.10,false,false,false}},
	{15,{"Fresh Lemon",2.10,false,false,false}},
	{16,{"Fresh Mix",2.20,false,false,false}},
	{17,{"Kamenitsa",3.10,true,true,false}},
	{18,{"Madri",4.10,true,true,false}},
	{19,{"Stella Artois",4.10,true,true,false}},
	{20,{"White wine 200ml",6.20,true,false,false}},
	{21,{"Red wine 200ml",7.10,true,false,false}},
	{22,{"Rose 200ml",7.10,true,false,true}},
	{23,{"Aperol Spritz",6.20,true,false,true}},
	{24,{"Martini",7.20,true,false,true}},
};
//design for title:
void printTitle() {
	std::cout << WHITE << "+-------------------------------------+\n"
		<< "| RESTAURANT========================= |\n" << RESET
		CYAN << "| ========================== BALATON  |\n"
		<< "+-------------------------------------+" << RESET << std::endl;
}
//printing outline lines:
void printLine() {
	std::cout << "+-------------------------------------+" << std::endl;
}
//Information Text for the first window
void printMainInfo(std::vector<std::string>basket) {
	printTitle();
	std::cout << "|Restaurant Balaton - a cozy          |"
		<< "\n|restaurant with European and         |"
		<< "\n|Bulgarian cuisine.                   |"
		<< "\n|It has 80 indoor and 40 outdoor seats|"
		<< "\n|It offers salads, fish,              |"
		<< "\n|meat specialties, pasta and homemade |"
		<< "\n|desserts.Working hours :             |"
		<< "\n|10 : 00-23 : 30. Suitable for        |"
		<< "\n|family gatherings and theme dinners. |"
		<< "\n|Phone 032 311 112.                   |" << std::endl;
	printLine();
	std::cout << "|Enter (1) to menu.                   |"
		<< "\n|Enter (2) to add to basket           |"
		<< "\n|Enter (3) to quit                    |" << std::endl;

	if (!basket.empty()) {
		std::cout << "|Enter (4) to see basket              |" << std::endl;
		std::cout << "|Enter (5) to pay                     |" << std::endl;
	}
	printLine();
}
//Choices infor for first window
void printMenuInfo() {
	printTitle();
	std::cout << "|Enter (1) to see drinks.             |"
		<< "\n|Enter (2) to see meals               |"
		<< "\n|Enter (3) to see desserts            |"
		<< "\n|Enter (4) to quit                    |" << std::endl;
	printLine();
	std::cout << "Enter your choice: ";
}
//Draw creditcard imaginative letters
void creditCardsInfo() {
	std::cout << REDB << WHITE << "Master"
		<< RESET << YELLOWB << WHITE << "Card" << RESET << ' ';
	std::cout << BLUEB << WHITE << "Visa" << RESET << ' ';
	std::cout << BLUEB << WHITE << "America express" << RESET << std::endl;

}
//Choices info for payment window
void paymentInfo() {
	printTitle();
	creditCardsInfo();
	printLine();
	std::cout << "|Enter (1) to pay with card.          |"
		<< "\n|Enter (2) to pay with cash.          |"
		<< "\n|Enter (3) to quit.                   |" << std::endl;
	printLine();
	std::cout << "How you want to pay: ";
}
//Message after clicking one of choices info
void paymentMessage(std::string cardCash) {
	printLine();
	//if choice is to pay with card:
	if (cardCash == "card") {
		std::cout << "|Expect a call from                   |"
			<< "\n|a provider in 20 minutes.            |";
	}
	//if choice is to pay with cash:
	else if (cardCash == "cash") {
		std::cout << "|Expect a call from                   |"
			<< "\n|a provider in 20 minutes.            |"
			<< "\n|Payment will be made upon delivery.  |";
	}
	std::cout << "\n|Thank you for choosing               |"
		<< "\n|Balaton Restaurant.                  |"
		<< "\n|The restaurant team wishes           |"
		<< "\n|you a pleasant day and bon appetit.  |" << std::endl;
	printLine();
}
//Choics for basket window
void seeBasketInfo() {
	printLine();
	std::cout << "|Enter (1) to remove last product     |"
		<< "\n|Enter (2) to quit.                   |" << std::endl;
	printLine();
	std::cout << "\nEnter choice:";
}
void clearConsole() {
	system("cls");
}
//Message for press key and pause system:
void pressKeyMessage() {
	std::cout << "->Press any key to continue." << std::endl;
	system("pause>0");
}
//Message:
void printExceptionMessageAndPause() {
	std::cout << RED << "Invalid choice" << RESET << '\a' << std::endl;
	pressKeyMessage();
}
//Check for exception:for choices: 
bool haveException(std::string tryChoice, int min, int max) {
	int choice;
	try { choice = stoi(tryChoice); }
	catch (...) { return true; }
	if (choice < min || choice>max) { return true; }
	return false;
}
//haveException for keys:
bool haveExceptionForProducts(std::string tryChoice) {
	int choice;
	try { choice = std::stoi(tryChoice); }
	catch (...) { return true; }
	return false;
}
//Func for getting the sum of prices elements:
double getTotalPrice(const std::vector<double>& prices) {
	double totalPrice = 0;
	for (const auto& p : prices) { totalPrice += p; }
	return totalPrice;
}
//Rounding the sum form getTotalPrice():
void printTotalPrice(const std::vector<double>& prices) {
	std::cout << "Total: "
		<< std::fixed
		<< std::setprecision(2)
		<< getTotalPrice(prices) << " BGN" << std::endl;
}
//Separator for drinks by key: 
void separateDrinks(std::vector<std::string>& alcoholDrinks,
	std::vector<std::string>& carbonatedDrinks,
	std::vector<std::string>& nonCarbonated) {

	for (const auto& t : DRINKS) {
		std::ostringstream oos;
		oos << t.first << ' ' << t.second.name << ' '
			<< std::fixed << std::setprecision(2) << t.second.price << " BGN";
		std::string res = oos.str();
		//separaing by values:
		if (t.second.containsAlcohol) { alcoholDrinks.push_back(res); }
		if (t.second.carbonated) { carbonatedDrinks.push_back(res); }
		if (!t.second.carbonated) { nonCarbonated.push_back(res); }
	}
}
//Printing every vector: 
void printSeparatedElements(std::string message, const std::vector<std::string>& elements) {
	std::cout << CYAN << ITALIC_STYLE
		<< message << RESET << std::endl;
	for (const auto& e : elements) { std::cout << e << std::endl; }
}
void printSeparatedDrinks(const std::vector<std::string>& alcoholDrinks,
	const std::vector<std::string>& carbonatedDrinks,
	const std::vector<std::string>& nonCarbonated) {
	//printing every vector one by one
	printSeparatedElements("\nNot-carbonated drinks:", nonCarbonated);
	printSeparatedElements("\nCarbonated drinks:", carbonatedDrinks);
	printSeparatedElements("\nAlcohol drinks & cocktails(18+):", alcoholDrinks);
}
//Printing meals meun.Not separated
void showDrinksMenu(int a) {
	std::vector<std::string>alcoholDrinks;
	std::vector<std::string>carbonatedDrinks;
	std::vector<std::string>nonCarbonated;
	if (a == 1) { clearConsole(); printTitle(); }
	std::cout << BOLD << "Drinks menu: " << RESET << std::endl;
	separateDrinks(alcoholDrinks, carbonatedDrinks, nonCarbonated);
	printSeparatedDrinks(alcoholDrinks, carbonatedDrinks, nonCarbonated);
	if (a == 1) { pressKeyMessage(); }
}
//Func for separating meals by key
void separateMeals(std::vector<std::string>& salads,
	std::vector<std::string>& chicken,
	std::vector<std::string>& beef,
	std::vector<std::string>& pork,
	std::vector<std::string>& fish) {

	for (const auto& t : MEALS) {
		std::ostringstream oos;
		oos << t.first << ' ' << t.second.name << ' '
			<< std::fixed << std::setprecision(2) << t.second.price << " BGN";
		std::string res = oos.str();
		//separating by values
		if (t.second.isSalad) { salads.push_back(res); }
		if (t.second.isChickenMeal) { chicken.push_back(res); }
		if (t.second.isBeef) { beef.push_back(res); }
		if (t.second.isPork) { pork.push_back(res); }
		if (t.second.isFish) { fish.push_back(res); }
	}
}
//Printing the separated meals by boolean values:
void printSeparatedMeals(const std::vector<std::string>& salads,
	const std::vector<std::string>& chicken,
	const std::vector<std::string>& beef,
	const std::vector<std::string>& pork,
	const std::vector<std::string>& fish) {
	//printing every vector one by one
	printSeparatedElements("\nSalads:", salads);
	printSeparatedElements("\nChicken:", chicken);
	printSeparatedElements("\nBeef:", beef);
	printSeparatedElements("\nPork:", pork);
	printSeparatedElements("\nFish:", fish);
}
//Printing seprated meals menu:
void showMealsMenu(int a) {
	std::vector<std::string>salads;
	std::vector<std::string>chicken;
	std::vector<std::string>beef;
	std::vector<std::string>pork;
	std::vector<std::string>fish;

	if (a == 1) { clearConsole(); printTitle(); }
	std::cout << BOLD << "Meals menu: " << RESET << std::endl;
	separateMeals(salads, chicken, beef, pork, fish);
	printSeparatedMeals(salads, chicken, beef, pork, fish);

	if (a == 1) { pressKeyMessage(); }
}
//Printing deserts:
void showDesserts(int a) {
	if (a == 1) { clearConsole(); printTitle(); }
	std::cout << BOLD << "Desserts menu:" << RESET << std::endl;
	std::cout << std::endl;
	for (const auto& t : DESSERTS) {
		std::cout << t.first << ' ' << t.second.name
			<< ' ' << t.second.price << " BGN" << std::endl;
	}
	if (a == 1) { pressKeyMessage(); }
}
//Printing the menu with separated meals drinks and desserts
void showMenu() {
	std::string tryChoice;
	int choice;
	while (true) {
		clearConsole();
		printMenuInfo();
		getline(std::cin, tryChoice);

		if (haveException(tryChoice, 1, 4)) {
			printExceptionMessageAndPause(); continue;
		}
		choice = stoi(tryChoice);
		switch (choice) {
		case 1:showDrinksMenu(1); break;
		case 2:showMealsMenu(1); break;
		case 3:showDesserts(1); break;
		case 4:return; break;
		}
	}
}
//add to basket: 
void addToBasketIS(std::vector<std::string>& basket,
	std::vector<double>& prices, std::string& res,
	bool& isRunning) {
	std::string tryNumber;
	int number;

	while (true) {
		clearConsole();
		printTitle();
		std::cout << "code|" << "name of product|"
			<< " price" << std::endl;
		//Printing every separated menu one by one: 
		showDrinksMenu(0);
		std::cout << std::endl;
		showMealsMenu(0);
		std::cout << std::endl;
		showDesserts(0);

		std::cout << res;
		getline(std::cin, tryNumber);
		if (tryNumber == "esc") { isRunning = false; break; }
		if (haveExceptionForProducts(tryNumber)) {
			printExceptionMessageAndPause(); continue;
		}
		number = stoi(tryNumber);
		auto tt = DRINKS.find(number);
		auto it = MEALS.find(number);
		auto dr = DESSERTS.find(number);
		//add to vectors values if key was found:
		if (tt != DRINKS.end()) {
			basket.push_back(tt->second.name);
			prices.push_back(tt->second.price);
			res += std::to_string(number) + '\n';
			break;
		}
		if (it != MEALS.end()) {
			basket.push_back(it->second.name);
			prices.push_back(it->second.price);
			res += std::to_string(number) + '\n';
			break;
		}
		if (dr != DESSERTS.end()) {
			basket.push_back(dr->second.name);
			prices.push_back(dr->second.price);
			res += std::to_string(number) + '\n';
			break;
		}
		//if key was not found: 
		printExceptionMessageAndPause();
	}
}
//add to basket main opeartion: 
void addToBasket(std::vector<std::string>& basket,
	std::vector<double>& prices) {

	std::string res = "\nWrite (esc) to quit.\n";
	bool isRunning = true;
	while (isRunning) {
		res += "Enter number of product to add:";
		addToBasketIS(basket, prices, res, isRunning);
	}
}
//Func for removing products form users basket
void seeBasket(std::vector<std::string>& basket,
	std::vector<double>& prices, int& maxNum) {

	std::string tryChoice;
	int choice;
	while (true) {
		clearConsole();
		printTitle();
		for (const auto& t : basket) { std::cout << t << std::endl; }
		seeBasketInfo();
		getline(std::cin, tryChoice);
		if (haveException(tryChoice, 1, 2)) {
			printExceptionMessageAndPause(); continue;
		}
		choice = stoi(tryChoice);
		if (choice == 1) {
			if (!basket.empty()) { basket.pop_back(); prices.pop_back(); }
			if (basket.empty()) { maxNum = 3; break; }
			continue;
		}
		if (choice == 2) { break; }
		printExceptionMessageAndPause();
	}
}
//Importing the products to text file in laptop "client.txt"
void importToFile(const std::vector<std::string>& basket,
	const std::vector<double>& prices, int numberOfOrder, std::string txt) {

	std::ofstream file("client.txt");
	file << "      REQUEST      " << std::endl;
	for (int i = 0; i < basket.size(); i++) {
		file << i + 1 << ':' << basket[i] << std::endl;
	}
	file << std::fixed
		<< std::setprecision(2) << getTotalPrice(prices) << " BGN" << std::endl;
	file << "Order number: " << numberOfOrder << "." << std::endl;
	file << "Phone: " << PHONE_NUMBER << std::endl;
	if (txt == "card") { file << "PAY WITH CARD!" << std::endl; }
	if (txt == "cash") { file << "PAY WITH CASH!" << std::endl; }
}
//Function for payment window 
void payment(std::string type, const std::vector<std::string>& basket,
	const std::vector<double>& prices, int numberOfOrder) {
	clearConsole();
	printTitle();
	//Printing elements in vector basket: 
	std::cout << "Products: " << std::endl;
	for (int i = 0; i < basket.size(); i++) {
		std::cout << i + 1 << ':' << basket[i] << std::endl;
	}
	printTotalPrice(prices);
	std::cout << "\nOrder number: " << numberOfOrder << std::endl;
	paymentMessage(type);
	importToFile(basket, prices, numberOfOrder, type);
	pressKeyMessage();
}
//Function for clearing vector for prices & basket:
void reset(std::vector<std::string >& basket, std::vector<double>prices, int& maxNum) {
	basket.clear();
	prices.clear();
	maxNum = 3;
}
//Functions that operate program depending on users choice
void makePayment(std::vector<std::string>& basket, int& maxNum,
	std::vector<double>& prices) {
	int numberOfOrder = rand() % 1000 + 1000;
	std::string tryChoice;
	int choice;
	while (true) {
		clearConsole();
		paymentInfo();
		getline(std::cin, tryChoice);

		if (haveException(tryChoice, 1, 3)) {
			printExceptionMessageAndPause(); continue;
		}
		choice = stoi(tryChoice);
		if (choice == 1) {
			payment("card", basket, prices, numberOfOrder);
			reset(basket, prices, maxNum); break;
		}
		if (choice == 2) {
			payment("cash", basket, prices, numberOfOrder);
			reset(basket, prices, maxNum); break;
		}
		if (choice == 3) { break; }
	}
}
//Function for main operaions:
void restaurantApplication() {
	std::vector<double>prices;
	std::vector<std::string>basket;
	std::string tryChoice;
	int maxNum = 3;
	//Main operations:
	while (true) {
		clearConsole();
		printMainInfo(basket);

		std::cout << "Enter your choice: ";
		getline(std::cin, tryChoice);

		if (!basket.empty()) { maxNum = 5; }
		if (haveException(tryChoice, 1, maxNum)) {
			printExceptionMessageAndPause(); continue;
		}
		int choice = std::stoi(tryChoice);
		switch (choice) {
		case 1:showMenu(); break;
		case 2:addToBasket(basket, prices); break;
		case 3:return; break;//break from main().
		case 4:seeBasket(basket, prices, maxNum); break;
		case 5:makePayment(basket, maxNum, prices); break;
		}
	}
}
int main() {
	srand(time(0));
	restaurantApplication();
	return 0;
}
