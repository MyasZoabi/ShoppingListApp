#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Item.h"  // use correct path to your Item.h

TEST_CASE("Item behavior", "[Item]") {   // ← no semicolon
Item apple("Apple", Category::Food, 3);

REQUIRE(apple.getName() == "Apple");
REQUIRE(apple.getQuantity() == 3);
REQUIRE_FALSE(apple.isPurchased());

apple.markAsPurchased();
REQUIRE(apple.isPurchased());
}

