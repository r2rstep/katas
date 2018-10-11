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

template <typename T, typename IT1, typename IT2 = IT1>
class Iterator2D : public std::iterator<std::forward_iterator_tag, T>
{    
public:    
    Iterator2D(const IT1 dim1_begin, const IT1 dim1_end):
        _dim1_begin(dim1_begin), _dim1_it(dim1_begin), _dim1_end(dim1_end), _dim2_it(_dim1_it->begin())
    {}
    
    T& operator*()
    {
        return *_dim2_it;
    }
    
    T& operator->()
    {
        return *_dim2_it;
    }
    
    Iterator2D& operator++()
    {
        _advance_by_1();
        return *this;
    }
    
    Iterator2D& operator++(int)
    {
        _advance_by_1();
        return *this;
    }
    
    void operator=(T x)
    {
        *_dim2_it= x;
    }
    
    bool operator!=(Iterator2D& other)
    {
        return false;
    }
    
    
private:
    
    void _advance_by_1()
    {
        _dim2_it++;
        if (_dim2_it == _dim1_it->end())
        {
            _dim1_it++;
            _dim2_it = _dim1_it->begin();
        }
    }
    
    IT1 _dim1_begin;
    IT1 _dim1_it;
    IT1 _dim1_end;
    IT2 _dim2_it;
};

template <typename T>
class Table
{
public:
    typedef Iterator2D<T, typename vector<vector<T> >::iterator, typename vector<T>::iterator > it;
    
    void push_back(const vector<T>& row)
    {
        mData.push_back(row);
    }
    
    it begin(Direction dir0, Direction dir1)
    {
        // TODO create _begin_it member
        return it(mData.begin(), mData.end());
    }
    
    it end()
    {
        // TODO create _end_it member
        it end_it(mData.begin(), mData.end());
        advance(end_it, mData.size()*mData[0].size());
        return end_it;
    }
    
protected:
    vector<vector<T> > mData;
};
