#include "catch.hpp"
#include "../ShoppingList.h"

TEST_CASE("Add and remove items", "[ShoppingList]") {
    ShoppingList list("Groceries");

    Item rice("Rice", Category::FOOD, 1);
    Item soap("Soap", Category::CLEANING, 1);

    list.addItem(rice);
    list.addItem(soap);

    SECTION("Items are added") {
        REQUIRE(list.getTotalItemsCount() == 2);

        auto foodItems = list.findItemsByCategory(Category::FOOD);
        REQUIRE(foodItems.size() == 1);
        REQUIRE(foodItems[0].getName() == "Rice");

        auto cleaningItems = list.findItemsByCategory(Category::CLEANING);
        REQUIRE(cleaningItems.size() == 1);
        REQUIRE(cleaningItems[0].getName() == "Soap");
    }

    SECTION("Items are removed correctly") {
        list.removeItem(soap);
        REQUIRE(list.getTotalItemsCount() == 1);

        auto cleaningItems = list.findItemsByCategory(Category::CLEANING);
        REQUIRE(cleaningItems.empty());

        auto allItems = list.getAllItems();
        REQUIRE(allItems.size() == 1);
        REQUIRE(allItems[0].getName() == "Rice");
    }
}

TEST_CASE("Remaining items count", "[ShoppingList]") {
    ShoppingList list("RemainingTest");

    Item rice("Rice", Category::FOOD, 1);
    Item beans("Beans", Category::FOOD, 1);

    rice.markAsPurchased();

    list.addItem(rice);   // already marked as purchased
    list.addItem(beans);  // still to be purchased

    REQUIRE(list.getTotalItemsCount() == 2);
    REQUIRE(list.getRemainingItemsCount() == 1);
}

TEST_CASE("Find items by category", "[ShoppingList]") {
    ShoppingList list("CategoryTest");

    list.addItem(Item("Rice", Category::FOOD, 1));
    list.addItem(Item("Pasta", Category::FOOD, 1));
    list.addItem(Item("Soap", Category::CLEANING, 1));

    auto foodItems = list.findItemsByCategory(Category::FOOD);
    REQUIRE(foodItems.size() == 2);

    std::vector<std::string> names;
    for (const auto& item : foodItems)
        names.push_back(item.getName());

    REQUIRE(std::find(names.begin(), names.end(), "Rice") != names.end());
    REQUIRE(std::find(names.begin(), names.end(), "Pasta") != names.end());
}

TEST_CASE("Find items by name (case-insensitive substring search)", "[ShoppingList]") {
    ShoppingList list("NameSearch");

    list.addItem(Item("Rice Krispies", Category::FOOD, 1));
    list.addItem(Item("Rice Pudding", Category::FOOD, 1));
    list.addItem(Item("Milk", Category::FOOD, 1));

    auto found = list.findItemsByName("rice");
    REQUIRE(found.size() == 2);

    std::vector<std::string> resultNames;
    for (const auto& item : found)
        resultNames.push_back(item.getName());

    REQUIRE(std::find(resultNames.begin(), resultNames.end(), "Rice Krispies") != resultNames.end());
    REQUIRE(std::find(resultNames.begin(), resultNames.end(), "Rice Pudding") != resultNames.end());
}

TEST_CASE("Edge case: search for empty string returns all items", "[ShoppingList]") {
    ShoppingList list("EdgeCase");

    list.addItem(Item("Bread", Category::FOOD, 1));
    list.addItem(Item("Butter", Category::FOOD, 1));

    auto found = list.findItemsByName("");
    REQUIRE(found.size() == 2);
}
