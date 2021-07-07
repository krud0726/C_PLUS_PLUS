
#include "iostream"
#include "gtest/gtest.h"
#include "libmatrix/matrix.h"


class MatrixFixture : public testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
};

void MatrixFixture::SetUp() {
    std::cout << "--------------Test Started---------------"<<std::endl;
}

void MatrixFixture::TearDown() {
    std::cout << "--------------Test Finished--------------"<<std::endl << std::endl;
}

TEST_F(MatrixFixture, test1) {
    matrix m1 = {{1, 2}, {3, 4}};
    matrix m2 = {{5, 6}, {7, 8}};

    matrix m3(m1+m2);

    EXPECT_EQ(m3[0][0], 6);
    EXPECT_EQ(m3[1][1], 12);

    matrix m4;
    m4 = m3;

    std::cout << m4 << std::endl;
    std::cout << m4.size().first << " " << m4.size().second << "\n";

    EXPECT_EQ(m4.size().first, 2);
    EXPECT_EQ(m4.size().second, 2);
}


TEST_F(MatrixFixture, test2) {
    //테스트 케이스#2 를 작성하시오
    matrix m = {{1,1}, {1,1}} , n ={{2,2}, {2,2}};

    m = n;

    assert(m==n);
    EXPECT_EQ(1, (m==n));

    n = {{3,3}, {3,3}};
    assert(!(m==n));
    EXPECT_EQ(1, !(m==n));

    std::cout << m << std::endl;
    std::cout << n << std::endl;
}

TEST_F(MatrixFixture, test3) {
    //테스트 케이스#3 를 작성하시오
    matrix m11 = {{1,2}, {3,4}};
    matrix m22 = {{5,6}, {7,8}};

    std::cout << m11.transpose() << '\n';
    EXPECT_EQ(2, m11.transpose()[1][0]);
    EXPECT_EQ(3, m11.transpose()[0][1]);

    std::cout << m22.transpose() << '\n';
    EXPECT_EQ(6, m22.transpose()[1][0]);
    EXPECT_EQ(7, m22.transpose()[0][1]);
}
