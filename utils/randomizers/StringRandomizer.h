#include "AbstractRandomizer.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;
namespace RandomDigits
{
    class StringRandomizer : public AbstractRandomizer<string>
    {
        const static int MaxNumber = 916132832;

        static int rand(int min, int max)
        {
            int value = std::rand();
            double percent = (double)value / (double)RAND_MAX;

            int out = (double)min + percent * (double(max - min));
            return out;
        }

        static string weightToStr(int weight)
        {
            static string _charset = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789";
            int charlen = _charset.length();
            int curweight = weight;
            string word;
            int index = 0;

            int len = rand(0,10)+1;
        
            int maxRange = MaxNumber;
            for(int i = 0;i<len;i++)
            {
                int sector = ceil((double)maxRange/(double)_charset.length());
                int k = curweight/sector;
                word.resize(word.length()+1);
                word[i] = _charset[k];
                curweight = curweight - k*sector;
                maxRange = sector;
                if(curweight == 0) return word;
            }

            return word;
        }

    public:
        string *generateOrderedArray(int count) override
        {
            string *array = new string[count];
            int last = MaxNumber-1;
            array[0] = weightToStr(last);
            for (int i = 1; i < count; i++)
            {
                last = last - rand(0, MaxNumber / count) - 1;
                array[i] = weightToStr(last);
            }
            return array;
        }

        string *generateReversedArray(int count) override
        { 
            string *array = new string[count];
            int last = 1;
            array[0] = weightToStr(last);
            for (int i = 1; i < count; i++)
            {
                last = last + rand(0, MaxNumber / count) + 1;
                array[i] = weightToStr(last);
            }
            return array;
        }

        string *generateDegenerateArray(int count) override
        {
            string *array = new string[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = weightToStr(rand(0, MaxNumber / (70000 / 12)) + 1);
            }
            return array;
        }

        string *generateRandomArray(int count) override
        {
            string *array = new string[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = weightToStr(rand(0, MaxNumber) + 1);
            }
            return array;
        }
    };
}