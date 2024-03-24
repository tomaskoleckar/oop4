#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <cmath>
#pragma once

class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(int n);
    DynamicArray(int *arr, int length);

    int getAt(int i);
    int * getArr();
    int getCount();
    void setAt(int i, int value);

    void repeat(int n, int initValue);
    void range(int start, int end);

    void Add(int number);
    void extendArr();
    void printArr();


    ~DynamicArray();

private:
    static const int defaultSize = 10;
    int *arr;
    int itemCount;
    int arrLen;
};

#endif