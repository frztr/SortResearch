#include "abstractsort.h"
namespace Sorts
{
    template <typename T>
    class ShakeSort : public AbstractSort<T>
    {
        void Exchange(int *array, int left, int right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

    public:
     using AbstractSort<T>::AbstractSort;        string getName() const override
        {
            return "ShakeSort";
        }

        void Sort(int *array, int count) override
        {
            bool x = true;
            int left = 0;
            int right = count - 1;

            while (left < right)
            {
                int i = left;
                int j = right;
                int ExchangeCount = 0;
                if (x)
                {
                    while (j > i)
                    {
                        // if (array[j - 1] < array[j])
                        if(this->condition(array[j-1],array[j]) < 0)
                        {
                            Exchange(array, j - 1, j);
                            ExchangeCount++;
                        }
                        j--;
                    }
                    left++;
                }
                else
                {
                    while (i <= j)
                    {
                        // if (array[i - 1] < array[i])
                        if(this->condition(array[i-1], array[i]) < 0)
                        {
                            Exchange(array, i - 1, i);
                            ExchangeCount++;
                        }
                        i++;
                    }
                    right--;
                }
                x = !x;
                if(ExchangeCount == 0) return;
            }
        }
    };
};