#include "abstractsort.h"
namespace Sorts
{
    template <typename T>
    class ShellSort : public AbstractSort<T>
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
            return "ShellSort";
        }

        void Sort(T *array, int count) override
        {
            int gap = count / 2;
            while (gap > 0)
            {
                for (int i = gap; i < count; i++)
                {
                    int j = i - gap;
                    bool cond = true;
                    while (this->tester->Test(array[j], array[j + gap]) < 0 && cond)
                    {
                        Exchange(array, j, j + gap);
                        if (j >= gap)
                        {
                            j = j - gap;
                        }
                        else
                        {
                            cond = false;
                        }
                    }
                }
                gap = gap / 2;
            }
        }
    };
};