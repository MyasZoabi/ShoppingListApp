#include <iostream>
#include "User.h"
#include "ShoppingList.h"
#include "Item.h"
#include "Category.h"

int main() {
    User mias("Mias");
    User andrea("Andrea");

    ShoppingList groceries("Weekly Groceries");

    mias.addSharedList(&groceries);
    andrea.addSharedList(&groceries);

    Item milk("Milk", Category::FOOD, 2);
    groceries.addItem(milk);

    Item soap("Soap", Category::CLEANING, 1);
    groceries.addItem(soap);

    return 0;
}
