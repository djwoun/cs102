// lab5b.cpp
// The program asks the user for a item, item price, and item quantity. Each item's information is stored into a vector. When the user sends an EOF sign, the item infos and totals are displayed.
// Dong Jun Woun
// 10/30/2020
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;
class Item {


public:
    // initializer list
    Item()
        : iName("none"), Description("none"), Price(0), Quantity(0) {}
    // public mutators and accessors
    void SetName(string itemName);
    void SetPrice(double itemPrice);
    void SetQuantity(int itemQuantity);
    void SetDescription(string itemDescription);
    string GetName() const;
    double GetPrice() const;
    int GetQuantity() const;
    string GetDescription() const;
    void Print() const;
    void PrintDescription() const;
    // using a vector items to store all items the user specifies
private:
    // private member variables store an item's name, a real-number to store the price, and an integeter to store the quantity of the item.
    // initializer list
    string iName, Description;
    double Price;
    int Quantity;


};

class ShoppingCart {

public:
    ShoppingCart()
        : CustomerName("none"), date("April 1, 2020") {}
    void SetCustomerName(string sName);
    void SetDate(string sdate);
    void AddItem(const Item&); //******* This function should append the Item passed in to your vector of Item objects.
    void RemoveItem(const string&);
    void ChangeQuantity(const string&, int);
    int FindItemIndex(const string&) const;
    string GetCustomerName() const;
    string GetDate() const;
    int GetTotalQuantity() const;
    double GetTotalCost() const;
    void PrintTotal() const;
    void PrintDescription() const;
    vector<string> shoppingListItem;
    vector<double> shoppingListPrice;
    vector<int> shoppingListQuantity;
    vector<string> shoppingListDescription;


private:
    string CustomerName, date;

};
char PrintMenu();




int main()
{
    Item shop;
    ShoppingCart Customer;
    string customerName;
    string date;
    while (cout << "Enter customer name: ", (getline(cin, customerName))) {
        if ((customerName == "none", customerName == "")) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (customerName != "none") {
            Customer.SetCustomerName(customerName);

            // asks for item quantity
            cout << "Enter today's date: ";
            while (!(getline(cin, date))) {

                if ((cin.eof())) {
                    break;

                }

                // error checking
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter today's date: ";



            }
            if ((cin.eof())) {
                break;

            }


            Customer.SetDate(date);
            cout << endl;

            cout << "Customer name: " << Customer.GetCustomerName() << endl;
            cout << "Today's date: " << Customer.GetDate() << endl;
            cout << endl;
        }
        char option;
        
        do {
            
           


            option = PrintMenu();

            if ((cin.eof())) {
                break;

            }

            if (option == 'a') {
                
                Customer.AddItem(shop);

            }

            if (option == 'd') {
                string PossibleRemoval;
                cout << "REMOVE ITEM FROM CART" << endl;
                cout << "Enter the item name to remove: ";
                getline(cin, PossibleRemoval);

                Customer.RemoveItem(PossibleRemoval);
                cout << endl;
            }
            if (option == 'c') {
                string changeQuantityName;
                int changeQuantity;
                cout << endl;
                cout << "CHANGE ITEM QUANTITY" << endl;
                cout << "Enter the item name: ";
                getline(cin, changeQuantityName);
                cout << "Enter the item quantity : ";
                
                while (!(cin >> changeQuantity) || (changeQuantity <= 0)) {
                    if ((cin.eof())) {
                        break;

                    }
                    // error checking
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter the item quantity : ";

                }
                if ((cin.eof())) {
                    break;

                }
                cin.ignore(100, '\n');

                Customer.ChangeQuantity(changeQuantityName, changeQuantity);
                cout << endl;

            }
            if (option == 'i') {
                Customer.PrintDescription();

            }

            if (option == 'o') {

                Customer.PrintTotal();
            }

        } while (!(option == 'q'));




        break;

        //calls public accessor Print
    }

}





// class Item


void Item::SetName(string itemName) {
    iName = itemName;
}
void Item::SetPrice(double itemPrice) {
    Price = itemPrice;
}
void Item::SetQuantity(int itemQuantity) {
    Quantity = itemQuantity;
}
void Item::SetDescription(string itemDescription) {
    Description = itemDescription;
}

//public accessors called GetName, GetPrice, and GetQuantity which return the value of the corresponding member variables.
string Item::GetName() const {
    return iName;
}
double Item::GetPrice() const {
    return Price;
}
int Item::GetQuantity() const {
    return Quantity;
}
string Item::GetDescription() const {
    return Description;
}

void Item::PrintDescription() const {
    cout << iName << ": " << Description;
}

//public accessor called Print
// prints out the item's name, quantity, individual price read from the member variable, and the total price computed by multiplying the quantity with the item's price
void Item::Print() const {

}

