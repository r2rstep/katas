#include "table_iterator.hpp"

#include <vector>
#include <gtest/gtest.h>

using namespace testing;

class TestIterator2D
{
public:
    using IT = Iterator2D<int, typename std::vector< std::vector<int> >::iterator, typename std::vector<int>::iterator >;
    
    TestIterator2D()
    {
        std::vector< std::vector<int> > x;
        x.push_back({1, 2, 3});
        x.push_back({4, 5, 6});
        x.push_back({7, 8, 9});
        
        i = IT(x.begin(), x.end());
    }
    
    IT i;
};

TEST_F(TestIterator2D, advance_within_first_dimension)
{
    EXPECT_EQ(1, *i);
    EXPECT_EQ(2, *(i++));
    EXPECT_EQ(3, *(i++));
}

TEST_F(TestIterator2D, advance_to_the_next_dimensions)
{    
    EXPECT_EQ(4, advance(i, 3));
    EXPECT_EQ(7, advance(i, 3));
}
