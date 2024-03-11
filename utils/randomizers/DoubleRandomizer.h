#include "AbstractRandomizer.h"
#include <cstdlib>

namespace RandomDigits
{
    class DoubleRandomizer: public AbstractRandomizer<double>
    {
        const static int MaxNumber = 70000;

        double rand(double min, double max) 
        {
            int value = std::rand();
            double percent = (double)value / (double)RAND_MAX;

            double out = (double)min + percent * (double(max - min));
            return out;
        }

    public:
        double *generateOrderedArray(int count) override
        {
            double *array = new double[count];
            array[0] = MaxNumber;
            for (int i = 1; i < count; i++)
            {
                array[i] = array[i - 1] - rand(0, MaxNumber / count) - 1;
            }
            return array;
        }

        double *generateReversedArray(int count) override
        {
            double *array = new double[count];
            array[0] = 0;
            for (int i = 1; i < count; i++)
            {
                array[i] = array[i - 1] + rand(0, MaxNumber / count) + 1;
            }
            return array;
        }

        double *generateDegenerateArray(int count) override
        {
            double *array = new double[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = rand(0, 12)+1;
            }
            return array;
        }

        double *generateRandomArray(int count) override
        {
            double *array = new double[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = rand(0, 70000)+1;
            }
            return array;
        }
    };
}