cmake_minimum_required(VERSION 3.24)
project(ShoppingListApp)

set(CMAKE_CXX_STANDARD 17)

# Real App
add_executable(ShoppingListApp
        main.cpp
        User.cpp
        ShoppingList.cpp
        Item.cpp
        Observer.h
        Category.h
        Item.h
        ShoppingList.h
        User.h
)

# Include the tests folder for the second executable
include_directories(tests)

# Test Executable
add_executable(ShoppingListTests
        tests/test_item.cpp
        Item.cpp
)

