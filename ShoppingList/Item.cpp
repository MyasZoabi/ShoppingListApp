#include "Item.h"

Item::Item(const std::string& name, Category category, int quantity, bool purchased)
        : name_(name), category_(category), quantity_(quantity), purchased_(purchased) {}

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
