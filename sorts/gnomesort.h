#include "abstractsort.h"
namespace Sorts
{
    class GnomeSort: public AbstractSort
    {   
        void Exchange(int* array, int left, int right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

        public:
        string getName() const override
        {
            return "GnomeSort";
        }

        void Sort(int* array, int count)
        {
            int l = count-1;
            while(l>0){
            if(array[l-1]>array[l])
            {
                l--;
            }
            else
            {
                Exchange(array,l-1,l);
                l++;
            }
            }
        }
    };
};