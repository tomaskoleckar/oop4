#include "DynamicArray.h"


int main()
{
    DynamicArray * a1 = new DynamicArray();

    a1->repeat(10,10);
    a1->printArr();

    DynamicArray * a2 = new DynamicArray(5);

    a2->range(15,-15);
    a2->printArr();

    DynamicArray * a3 = new DynamicArray(a1->getArr(),10);

    a3->Add(1);
    a3->printArr();

    std::cout << a3->getAt(10) << std::endl;

    return 0;
}
