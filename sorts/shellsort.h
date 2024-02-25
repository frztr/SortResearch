#include "abstractsort.h"
namespace Sorts{
    class ShellSort:public AbstractSort
    {
        void Exchange(int*array, int left, int right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

        public:
        string getName() const override
        {
            return "ShellSort";
        }

        void Sort(int* array, int count) override
        {
            int gap = count / 2;
            while(gap>0)
            {
                for(int i = gap; i<count;i++)
                {
                    int j = i-gap;
                    bool cond = true;
                    while(array[j]< array[j+gap] && cond)
                    {
                        Exchange(array,j,j+gap);
                        if(j>gap)
                        {
                            j = j-gap;
                        }
                        else
                        {
                            cond = false;
                        }
                    }
                }
                gap = gap/2;   
            }
        }
    };
};