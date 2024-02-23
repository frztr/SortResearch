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
            
        }
    };
};