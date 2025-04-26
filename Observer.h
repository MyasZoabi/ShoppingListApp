#ifndef OBSERVER_H
#define OBSERVER_H

class ShoppingList;

class Observer {
public:
    virtual void update(ShoppingList* list) = 0;
    virtual ~Observer() = default;
};

#endif
