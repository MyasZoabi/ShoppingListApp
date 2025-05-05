#include "Item.h"
#include <stdexcept>

Item::Item(const std::string& name, Category category, int quantity, bool purchased)
        : name_(name), category_(category), quantity_(quantity), purchased_(purchased) {
    if(quantity<0)
        throw std::logic_error("Qty can not be negative");
}

void Item::markAsPurchased() {
    purchased_ = true;
}

bool Item::isPurchased() const {
    return purchased_;
}

Category Item::getCategory() const {
    return category_;
}

const std::string& Item::getName() const {
    return name_;
}

int Item::getQuantity() const {
    return quantity_;
}
