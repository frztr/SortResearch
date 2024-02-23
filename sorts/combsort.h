#include "abstractsort.h"
#include "bubblesort.h"
#include <iostream>
namespace Sorts
{
    class CombSort : public AbstractSort
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
            return "CombSort";
        }

        void Sort(int *array, int count) override
        {
            const double factor = 1.247;
            double step = count - 1;

            int i = 0;
            while (step >= 1)
            {
                for (int j = count - 1; j - int(step) > i; j--)
                {
                    if (array[j - int(step)] < array[j])
                    {
                        Exchange(array, j - int(step), j);
                    }
                }
                i++;
                step /= factor;
            }

            BubbleSort sort = BubbleSort();
            sort.Sort(array, count);
        }
    };
};