#include <stdint.h>
#include "abstractsort.h"
#include <iostream>
#include <map>
#include <functional>
#include <unordered_map>
#include <string_view>

using namespace std;
namespace Sorts
{
    template <typename T>
    class CountingSort : public AbstractSort<T>
    {
        class string_comparator
        {
        public:
            bool operator()(string_view a, string_view b) const
            {
                string str = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789";
                map<char, int> alphabet;
                for (int i = 0; i < str.length(); i++)
                {
                    alphabet[str[i]] = i;
                }

                for (int i = 0; i < a.length() && i < b.length(); i++)
                {
                    if (alphabet[a[i]] < alphabet[b[i]])
                        return 1;
                    if (alphabet[b[i]] < alphabet[a[i]])
                        return 0;
                }
                if (a.length() < b.length())
                {
                    return 1;
                }
                if (a.length() > b.length())
                {
                    return 0;
                }
                return 0;
            }
        };

        void SortString(string *array, int count)
        {
            map<string, int, string_comparator> _map;
            for (int i = 0; i < count; i++)
            {
                _map[array[i]]++;
            }
            int index = 0;

            for (auto iter = --_map.end(); iter != --_map.begin(); iter--)
            {
                for (int j = 0; j < iter->second; j++)
                {
                    array[index] = iter->first;
                    index++;
                }
            }
        }

        void SortDouble(double *array, int count)
        {
            double min = array[0];
            double max = array[0];

            for (int i = 1; i < count; i++)
            {
                if (array[i] < min)
                {
                    min = array[i];
                }
                if (array[i] > max)
                {
                    max = array[i];
                }
            }

            map<double, int> _map;
            for (int i = 0; i < count; i++)
            {
                _map[array[i] - min]++;
            }
            int index = 0;

            for (auto iter = --_map.end(); iter != --_map.begin(); iter--)
            {
                for (int j = 0; j < iter->second; j++)
                {
                    array[index] = iter->first + min;
                    index++;
                }
            }
        }

        void SortInt(int *array, int count)
        {
            int min = array[0];
            int max = array[0];

            for (int i = 1; i < count; i++)
            {
                if (array[i] < min)
                {
                    min = array[i];
                }
                if (array[i] > max)
                {
                    max = array[i];
                }
            }
            int *map = new int[max - min + 1]{0};

            for (int i = 0; i < count; i++)
            {
                map[array[i] - min]++;
            }
            int index = 0;

            for (int i = max - min; i >= 0; i--)
            {
                for (int j = 0; j < map[i]; j++)
                {
                    array[index] = i + min;
                    index++;
                }
            }

            delete[] map;
        }

    public:
        using AbstractSort<T>::AbstractSort;
        string getName() const override
        {
            return "CountingSort";
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