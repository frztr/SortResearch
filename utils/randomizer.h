#include <cstdlib>

namespace RandomDigits
{
    class Randomizer
    {
        const static int MaxNumber = 70000;

        static int rand(int min, int max)
        {
            int value = std::rand();
            double percent = (double)value / (double)RAND_MAX;

            int out = (double)min + percent * (double(max - min));
            return out;
        }

    public:
        static int *generateOrderedArray(int count)
        {
            int *array = new int[count];
            array[0] = MaxNumber;
            for (int i = 1; i < count; i++)
            {
                array[i] = array[i - 1] - rand(0, MaxNumber / count) - 1;
            }
            return array;
        }

        static int *generateReversedArray(int count)
        {
            int *array = new int[count];
            array[0] = 0;
            for (int i = 1; i < count; i++)
            {
                array[i] = array[i - 1] + rand(0, MaxNumber / count) + 1;
            }
            return array;
        }

        static int *generateDegenerateArray(int count)
        {
            int *array = new int[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = rand(0, 12)+1;
            }
            return array;
        }

        static int *generateRandomArray(int count)
        {
            int *array = new int[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = rand(0, 70000)+1;
            }
            return array;
        }
    };
}