#pragma once

#include <vector>
#include <iterator>

using namespace std;

enum Direction {
    DirectionNone,
    DirectionUp,
    DirectionLeft,
    DirectionDown,
    DirectionRight
};

template <typename T, typename IT>
class Iterator2D : public std::iterator<std::forward_iterator_tag, T>
{    
public:    
    Iterator2D(T* p):
        ptr(p)
    {}
    
    T& operator*()
    {
        return *ptr;
    }
    
    T& operator->()
    {
        return *ptr;
    }
    
    Iterator2D& operator++()
    {
        ++ptr;
        return *this;
    }
    
    Iterator2D& operator++(int)
    {
        ptr++;
        return *this;
    }
    
    void operator=(T x)
    {
        *ptr = x;
    }
    
    bool operator!=(Iterator2D& other)
    {
        return false;
    }
    
    
private:
    T* ptr;
};

template <typename T>
class Table
{
public:
    typedef Iterator2D<vector<T>> it;
    
    void push_back(const vector<T>& row)
    {
        mData.push_back(row);
    }
    
    it begin(Direction dir0, Direction dir1)
    {
        return it(mData.data()->data());
    }
    
    it end()
    {
        return it(mData.data()->data());
    }
    
protected:
    vector<vector<T> > mData;
};
