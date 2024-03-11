#include "abstractsort.h"

namespace Sorts{
    template <typename T>
    class InsertionSort: public AbstractSort<T>
    {

        public:
        using AbstractSort<T>::AbstractSort;        
        string getName() const override
        {
            return "InsertionSort";
        }

        void Sort(T* array, int count) override
        {
            for(int i = 0; i < count;i++){
                T temp = array[i];
                int j = i - 1;
                bool dec = true;
                while(j>=0 && dec)
                {
                    if(this->tester->Test(array[j],temp)<0)
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