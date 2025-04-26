#pragma once

#include <string>
#include "Category.h"   // <--- include the Category enum

class Item {
public:
    Item(const std::string& name, Category category, int quantity, bool purchased = false);

    void markAsPurchased();
    bool isPurchased() const;

    Category getCategory() const;
    const std::string& getName() const;
    int getQuantity() const;

private:
    std::string name_;
    Category category_;
    int quantity_;
    bool purchased_;
};
