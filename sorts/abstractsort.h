#include <functional>
#pragma once
using namespace std;
namespace Sorts
{
    template<typename T=int>
    class AbstractSort
    {
    protected:
        int (*condition)(int a, int b){[](int a, int b)
        {
            return a - b;
        }};

    public:
        AbstractSort()
        {
        }
        AbstractSort(int (*condition)(int, int))
        {
            this->condition = condition;
        }
        virtual string getName() const = 0;
        virtual void Sort(int *array, int count) = 0;
    };
};