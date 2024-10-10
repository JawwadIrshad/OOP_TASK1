#include <iostream>
#include <string>
using namespace std;

class pizza {
private:
    string pizza_size;
    string pizza_crust;
    string toppings[10];
    int List_of_toppings;
    double price;

public:
    pizza() {
        List_of_toppings = 0;
        price = 0.0;
    }

    void initializePizza(string size, string crust) {
        pizza_size = size;
        pizza_crust = crust;
        List_of_toppings = 0;

        if (size == "Small") price = 350;
        else if (size == "Medium") price = 500;
        else if (size == "Large") price = 850;
        else if (size == "X-Large") price = 1000;
    }

    void addTopping(string topping) {
        if (List_of_toppings < 10) {
            toppings[List_of_toppings++] = topping;
        } else {
            cout << "Cannot add more toppings. Maximum limit reached." << endl;
        }
    }

    double calculateTotalPrice() const {
        return price + (List_of_toppings * 50);  
    }

    void showPizzaInfo() const {
        cout << "Pizza Type:" << endl;
        cout << "Size: " << pizza_size << endl;
        cout << "Crust: " << pizza_crust << endl;
        cout << "Toppings: ";
        if (List_of_toppings == 0) {
            cout << "No toppings added.";
        } else {
            for (int i = 0; i < List_of_toppings; ++i) {
                cout << toppings[i];
                if (i != List_of_toppings - 1) cout << ", ";
            }
        }
        cout << endl;
        cout << "Total Price: $" << calculateTotalPrice() << endl;
    }
};

int main() {
    pizza myPizza;
    myPizza.initializePizza("X-Large", "Thin Crust");
    myPizza.addTopping("BBQ chicken ");
    myPizza.addTopping("Jalapeno");
    myPizza.addTopping("Cheese");

    myPizza.showPizzaInfo();

    return 0;
}