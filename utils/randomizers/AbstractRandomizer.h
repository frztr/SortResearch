#include <cstdlib>
#pragma once
namespace RandomDigits
{
    template<typename T=int>
    class AbstractRandomizer
    {

    public:
        virtual  T *generateOrderedArray(int count) = 0;

        virtual  T *generateReversedArray(int count) = 0;

        virtual  T *generateDegenerateArray(int count) = 0;

        virtual  T *generateRandomArray(int count) = 0;
    };
}