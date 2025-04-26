#include "ShoppingList.h"
#include <algorithm>

ShoppingList::ShoppingList(const std::string& name) : name(name) {}

void ShoppingList::addItem(const Item& item) {
    itemsByCategory[item.getCategory()].push_back(item);
    notifyObservers();
}

void ShoppingList::removeItem(const Item& item) {
    auto& vec = itemsByCategory[item.getCategory()];
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&](const Item& i) {
        return i.getName() == item.getName();
    }), vec.end());
    notifyObservers();
}

void ShoppingList::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void ShoppingList::notifyObservers() {
    for (Observer* obs : observers) {
        obs->update(this);
    }
}

std::string ShoppingList::getName() const {
    return name;
}

int ShoppingList::getRemainingItemsCount() const {
    int count = 0;
    for (const auto& [_, items] : itemsByCategory) {
        for (const auto& item : items) {
            if (!item.isPurchased()) count++;
        }
    }
    return count;
}

std::vector<Item> ShoppingList::getAllItems() const {
    std::vector<Item> all;
    for (const auto& [_, items] : itemsByCategory) {
        all.insert(all.end(), items.begin(), items.end());
    }
    return all;
}
