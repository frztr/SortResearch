#include <stdint.h>
#include "abstractsort.h"
#include <vector>
#include <iostream>
namespace Sorts
{
    template <typename T>
    class RadixSortLSD : public AbstractSort<T>
    {
    public:
         using AbstractSort<T>::AbstractSort;        string getName() const override
        {
            return "RadixSort(LSD)";
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

            int size = 1;
            while (max > 9)
            {
                max = max / 10;
                size++;
            }

            for (int i = size; i > 0; i--)
            {
                vector<int> **digits = new vector<int> *[10];
                for (int j = 0; j < 10; j++)
                {
                    digits[j] = new vector<int>();
                }
                int ch = 1;
                for (int k = 0; k < size - i; k++)
                {
                    ch *= 10;
                }
                for (int j = 0; j < count; j++)
                {
                    int number = array[j];
                    number /= ch;
                    number %= 10;
                    digits[number]->push_back(array[j]);
                }

                int index = 0;
                if (this->condition(0, 1) < 0)
                {
                    for (int j = 9; j >= 0; j--)
                    {
                        for (int d : *digits[j])
                        {
                            array[index] = d;
                            index++;
                        }
                    }
                }
                else
                {
                    for (int j = 0; j <= 9; j++)
                    {
                        for (int d : *digits[j])
                        {
                            array[index] = d;
                            index++;
                        }
                    }
                }
            }
        }
    };
};