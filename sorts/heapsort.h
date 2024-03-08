#include <iostream>
#include "abstractsort.h"

using namespace std;
namespace Sorts
{
    template <typename T>
    class HeapSort : public AbstractSort<T>
    {
        void Exchange(int *array, int left, int right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

        void Heapify(int *array, int count, int index)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int min = index;
            // if (left < count && array[left] < array[min])
            if (left < count && this->condition(array[left], array[min])<0)
            {
                min = left;
            }
            // if (right < count && array[right] < array[min])
            if (right < count && this->condition(array[right], array[min])<0)
            {
                min = right;
            }

            if (min != index)
            {
                Exchange(array, index, min);
                Heapify(array, count, min);
            }
        }

    public:
     using AbstractSort<T>::AbstractSort;        string getName() const override
        {
            return "HeapSort";
        }

        void Sort(int *array, int count) override
        {
            int h_size = count;
            for (int i = count / 2; i >= 0; i--)
            {
                Heapify(array, count, i);
            }

            for (int i = count - 1; i > 0; i--)
            {
                Exchange(array, 0, i);
                h_size--;
                Heapify(array, h_size, 0);
            }
        }
    };
};