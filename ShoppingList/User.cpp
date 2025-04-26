#include "User.h"
#include <iostream>

User::User(const std::string& name) : name(name) {}

void User::addSharedList(ShoppingList* list) {
    sharedLists.push_back(list);
    list->addObserver(this);
}

void User::update(ShoppingList* list) {
    std::cout << "User " << name << " was notified about changes in list: "
              << list->getName() << ". Remaining items: "
              << list->getRemainingItemsCount() << std::endl;
}
