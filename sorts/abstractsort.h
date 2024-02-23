#include <string>
#pragma once
using namespace std;
namespace Sorts
{
    class AbstractSort
    {

    public:
        virtual string getName() const = 0;
        virtual void Sort(int* array, int count) = 0;
    };
};