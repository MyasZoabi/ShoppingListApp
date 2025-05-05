#include "ShoppingList.h"
#include <algorithm>
#include <cctype>  // for std::tolower

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

int ShoppingList::getTotalItemsCount() const {
    int total = 0;
    for (const auto& [_, items] : itemsByCategory) {
        total += items.size();
    }
    return total;
}

std::vector<Item> ShoppingList::getAllItems() const {
    std::vector<Item> all;
    for (const auto& [_, items] : itemsByCategory) {
        all.insert(all.end(), items.begin(), items.end());
    }
    return all;
}

std::vector<Item> ShoppingList::findItemsByCategory(Category category) const {
    auto it = itemsByCategory.find(category);
    if (it != itemsByCategory.end()) {
        return it->second;
    }
    return {};
}

std::vector<Item> ShoppingList::findItemsByName(const std::string& searchTerm) const {
    std::vector<Item> result;

    auto toLower = [](std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return s;
    };

    std::string termLower = toLower(searchTerm);

    for (const auto& [_, items] : itemsByCategory) {
        for (const auto& item : items) {
            if (toLower(item.getName()).find(termLower) != std::string::npos)
                result.push_back(item);
        }
    }
    return result;
}
