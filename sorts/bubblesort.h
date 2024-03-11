#include "abstractsort.h"
#pragma once
namespace Sorts
{
    template <typename T>
    class BubbleSort : public AbstractSort<T>
    {
        void Exchange(T *array, int left, int right)
        {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

    public:
        using AbstractSort<T>::AbstractSort;
        string getName() const override
        {
            return "BubbleSort";
        };

        void Sort(T *array, int count) override
        {
            for (int i = 0; i < count; i++)
            {
                int ExchangeCount = 0;
                for (int j = count - 1; j > i; j--)
                {
                    if (this->tester->Test(array[j - 1], array[j]) < 0)
                    {
                        Exchange(array, j - 1, j);
                        ExchangeCount++;
                    }
                }
                if (ExchangeCount == 0)
                    return;
            }
        };
    };
};