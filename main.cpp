#include <iostream>

using namespace std;

class cashRegister
{
private:
    int cashOnHand;
public:
    cashRegister();
    cashRegister(int cashIn);
    int getCurrentBalance();
    void acceptAmount(int amountIn);
};

class dispenserType
{
private:
    int numberOfItems;
    int cost;
public:
    dispenserType();
    dispenserType(int setNoOfItems, int setCost);
    int getNoOfItems();
    int getCost();
    void makeSale();
};

cashRegister::cashRegister()
{
    cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn)
{
    cashOnHand = cashIn;
}

int cashRegister::getCurrentBalance()
{
    return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}

dispenserType::dispenserType()
{
    numberOfItems = 50;
    cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    numberOfItems = setNoOfItems;
    cost = setCost;
}

int dispenserType::getNoOfItems()
{
    return numberOfItems;
}

int dispenserType::getCost()
{
    return cost;
}

void dispenserType::makeSale()
{
    numberOfItems--;
}

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);


int main() {
    cashRegister counter;
    dispenserType candy(100, 50);
    dispenserType chips(100, 65);
    dispenserType gum(75,45);
    dispenserType cookies(50, 85);
    int choice;
    showSelection();
    cin >> choice;
    while (choice != 5)
    {
        switch (choice)
        {
            case 1:
                sellProduct(candy, counter);
                break;
            case 2:
                sellProduct(chips, counter);
                break;
            case 3:
                sellProduct(gum, counter);
                break;
            case 4:
                sellProduct(cookies, counter);
            case 5:
                cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}

void showSelection()
{
    cout << "Welcome to the junk yard" << endl;
    cout << "To select an item enter: " << endl;
    cout << "1 for candy" << endl;
    cout << "2 for chips" << endl;
    cout << "3 for gum" << endl;
    cout << "4 for cookies" << endl;
    cout << "5 to exit" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter )
{
    int amount;
    int amount2;
    if (product.getNoOfItems() > 0)
    {
        cout << "Please deposit " << product.getCost()
        << " cents" << endl;
        cin >> amount;
        if (amount < product.getCost())
        {
            cout << "Please deposit another " <<
            product.getCost() - amount << " cents" << endl;
            cin >> amount2;
            amount = amount + amount2;
        }

        if (amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom "
            << " and enjoy!" << endl;
        }
        else
            cout << "The amount isnt enough." << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
        << endl << endl;
    }
    else
        cout << "Sorry this item is sold out" << endl;
}