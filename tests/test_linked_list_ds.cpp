#include <gtest/gtest.h>
#include "../include/linked_list_ds.h"

namespace dsa {

TEST(LinkedListDSTest, PushFrontWorks) {
    LinkedListDS list;
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.get(0), 20);
    EXPECT_EQ(list.get(1), 10);
}

TEST(LinkedListDSTest, PushBackWorks) {
    LinkedListDS list;
    list.push_back(5);
    list.push_back(15);
    EXPECT_EQ(list.get(0), 5);
    EXPECT_EQ(list.get(1), 15);
}

TEST(LinkedListDSTest, DeleteValueWorks) {
    LinkedListDS list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.delete_value(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.get(1), 3);
    EXPECT_FALSE(list.delete_value(42));  // not present
}

TEST(LinkedListDSTest, SearchReturnsCorrectIndex) {
    LinkedListDS list;
    list.push_back(11);
    list.push_back(22);
    list.push_back(33);
    EXPECT_EQ(list.search(22), 1);
    EXPECT_EQ(list.search(99), -1);
}

}
