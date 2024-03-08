#include "abstractsort.h"
namespace Sorts
{
    template <typename T>
    class GnomeSort : public AbstractSort<T>
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
            return "GnomeSort";
        }

        void Sort(int *array, int count)
        {
            int l = count - 1;
            while (l > 0)
            {
                // if(array[l-1]>=array[l])
                if (this->condition(array[l - 1], array[l]) >= 0)
                {
                    l--;
                }
                else
                {
                    Exchange(array, l - 1, l);
                    if (l < count - 1)
                    {
                        l++;
                    }
                }
            }
        }
    };
};