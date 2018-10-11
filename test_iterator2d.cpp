#include "table_iterator.hpp"

#include <vector>
#include <gtest/gtest.h>

class TestIterator2D : public ::testing::Test
{
public:
    using IT = Iterator2D<int, typename std::vector< std::vector<int> >::iterator, typename std::vector<int>::iterator >;
    
    TestIterator2D()
    {
        x.push_back({1, 2, 3});
        x.push_back({4, 5, 6});
        x.push_back({7, 8, 9});
    }
    
    std::vector< std::vector<int> > x;
};

TEST_F(TestIterator2D, advance_within_first_dimension)
{
    IT i = IT(x.begin(), x.end());
    
    EXPECT_EQ(1, *i);
    EXPECT_EQ(2, *(i++));
    EXPECT_EQ(3, *(i++));
}

TEST_F(TestIterator2D, advance_to_the_next_dimensions)
{    
    IT i = IT(x.begin(), x.end());
    advance(i, 3);
    EXPECT_EQ(4, *i);
    advance(i, 2);
    EXPECT_EQ(6, *i);
    advance(i, 3);
    EXPECT_EQ(9, *i);
}
