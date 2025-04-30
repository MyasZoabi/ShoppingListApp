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
# --- Unit Tests ---
enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")

add_executable(ShoppingListTests
        ${TEST_SOURCES}
        ShoppingList.cpp
        Item.cpp
        User.cpp
)

target_include_directories(ShoppingListTests PRIVATE ${PROJECT_SOURCE_DIR})
add_test(NAME AllTests COMMAND ShoppingListTests)


