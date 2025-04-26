#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "ShoppingList.h"
#include "Observer.h"

class User : public Observer {
private:
    std::string name;
    std::vector<ShoppingList*> sharedLists;

public:
    explicit User(const std::string& name);
    void addSharedList(ShoppingList* list);
    void update(ShoppingList* list) override;
};

#endif
