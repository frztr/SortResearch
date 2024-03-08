#include "abstractsort.h"
#include <iostream>

using namespace std;
namespace Sorts
{
    template <typename T>
    class MergeSort : public AbstractSort<T>
    {
        void SortPart(int *array, int left, int right)
        {
            int middle = ((right - left) / 2) + left;
            if (middle - left > 1)
            {
                SortPart(array, left, middle);
            }
            if (right - middle > 1)
            {
                SortPart(array, middle, right);
            }

            int a_size = middle - left;
            int b_size = right - middle;

            int* copy = new int[right-left];
            int l = 0;
            int r = 0;
            int index = 0;           
            
            while(l<a_size && r<b_size)
            {
                // if(array[left+l]>array[middle+r])
                if(this->condition(array[left+l],array[middle+r])>0)
                {
                    copy[index]= array[left+l];
                    l++;
                }
                else
                {
                    copy[index] = array[middle+r];
                    r++;
                }
                index++;
            }
            
            while(index<(right-left))
            {   
                if(l < a_size)
                {
                    copy[index] = array[left+l];
                    l++;
                }
                if(r < b_size)
                {
                    copy[index] = array[middle+r];
                    r++;
                }
                index++;
            }

            for(int i = 0;i<right-left;i++)
            {
                array[left+i] = copy[i];
            }
        }

    public:
     using AbstractSort<T>::AbstractSort;        string getName() const override
        {
            return "MergeSort";
        }

        void Sort(int *array, int count) override
        {
            SortPart(array, 0, count);
        }
    };
};