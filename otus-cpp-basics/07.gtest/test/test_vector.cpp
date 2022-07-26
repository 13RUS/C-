//
// Created by Aleksey Leshchankin on 22.06.2022.
//

#include "vector.hpp"

#include <gtest/gtest.h>

//--------- Basic Checks ---------
TEST(VectorBasic, Empty) {
    // Arrange
    homeworkspace::Vector<size_t> vector;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(int(vector.size()), 0);
}

TEST(VectorBasic, Size) {
    // Arrange
    const int count = 10;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Assert
    //ASSERT_EQ(vector.size(), count);
    ASSERT_TRUE(vector.size() == count);
    }

//--------- Insert Elements ---------
TEST(VectorInsert, PushBack) {
    // Arrange
    const size_t count = 10;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Assert
    for (unsigned i = 0; i < count; ++i) {
        EXPECT_EQ(vector[i],  i);
    }
}

TEST(VectorInsert, PushFront) {
    // Arrange
    const size_t count = 5;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vector.push_front(i);
    }

    vector.push_front(333);

    // Assert
    ASSERT_EQ(vector.front(), 333u);
    ASSERT_FALSE(vector.empty());
}

TEST(VectorInsert, PushMiddle) {
    // Arrange
    const size_t count = 6;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    vector.push_middle(333);

    for (size_t i = 0; i < count/2; ++i) {
        vector.pop_front();
    }

    // Assert
    ASSERT_EQ(vector.front(), 333u);
    ASSERT_FALSE(vector.empty());
}

//--------- Retrieve Elements ---------
TEST(VectorPop, PopBack) {
    // Arrange
    const size_t count = 10;
    homeworkspace::Vector<size_t> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count-2; ++i) {
        vector.pop_back();
    }

    // Assert
    ASSERT_EQ(vector.back(), 1u);
}

TEST(VectorPop, PopFront) {
    // Arrange
    const size_t count = 10;
    homeworkspace::Vector<size_t> vector;

    for (size_t i = 0; i < count; ++i) {
        vector.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count-2; ++i) {
        vector.pop_front();
    }

    // Assert
    ASSERT_EQ(vector.front(), 8u);
}


TEST(VectorPop, PopMiddle) {
    // Arrange
    const size_t count_test = 10;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i=0; i<count_test; i++) {
        vector.push_back(i);
    }

    vector.pop_middle();

    for (size_t i = 0; i + 2 < count_test/2; ++i) {
        vector.pop_front();
    }

    // Assert
    EXPECT_EQ(vector.front(), 3u);
    vector.pop_front();
    EXPECT_EQ(vector.front(), 5u);

}

TEST(VectorPopPush, PopPushComplex1) {
    // Arrange
    const size_t count_test = 10;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i=0; i<count_test; i++) {
        vector.push_back(i);
    }

    vector.pop_back();
    vector.pop_back();
    vector.pop_middle();
    vector.push_back(111);

    // Assert
    ASSERT_EQ(vector.back(), 111u);
}

TEST(VectorPopPush, PopPushComplex2) {
    // Arrange
    const size_t count_test = 10;
    homeworkspace::Vector<size_t> vector;

    // Act
    for (size_t i=0; i<count_test; i++) {
        vector.push_back(i);
    }

    vector.pop_back();
    vector.pop_back();
    vector.pop_middle();
    vector.push_middle(111);

    // Assert
    ASSERT_EQ(vector.front(), 0u);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}