#include <stdint.h>
#include "abstractsort.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <unordered_map>
namespace Sorts
{
    template <typename T>
    class RadixSortMSD : public AbstractSort<T>
    {
        void SortMiniArray(string *basearray, int left, int right, int digitcount, int maxSize)
        {
            if (left < right)
            {
                string str = "9876543210zZyYxXwWvVuUtTsSrRqQpPoOnNmMlLkKjJiIhHgGfFeEdDcCbBaA";
                unordered_map<int, vector<string>> digits;
                vector<string> emp;
                for (int j = 0; j < str.length(); j++)
                {
                    int index = str[j];
                    vector<string> v;
                    digits[index] = v;
                }

                for (int j = left; j < right; j++)
                {
                    if (basearray[j].length() > digitcount)
                    {
                        int x = basearray[j][digitcount];
                        (digits[x]).push_back(basearray[j]);
                    }
                    else
                    {
                        emp.push_back(basearray[j]);
                    }
                }

                int index = left;
                int _l = index;
                for (string d : emp)
                {
                    basearray[index] = d;
                    index++;
                }

                for (int j = str.length(); j >= 0; j--)
                {
                    int _l = index;

                    for (string d : digits[str[j]])
                    {
                        basearray[index] = d;
                        index++;
                    }
                    if (digitcount + 1 < maxSize)
                    {
                        SortMiniArray(basearray, _l, index, digitcount + 1, maxSize);
                    }
                }
            }
        }

        void SortMiniArray(int *basearray, int left, int right, int digitcount, int maxSize)
        {
            if (left < right)
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
        }

        void SortMiniArray(double *basearray, int left, int right, int digitcount, int maxSize)
        {
            if (left < right)
            {
                vector<double> **digits = new vector<double> *[10];
                for (int j = 0; j < 10; j++)
                {
                    digits[j] = new vector<double>();
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
                for (int j = 9; j >= 0; j--)
                {
                    int _l = index;
                    for (double d : *digits[j])
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

        void SortInt(int *array, int count)
        {
            int max = array[0];
            for (int i = 1; i < count; i++)
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

        void SortDouble(double *array, int count)
        {
            long mult = 1000000;
            double max = array[0] * mult;
            for (int i = 1; i < count; i++)
            {
                array[i] *= mult;
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

            for (int i = 1; i < count; i++)
            {
                array[i] /= mult;
            }
        }

        void SortString(string *array, int count)
        {
            int max = array[0].length();
            for (int i = 1; i < count; i++)
            {
                if (array[i].length() > max)
                {
                    max = array[i].length();
                }
            }

            SortMiniArray(array, 0, count, 0, max);
        }

    public:
        using AbstractSort<T>::AbstractSort;
        string getName() const override
        {
            return "RadixSort(MSD)";
        }

        void Sort(T *array, int count) override
        {
            if (typeid(T) == typeid(string))
            {
                SortString((string *)array, count);
            }

            if (typeid(T) == typeid(int))
            {
                SortInt((int *)array, count);
            }

            if (typeid(T) == typeid(double))
            {
                SortDouble((double *)array, count);
            }
        }
    };
};