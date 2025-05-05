#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Item.h"

TEST_CASE("Item behavior", "[Item]") {
    Item apple("Apple", Category::FOOD, 3);

    REQUIRE(apple.getName() == "Apple");
    REQUIRE(apple.getQuantity() == 3);
    REQUIRE_FALSE(apple.isPurchased());

    apple.markAsPurchased();
    REQUIRE(apple.isPurchased());

    Item* item;
    REQUIRE_THROWS_AS(item = new Item("rice", Category::FOOD, -1), std::logic_error);
}
