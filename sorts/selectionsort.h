#include "abstractsort.h"
namespace Sorts
{
    template <typename T>
    class SelectionSort : public AbstractSort<T>
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
            return "SelectionSort";
        }

        void Sort(T *array, int count) override
        {
            for (int i = 0; i < count; i++)
            {
                int min_index = i;
                for (int j = i; j < count; j++)
                {
                    if (this->tester->Test(array[j], array[min_index]) > 0)
                    {
                        min_index = j;
                    }
                }
                Exchange(array, i, min_index);
            }
        }
    };
};
