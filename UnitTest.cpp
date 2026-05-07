#include <gtest/gtest.h>
#include "templates.h"
#include <string>

// --- Тести для шаблону функції hasNoAdjacentDuplicates ---

TEST(FunctionTemplateTest, NoDuplicates) {
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_TRUE(hasNoAdjacentDuplicates(arr, 5));
}

TEST(FunctionTemplateTest, HasAdjacentDuplicates) {
    int arr[] = {1, 2, 2, 3, 4};
    EXPECT_FALSE(hasNoAdjacentDuplicates(arr, 5));
}

TEST(FunctionTemplateTest, EmptyOrSingleElement) {
    int arr[] = {1};
    EXPECT_TRUE(hasNoAdjacentDuplicates(arr, 1));
    EXPECT_TRUE(hasNoAdjacentDuplicates((int*)nullptr, 0));
}

// --- Тести для шаблону класу CircularList ---

TEST(CircularListTest, AddAndFind) {
    CircularList<int> list;
    list.add(10);
    list.add(20);
    
    EXPECT_TRUE(list.find(10));
    EXPECT_TRUE(list.find(20));
    EXPECT_FALSE(list.find(30));
}

TEST(CircularListTest, RemoveElement) {
    CircularList<std::string> list;
    list.add("A");
    list.add("B");
    list.add("C");
    
    EXPECT_TRUE(list.removeNode("B"));
    EXPECT_FALSE(list.find("B"));
    EXPECT_TRUE(list.find("A"));
    EXPECT_TRUE(list.find("C"));
}

TEST(CircularListTest, RemoveLastElement) {
    CircularList<int> list;
    list.add(100);
    EXPECT_TRUE(list.removeNode(100));
    EXPECT_FALSE(list.find(100));
}