void ShoppingCart::SetCustomerName(string sName) {
    CustomerName = sName;
}
void ShoppingCart::SetDate(string sdate) {
    date = sdate;
}
void ShoppingCart::AddItem(const Item&) {
    // variable to temporarily store item name, price, and quantity
     // object shop
    ///////////////////////////  Shop.Print();
    Item Shop;
    // item Count starts at 1 and increases when the name, price, and quantity is input

    string iName;
    string description;
    double Price;
    int Quantity;
    do  {


        cout << endl;
        cout << "ADD ITEM TO CART " << endl;
        cout << "Enter the item name : " <<flush;
        while (!(getline(cin, iName))) {

            if ((cin.eof())) {
                break;

            }

            // error checking
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the item name: ";



        }
        if ((cin.eof())) {
            break;

        }
        
        if (iName != "none") {
            Shop.SetName(iName);

            // asks for item description
            cout << "Enter the item description: ";
            while (!(getline(cin, description))) {

                if ((cin.eof())) {
                    break;

                }

                // error checking
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the item description: ";



            }
            if ((cin.eof())) {
                break;

            }

            // if Name is not none, the public accessor SetName sets itemname to Name
            if (description != "none") {
                Shop.SetDescription(description);

                // asks for item quantity
                cout << "Enter the item price : $";
                while (!(cin >> Price) || (Price <= 0)) {

                    if ((cin.eof())) {
                        break;

                    }

                    // error checking
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter the item price : $";



                }
                if ((cin.eof())) {
                    break;

                }
                cin.ignore(100, '\n');

                // if Price is above 0, the public accessor SetPrice sets itemPrice to Price
                if (Price > 0) {
                    Shop.SetPrice(Price);

                    // asks for item quantity
                    cout << "Enter the item quantity : ";
                    while (!(cin >> Quantity) || (Quantity <= 0)) {
                        if ((cin.eof())) {
                            break;

                        }
                        // error checking
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter the item quantity : ";

                    }
                    if ((cin.eof())) {
                        break;

                    }
                    cin.ignore(100, '\n');

                    // if Quantity is above 0, the public accessor SetQuantity sets itemQuantity to Price
                    if (Quantity > 0) {
                        // information is not stored if EOF is signaled before the Quantity gets a valid input
                        // information about the items are stored into the vector
                        Shop.SetQuantity(Quantity);
                        shoppingListItem.push_back(Shop.GetName());
                        shoppingListPrice.push_back(Shop.GetPrice());
                        shoppingListQuantity.push_back(Shop.GetQuantity());
                        shoppingListDescription.push_back(Shop.GetDescription());


                        cout << endl;



                    }

                }

            }
        }
        //resets temporary variables
        iName = "none";
        Price = 0;
        Quantity = 0;
        description = "none";
        break;
    }while (iName == "adsf");
}
void ShoppingCart::RemoveItem(const string& PossibleRemoval) {
    for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

        if (PossibleRemoval == shoppingListItem.at(i)) {



            shoppingListItem.erase(shoppingListItem.begin() + i);
            shoppingListPrice.erase(shoppingListPrice.begin() + i);
            shoppingListQuantity.erase(shoppingListQuantity.begin() + i);
            shoppingListDescription.erase(shoppingListDescription.begin() + i);

        }

    }
}
void ShoppingCart::ChangeQuantity(const string& changeQuantityName, int changeQuantity) {
   
    
    for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

        if (changeQuantityName == shoppingListItem.at(i)) {



            shoppingListQuantity.at(i) = changeQuantity;

        }

    }
}

int  ShoppingCart::FindItemIndex(const string& Item) const {

    string FindItemIndex = "Item not found in cart.";
    int itemNUmber=0;
    for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

        if (Item == shoppingListItem.at(i)) {


            FindItemIndex = shoppingListItem.at(i);
            itemNUmber = i;
            i = shoppingListItem.size() + 1;


        }

    }
    if (FindItemIndex == "Item not found in cart.") {
        cout << FindItemIndex;
    }

    return itemNUmber;
} //This function should search for an Item in the vector of Item objects whose name matches the string passed to the function. If an Item is found, return its index in the vector. Otherwise, return -1.

string ShoppingCart::GetCustomerName() const {
    return CustomerName;
}
string ShoppingCart::GetDate() const {
    return date;
}
int ShoppingCart::GetTotalQuantity() const {
    return shoppingListItem.size();
}
double ShoppingCart::GetTotalCost() const {
    double totalCost = 0;
    for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

        // I/O manipulators to display prices to two decimal points
        totalCost = totalCost + shoppingListPrice.at(i) * shoppingListQuantity.at(i);
    }
    return totalCost;
}
void ShoppingCart::PrintTotal() const {



    cout << endl;


    if (GetTotalCost() == 0) {
        cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
        cout << "Number of Items: 0" << endl;
        cout << endl;
        cout << "Total: $0.00" << endl;
    }
    else if (GetTotalCost() > 0) {
        cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
        cout << "Number of Items: " << shoppingListPrice.size() << endl;
        cout << endl;
        for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

            // I/O manipulators to display prices to two decimal points
            cout << shoppingListItem.at(i) << ": " << shoppingListQuantity.at(i) << " at $" << setprecision(2) << fixed << shoppingListPrice.at(i) << " = $" << shoppingListPrice.at(i) * shoppingListQuantity.at(i) << endl;

        }
        cout << endl;
        cout << "Total: $" << GetTotalCost() << endl;
    }



    cout << endl;

}
void ShoppingCart::PrintDescription() const {
    cout << endl;
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
    cout << endl;

    cout << "Item Descriptions" << endl;

    if (shoppingListItem.size() != 0) {
        for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

            // I/O manipulators to display prices to two decimal points
            cout << shoppingListItem.at(i) << ": " << shoppingListDescription.at(i)<< endl;
        }
    }
    else if (shoppingListItem.size() == 0) {
    
        cout << "Shopping cart is empty." << endl;
    }

    cout << endl;
}

char PrintMenu() {
    char option =' ';
    cout << "Menu" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output item descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;

    while (cout << "Choose an option: ", !(cin>> option)) {

        if ((cin.eof())) {
            break;

        }

        // error checking
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter today's date: ";



    }
    cin.ignore(100, '\n');

    return option;


}