//
// Created by KA003 on 12/9/2022.
//

#include "KAVector.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
KAVector<T>::KAVector()
{
    size_ = 0;
    capacity_ = 0;
    arr = 0;
}

template<typename T>
KAVector<T>::KAVector(int size)
{
    size_ = size;
    capacity_ = size;
    arr = new T[size];
}

template<typename T>
KAVector<T>::KAVector(const KAVector<T>& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr = new T[size_];
    for (int i = 0; i < size_; ++i) {
        arr[i] = other.arr[i];
    }
}

template<typename T>
KAVector<T>::KAVector(const KAVector<T>&& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr = other.arr;
    other.arr = nullptr;
}
template<typename T>
KAVector<T>&KAVector<T>::operator=(const KAVector<T>& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr = new T[size_];
    for (int i = 0; i < size_; ++i) {
        arr[i] = other.arr[i];
    }
}
template<typename T>
KAVector<T>&KAVector<T>::operator=(const KAVector<T>&& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr = other.arr;
    other.arr = nullptr;
}

template<typename T>
KAVector<T>::~KAVector()
{
    delete[] arr;
    arr = nullptr;
}

template<typename T>
T& KAVector<T>::operator[](int x)
{
    if(x < 0 || x >= size_)
        throw "Out Of Range";

    return arr[x];
}

template<typename T>
int KAVector<T>::push_back(T item)
{
    if(size_ >= capacity_)
    {
        capacity_ += 5;
        T * newArr = new T[capacity_];
        copy(arr, arr + size_, newArr);
        delete[] arr;
        arr = newArr;
        newArr = nullptr;
    }
    arr[size_++] = item;
    return size_;
}

template<typename T>
T KAVector<T>::pop_back()
{
    size_--;
    return arr[size_];
}

template<typename T>
int KAVector<T>::size() const
{
    return size_;
}

template<typename T>
int KAVector<T>::capacity() const
{
    return capacity_;
}

template<typename T>
void KAVector<T>::resize(int newSize)
{
    if(newSize >= capacity_)
    {
        capacity_ = newSize + 5;
    }
    T * newArr = new T[capacity_];
    copy(arr, arr + size_, newArr);
    size_ = newSize;
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
}

template<typename T>
bool KAVector<T>::empty() {
    return size_ == 0;
}

template<typename T>
void KAVector<T>::erase(iterator it)
{
    bool found = false;
    for (int i = 0; i < size_; ++i) {
        if(it == &arr[i])
        {
            found = true;
            for (int j = i; j < size_ - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            size_--;
            break;
        }
    }
    if(!found)
        throw "Invalid Iterator";
}
template<typename T>
void KAVector<T>::erase(iterator it1, iterator it2)
{
    int start = -1, end = -1;
    for (int i = 0; i < size_; ++i) {
        if(it1 == &arr[i])
        {
            start = i;
        }
        if(it2 == &arr[i])
        {
            end = i;
        }
    }

    if(start == - 1 || end == - 1)
        throw "Invalid Iterator Range";

    for (int i = end; i < size_; ++i) {
        arr[start++] = arr[i];
    }
    size_ -= (it2 - it1);
}
template<typename T>
void KAVector<T> :: clear()
{
    size_ = 0;
    capacity_ = 0;
    delete [] arr;
    arr = nullptr;
}

template<typename T>
void KAVector<T> ::insert(iterator it, T item)
{
    int ind = it - arr;
    if(ind < 0 || ind >= size_)
        throw "Invalid Iterator";

    if(size_ >= capacity_)
    {
        capacity_ += 5;
        T * newArr = new T[capacity_];
        copy(arr, arr + size_, newArr);
        delete[] arr;
        arr = newArr;
        newArr = nullptr;
    }
    for (int i = size_ + 1; i > ind; --i) {
        arr[i] = arr[i - 1];
    }
    arr[ind] = item;
    size_++;
}

template<typename T>
T* KAVector<T>::begin()
{
    return arr;
}

template<typename T>
T* KAVector<T>::end()
{
    return arr + size_;
}

template<typename T>
bool KAVector<T>::operator==(const KAVector<T>& other)
{
    if(size_ == other.size_)
    {
        for (int i = 0; i < size_; ++i) {
            if(arr[i] != other.arr[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

template<typename T>
bool KAVector<T>::operator<(const KAVector<T>& other)
{
    for (int i = 0; i < min(size_, other.size_); ++i) {
        if(arr[i] < other.arr[i])
        {
            return true;
        }
        else if(arr[i] > other.arr[i])
        {
            return false;
        }
    }
    return false;
}

template<typename T>
bool KAVector<T>::operator>(const KAVector<T>& other)
{
    for (int i = 0; i < min(size_, other.size_); ++i) {
        if(arr[i] > other.arr[i])
        {
            return true;
        }
        else if(arr[i] < other.arr[i])
        {
            return false;
        }
    }
    return false;
}

template<typename T>
ostream& operator<<(ostream& out, KAVector<T> v)
{
    for (int i = 0; i < v.size_; ++i) {
        out << v[i] << " ";
    }
    return out;
}





















