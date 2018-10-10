#include "table_iterator.hpp"

#include <gtest/gtest.h>

using namespace std;

// TEST(table_iterator, sample_read_test)
// {
//     Table<int> t;
//     t.push_back({5, 6, 7, 8, 9});
//     t.push_back({10, 11, 12, 13, 14});
//     t.push_back({15, 16, 17, 18, 19});
//     t.push_back({20, 21, 22, 23, 24});
//     
//     vector<int> t4,t5;
//     
//     // bottom left corner -> top right corner
//     // row by row
//     copy(t.begin(DirectionRight,DirectionUp),t.end(),back_inserter(t4));
//     vector<int> t4e = { 20, 21, 22, 23, 24, 15, 16, 17, 18, 19, 10, 11, 12, 13, 14, 5, 6, 7, 8, 9};
//     EXPECT_EQ(t4e, t4);
//     
//     // column by column
//     copy(t.begin(DirectionUp,DirectionRight),t.end(),back_inserter(t5));
//     vector<int> t5e = { 20, 15, 10, 5, 21, 16, 11, 6, 22, 17, 12, 7, 23, 18, 13, 8, 24, 19, 14, 9};
//     EXPECT_EQ(t5e, t5);
// }
// 
// TEST(table_iterator, sample_write_test)
// {
//     Table<int> t;
//     t.push_back({5, 6, 7, 8, 9});
//     t.push_back({10, 11, 12, 13, 14});
//     t.push_back({15, 16, 17, 18, 19});
//     t.push_back({20, 21, 22, 23, 24});
//     
//     vector<int> t4,t5;
//     
//     auto it = t.begin(DirectionUp,DirectionLeft);
//     advance(it,9);
//     *it = 100;
//     
//     // bottom left corner -> top right corner
//     // row by row
//     copy(t.begin(DirectionRight,DirectionUp),t.end(),back_inserter(t4));
//     vector<int> t4e = { 20, 21, 22, 23, 24, 15, 16, 100, 18, 19, 10, 11, 12, 13, 14, 5, 6, 7, 8, 9};
//     EXPECT_EQ(t4e, t4);
//     
//     // column by column
//     copy(t.begin(DirectionUp,DirectionRight),t.end(),back_inserter(t5));
//     vector<int> t5e = { 20, 15, 10, 5, 21, 16, 11, 6, 22, 100, 12, 7, 23, 18, 13, 8, 24, 19, 14, 9};
//     EXPECT_EQ(t5e, t5);
// }
