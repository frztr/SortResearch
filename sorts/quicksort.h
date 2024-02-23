#include "abstractsort.h"
namespace Sorts{
    class QuickSort:public AbstractSort
    {
        void Exchange(int *array, int left, int right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

        void QuickSortIteration(int *array, int left, int right)
        {
            int i = left;
            int j = right;
            bool ij = false;
            while (i < j)
            {

                if (!ij)
                {
                    if (array[i] >= array[j])
                    {
                        j--;
                    }
                    else
                    {
                        Exchange(array, i, j);
                    }
                }
                else
                {
                    if (array[j] <= array[i])
                    {
                        i++;
                    }
                    else
                    {
                        Exchange(array, i, j);
                    }
                }
            }
            if(i-1>left){
                QuickSortIteration(array,left,i-1);
            }
            if(j+1<right){
                QuickSortIteration(array,j+1,right);
            }
        }

    public:
        std::string getName() const override
        {
            return "QuickSort";
        }

        void Sort(int *array, int count) override
        {
            QuickSortIteration(array, 0, count - 1);
        }
    };
};