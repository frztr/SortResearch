#include <stdint.h>
#include "abstractsort.h"
#include <iostream>
namespace Sorts
{
    class CountingSort: public AbstractSort
    {
        public:
        string getName() const override
        {
            return "CountingSort";
        }

        void Sort(int* array, int count) override
        {
            int min = INT32_MAX;
            int max = INT32_MIN;

            for(int i = 0;i< count;i++)
            {
                if(array[i]< min)
                {
                    min = array[i];
                }
                if(array[i]>max)
                {
                    max = array[i];
                }
            }
            int* map = new int[max-min+1]{0};

            for(int i = 0;i< count;i++)
            {
                map[array[i]-min]++;
            }
            int index = 0;

            for(int i = max-min;i>= 0;i--)
            {
                for(int j = 0;j<map[i];j++)
                {
                    array[index] = i+min;
                    index++;
                }
            }

            delete[] map;
        }
    };
};