#include <iostream>
#include "abstractsort.h"

using namespace std;
namespace Sorts
{
    template <typename T>
    class HeapSort : public AbstractSort<T>
    {
        void Exchange(T *array, int left, int right)
        {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

        void Heapify(T *array, int count, int index)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int min = index;
            if (left < count && this->tester->Test(array[left], array[min])<0)
            {
                min = left;
            }
            if (right < count && this->tester->Test(array[right], array[min])<0)
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
     using AbstractSort<T>::AbstractSort;        
     string getName() const override
        {
            return "HeapSort";
        }

        void Sort(T *array, int count) override
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