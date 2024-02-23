#include "abstractsort.h"
#pragma once
namespace Sorts
{
    class BubbleSort : public AbstractSort
    {
        void Exchange(int *array, int left, int right) 
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

    public:
        string getName() const override
        {
            return "BubbleSort";
        };

        void Sort(int *array, int count) override
        {
            for (int i = 0; i < count; i++)
            {
                int ExchangeCount = 0;
                for (int j = count - 1; j > i; j--)
                {
                    if (array[j - 1] < array[j])
                    {
                        Exchange(array, j - 1, j);
                        ExchangeCount++;
                    }
                }
                if(ExchangeCount == 0) return;
            }
        };
    };
};