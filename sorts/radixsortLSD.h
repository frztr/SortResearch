#include <stdint.h>
#include "abstractsort.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <string.h>
#include <unordered_map>

using namespace std;

namespace Sorts
{
    template <typename T>
    class RadixSortLSD : public AbstractSort<T>
    {

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
                for (int j = 9; j >= 0; j--)
                {
                    for (int d : *digits[j])
                    {
                        array[index] = d;
                        index++;
                    }
                }
            }
        }

        void SortDouble(double *array, int count)
        {
            const double mult = pow(10.0, 8.0);
            double max = array[0] * mult;
            for (int i = 1; i < count; i++)
            {
                array[i] = array[i] * mult;
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
                vector<double> **digits = new vector<double> *[10];
                for (int j = 0; j < 10; j++)
                {
                    digits[j] = new vector<double>();
                }
                long long ch = pow(10, size - i);
                for (int j = 0; j < count; j++)
                {
                    double number = array[j];
                    number /= ch;
                    long long num = number;
                    num %= 10;
                    digits[num]->push_back(array[j]);
                }

                int index = 0;
                for (int j = 9; j >= 0; j--)
                {
                    for (double d : *digits[j])
                    {
                        array[index] = d;
                        index++;
                    }
                }
            }
            for (int i = 0; i < count; i++)
            {
                array[i] /= mult;
            }
        }

        void SortString(string *array, int count)
        {
            string str = "9876543210zZyYxXwWvVuUtTsSrRqQpPoOnNmMlLkKjJiIhHgGfFeEdDcCbBaA";
            int max = array[0].length();
            for (int i = 1; i < count; i++)
            {
                if (array[i].length() > max)
                {
                    max = array[i].length();
                }
            }

            for (int i = max - 1; i >= 0; i--)
            {
                unordered_map<int, vector<string>> digits;
                vector<string> emp;
                for (int j = 0; j < str.length(); j++)
                {
                    int index = str[j];
                    vector<string> v;
                    digits[index] = v;
                }

                for (int j = 0; j < count; j++)
                {
                    if (array[j].length() > i)
                    {
                        int x = array[j][i];
                        (digits[x]).push_back(array[j]);
                    }
                    else
                    {
                        emp.push_back(array[j]);
                    }
                }

                int index = 0;
                for (string d : emp)
                {
                    array[index] = d;
                    index++;
                }
                for (int j = str.length(); j >= 0; j--)
                {
                    for (string d : digits[str[j]])
                    {
                        array[index] = d;
                        index++;
                    }
                }
            }
        }

    public:
        using AbstractSort<T>::AbstractSort;
        string getName() const override
        {
            return "RadixSort(LSD)";
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