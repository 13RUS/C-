//
// Created by Aleksey Leshchankin on 19.06.2022.
//

#include "list.hpp"

#include <gtest/gtest.h>


//--------- Basic Checks ---------
TEST(ListBasic, Empty) {
    // Arrange
    homeworkspace::List<int> list;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(list.size(), 0u);
    ASSERT_TRUE(list.empty());
}

TEST(ListBasic, Size) {
    // Arrange
    const int count = 10;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }
    // Assert
    ASSERT_EQ((list.size() == count), 1);
}

//--------- Insert Elements ---------
TEST(ListInsert, PushBack) {
    // Arrange
    const size_t count = 10;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Assert
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
}

TEST(ListInsert, PushFront) {
    // Arrange
    const size_t count = 5;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Assert
    ASSERT_EQ(list.front(), 0u);
    ASSERT_FALSE(list.empty());
}

TEST(ListInsert, PushMiddle) {
    // Arrange
    const size_t count = 6;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    list.push_middle(333);

    for (size_t i = 0; i < count/2; ++i) {
        list.pop_front();
    }

    // Assert
    ASSERT_EQ(list.front(), 333u);
    ASSERT_FALSE(list.empty());
}

//--------- Retrieve Elements ---------
TEST(ListPop, PopBack) {
    // Arrange 
    const size_t count = 10;
    homeworkspace::List<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.pop_back();
    }

    // Assert
    ASSERT_EQ(list.size(), 0u);
    ASSERT_TRUE(list.empty());
}

TEST(ListPop, PopFront) {
    // Arrange
    const size_t count = 10;
    homeworkspace::List<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.pop_front();
    }

    // Assert
    ASSERT_EQ(list.size(), 0u);
    ASSERT_TRUE(list.empty());
}

TEST(ListPop, PopMiddle) {
    // Arrange
    const size_t count_test = 10;
    bool middle_minus_one = 0, middle_plus_one=0;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i=0; i<count_test; i++) {
        list.push_back(i);
    }

    list.pop_middle();

    for (size_t i = 0; i < count_test/2 - 2; ++i) {
        list.pop_front();
    }

    if (list.front() == 3) middle_minus_one = 1;
    list.pop_front();

    if (list.front() == 5) middle_plus_one = 1;

    // Assert
    ASSERT_EQ(middle_minus_one &&  middle_plus_one, 1);
    ASSERT_FALSE(list.empty());
}

TEST(ListPopPush, PopPushComplex1) {
    // Arrange
    const size_t count_test = 10;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i=0; i<count_test; i++) {
        list.push_back(i);
    }

    list.pop_back();
    list.pop_back();
    list.pop_middle();
    list.push_back(111);

    // Assert
    ASSERT_EQ(list.back(), 111u);
}

TEST(ListPopPush, PopPushComplex2) {
    // Arrange
    const size_t count_test = 10;
    homeworkspace::List<size_t> list;

    // Act
    for (size_t i=0; i<count_test; i++) {
        list.push_back(i);
    }

    list.pop_back();
    list.pop_back();
    list.pop_middle();
    list.push_middle(111);

    // Assert
    ASSERT_EQ(list.front(), 0u);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}