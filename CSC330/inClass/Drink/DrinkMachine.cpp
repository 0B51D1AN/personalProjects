#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Drink {
    public:

int MAXIMUM_CAPACITY = 10;
        double DEFAULT_DRINK_COST = 1.75;

    private:
	int available;
        int consumed;
        int useDefaultCost;
        int useSuppliedCost;
        double drinkCost;
        double moneyMade;
        string name;

    public:
	Drink(string brandName);
        Drink(string brandName, double cost);
	 void vend();
        void refill();
        double profit();
        int drinksSold();
        string getDrinkName();
        int restockAmount();
};


Drink::Drink(string brandName) {
    name = brandName;
    consumed = 0;
    available = 0;
    moneyMade = 0.0;
    drinkCost = DEFAULT_DRINK_COST;
    useDefaultCost = 1;
    useSuppliedCost = 0;
}

Drink::Drink(string brandName, double cost) {
    name = brandName;
    consumed = 0;
    available = 0;
    moneyMade = 0.0;
    drinkCost = cost;
    useDefaultCost = 0;
    useSuppliedCost = 1;
}

void Drink::vend() {
    if (available > 0) {
        available -= 1;
        consumed += 1;
        moneyMade += (useDefaultCost * DEFAULT_DRINK_COST + useSuppliedCost * drinkCost);
        cout << name << " purchased." << endl;
    } else {
        cout << "************" << endl;
        cout << "* SOLD OUT *" << endl;
        cout << "************" << endl;
    }
}

void Drink::refill() {
    available = MAXIMUM_CAPACITY;
}

double Drink::profit() {
    return round(moneyMade * 100.0) / 100.0;
}

int Drink::drinksSold() {
    return consumed;
}

string Drink::getDrinkName() {
    return name;
}

int Drink::restockAmount() {
    return MAXIMUM_CAPACITY - available;
}


int main() {

	vector<Drink> drinks;

	drinks.push_back(Drink("Coke"));
    drinks.push_back(Drink("Sprite"));
    drinks.push_back(Drink("Doctor Pepper"));
    drinks.push_back(Drink("Guinness", 6.25));

for (int i = 0; i < drinks.size(); i++) {
        drinks[i].refill();
    }

for (int i = 0; i < 8; i++) {
        drinks[0].vend();
    }
for (int i = 0; i < 6; i++) {
        drinks[1].vend();
    }

for (int i = 0; i < 2; i++) {
        drinks[2].vend();
    }

for (int i = 0; i < 11; i++) {
        drinks[3].vend();
    }

int totalSold = 0;
    double totalProfit = 0.0;

    for (int i = 0; i < drinks.size(); i++) {
        totalSold += drinks[i].drinksSold();
        totalProfit += drinks[i].profit();
    }

    cout << "A total of " << totalSold << " drinks were sold for a profit of $" << totalProfit << endl;
    cout << endl;

for (int i = 0; i < drinks.size(); i++) {
        cout << drinks[i].restockAmount() << " " << drinks[i].getDrinkName() << " needed to restock machine" << endl;
    }

    return 0;
}







