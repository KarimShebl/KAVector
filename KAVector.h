//
// Created by KA003 on 12/9/2022.
//

#ifndef KAVECTOR_KAVECTOR_H
#define KAVECTOR_KAVECTOR_H
#include<iostream>
using namespace std;

template<typename T>
class KAVector{
private:
    T* arr;
    int size_, capacity_;
public:
    typedef T* iterator;

    KAVector();//Done, tested
    KAVector(int);//Done, tested
    KAVector(const KAVector&);//Done, tested
    KAVector(const KAVector&&);//Done, tested
    ~KAVector();//Done, tested
    KAVector &operator=(const KAVector&);//Done
    KAVector &operator=(const KAVector&&);//Done
    T& operator[](int);//Done, tested
    int push_back(T);//Done, tested
    T pop_back();// Done, tested
    void erase(iterator);//Done, tested
    void erase(iterator, iterator);//Done, tested
    void clear();//Done, tested
    void insert(iterator, T);//Done, tested
    iterator begin();//Done, tested
    iterator end();//Done, tested
    bool operator==(const KAVector<T>&);//Done, tested
    bool operator<(const KAVector<T>&);//Done, tested
    bool operator>(const KAVector<T>&);//Done, tested
    int size() const;//Done, tested
    int capacity() const;//Done, tested
    void resize(int);//Done, tested;
    bool empty();//Done, tested
    template<typename x>
    friend ostream& operator<<(ostream&, KAVector<x>);
};


#endif //KAVECTOR_KAVECTOR_H
