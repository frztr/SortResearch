#include "abstractsort.h"

namespace Sorts{
    class InsertionSort: public AbstractSort{

        public:
        string getName() const override
        {
            return "InsertionSort";
        }

        void Sort(int* array, int count) override
        {
            for(int i = 0; i < count;i++){
                int temp = array[i];
                int j = i - 1;
                bool dec = true;
                while(j>=0 && dec)
                {
                    if(array[j] < temp)
                    {
                        array[j+1] = array[j];
                        j--;
                    }
                    else
                    {
                        dec = false;
                    }
                    
                }
                array[j+1] = temp;
            }
        }
    };
};