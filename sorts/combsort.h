#include "abstractsort.h"
#include "bubblesort.h"
#include <iostream>
namespace Sorts
{
    template <typename T>
    class CombSort : public AbstractSort<T>
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
            return "CombSort";
        }

        void Sort(T *array, int count) override
        {
            const double factor = 1.247;
            double step = count - 1;

            int i = 0;
            while (step >= 1)
            {
                for (int j = count - 1; j - int(step) > i; j--)
                {
                    if (this->tester->Test(array[j - int(step)],array[j]))
                    {
                        Exchange(array, j - int(step), j);
                    }
                }
                i++;
                step /= factor;
            }
            BubbleSort<T> sort = BubbleSort<T>(this->tester->Test);
            sort.Sort(array, count);
        }
    };
};