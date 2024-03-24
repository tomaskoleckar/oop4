#include "DynamicArray.h"
using namespace std;
DynamicArray::DynamicArray()
{
    this->arr = new int[this->defaultSize];
}

DynamicArray::DynamicArray(int n)
{
    this->arr = new int[n];
}

DynamicArray::DynamicArray(int *arr, int length)
{
    this->arrLen = length*2;
    this->arr = new int[length*2];
    this->itemCount = length;

    for(int i = 0;i < length;i++){
        this->arr[i] = arr[i];
    }

}

int DynamicArray::getAt(int i)
{
    if(this->itemCount > i){
       return this->arr[i]; 
    }
    std::cout << "Wrong index !" << std::endl;
    return 0;
}

int *DynamicArray::getArr()
{
    return this->arr;
}

int DynamicArray::getCount()
{
    return this->itemCount;
}

void DynamicArray::setAt(int i, int value)
{
    while(this->arrLen < i){
        this->arrLen *= 2;
        if(this->arrLen > i){
            this->extendArr();
            this->itemCount++;
        }
    }

    this->arr[i] = value;
}

void DynamicArray::repeat(int n, int initValue)
{
    delete[] this->arr;
    this->arrLen = n;
    this->itemCount = n;
    this->arr = new int[this->arrLen];
    for(int i = 0;i<n;i++){
        this->arr[i] = initValue;
    }
}

void DynamicArray::range(int start, int end)
{
    delete[] this->arr;
    if(start == end){
        this->arr = new int[1];
        return;
    }

    this->arrLen = abs(start) + abs(end);

    this->arr = new int[this->arrLen];

    int startNum = start > end ? end:start;

    for(int i = 0;i<this->arrLen;i++){
        this->arr[i] = startNum + i;
        this->itemCount++;
    }




}

void DynamicArray::Add(int number)
{
    if (this->itemCount >= this->arrLen) {
        int newLen = this->arrLen * 2;
        int* newArray = new int[newLen];

        for (int i = 0; i < this->itemCount; ++i) {
            newArray[i] = this->arr[i];
        }
        
        newArray[this->itemCount] = number;
        this->itemCount++;

        delete[] this->arr;
        
        this->arrLen = newLen;
        this->arr = newArray;
    } else {
        this->arr[this->itemCount] = number;
        this->itemCount++;
    }
}

void DynamicArray::extendArr()
{
    int * newArr = new int[this->arrLen];
    for (int j = 0; j < this->itemCount; j++) {
        newArr[j] = this->arr[j];
    }
    delete this->arr;
    this->arr = newArr;
}

void DynamicArray::printArr()
{
    for (int i = 0; i < this->getCount(); i++) {
        cout << this->getAt(i) << " ";
    }
    cout << endl;
    return;
}

DynamicArray::~DynamicArray()
{

}