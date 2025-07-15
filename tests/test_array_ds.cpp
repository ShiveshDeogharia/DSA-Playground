#include <gtest/gtest.h>
#include "../include/array_ds.h"

namespace dsa {

TEST(ArrayDSTest, PushBackWorks) {
    ArrayDS arr;
    arr.push_back(10);
    arr.push_back(20);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
}

TEST(ArrayDSTest, InsertAtWorks) {
    ArrayDS arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.insert_at(1, 2);  // Insert 2 between 1 and 3
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);
}

TEST(ArrayDSTest, EraseAtWorks) {
    ArrayDS arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.erase_at(1);  // Remove 6
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr.get(0), 5);
    EXPECT_EQ(arr.get(1), 7);
}

}
