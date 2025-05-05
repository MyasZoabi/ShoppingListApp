#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>
#include <vector>
#include <map>
#include "Item.h"
#include "Observer.h"

class ShoppingList {
private:
    std::string name;
    std::map<Category, std::vector<Item>> itemsByCategory;
    std::vector<Observer*> observers;

public:
    explicit ShoppingList(const std::string& name);

    void addItem(const Item& item);
    void removeItem(const Item& item);

    void addObserver(Observer* observer);
    void notifyObservers();
    std::string getName() const;

    int getRemainingItemsCount() const;
    int getTotalItemsCount() const;

    std::vector<Item> getAllItems() const;
    std::vector<Item> findItemsByCategory(Category category) const;
    std::vector<Item> findItemsByName(const std::string& searchTerm) const;
};

#endif
