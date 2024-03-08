#include <stdint.h>
#include "abstractsort.h"
#include <vector>
#include <iostream>
namespace Sorts
{
    template <typename T>
    class RadixSortMSD : public AbstractSort<T>
    {
        void SortMiniArray(int *basearray, int left, int right, int digitcount, int maxSize)
        {
            vector<int> **digits = new vector<int> *[10];
            for (int j = 0; j < 10; j++)
            {
                digits[j] = new vector<int>();
            }

            int ch = 1;
            for (int k = 0; k < maxSize - digitcount; k++)
            {
                ch *= 10;
            }

            for (int j = left; j < right; j++)
            {
                int number = basearray[j];
                number /= ch;
                number %= 10;
                digits[number]->push_back(basearray[j]);
            }

            int index = left;
            if (this->condition(0, 1) < 0)
            {
                for (int j = 9; j >= 0; j--)
                {
                    int _l = index;
                    for (int d : *digits[j])
                    {
                        basearray[index] = d;
                        index++;
                    }
                    if (digitcount + 1 <= maxSize)
                    {
                        SortMiniArray(basearray, _l, index, digitcount + 1, maxSize);
                    }
                }
            }
            else
            {
                for (int j = 0; j <= 9; j++)
                {
                    int _l = index;
                    for (int d : *digits[j])
                    {
                        basearray[index] = d;
                        index++;
                    }
                    if (digitcount + 1 <= maxSize)
                    {
                        SortMiniArray(basearray, _l, index, digitcount + 1, maxSize);
                    }
                }
            }
        }

    public:
         using AbstractSort<T>::AbstractSort;        string getName() const override
        {
            return "RadixSort(MSD)";
        }

        void Sort(int *array, int count) override
        {
            int max = INT32_MIN;
            for (int i = 0; i < count; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                }
            }

            int maxSize = 1;
            while (max > 9)
            {
                max = max / 10;
                maxSize++;
            }

            SortMiniArray(array, 0, count, 1, maxSize);
        }
    };
};