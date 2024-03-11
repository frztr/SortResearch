#include <iostream>
#include <array>
#include <iomanip>
#include "sorts/abstractsort.h"
#include "sorts/bubblesort.h"
#include "sorts/quicksort.h"
#include "sorts/binarytreesort.h"
#include "sorts/shakesort.h"
#include "sorts/combsort.h"
#include "sorts/insertionsort.h"
#include "sorts/selectionsort.h"
#include "sorts/mergesort.h"
#include "utils/randomizers/AbstractRandomizer.h"
#include "utils/randomizers/IntRandomizer.h"
#include "utils/randomizers/DoubleRandomizer.h"
#include "sorts/shellsort.h"
#include "sorts/gnomesort.h"
#include "sorts/heapsort.h"
#include "sorts/countingsort.h"
#include "utils/randomizers/StringRandomizer.h"
#include "utils/testers/abstracttester.h"
#include "utils/testers/doubletester.h"
#include "utils/testers/inttester.h"
#include "utils/testers/stringtester.h"
#include <map>
#include "sorts/radixsortLSD.h"
#include "sorts/radixsortMSD.h"
#include "utils/customTimer.h"
#include <vector>
#include <math.h>

using namespace std;
using namespace Sorts;
using namespace RandomDigits;
using namespace TestNamespace;
// using namespace TimerNamespace;

int intTest(int a, int b)
{
    return a - b;
}

int doubleTest(double a, double b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

int stringTest(string a, string b)
{
    string str = "9876543210zZyYxXwWvVuUtTsSrRqQpPoOnNmMlLkKjJiIhHgGfFeEdDcCbBaA";
    map<char, int> alphabet;
    for (int i = 0; i < str.length(); i++)
    {
        alphabet[str[i]] = i;
    }

    for (int i = 0; i < a.length() && i < b.length(); i++)
    {
        if (alphabet[a[i]] > alphabet[b[i]])
            return 1;
        if (alphabet[b[i]] > alphabet[a[i]])
            return -1;
    }
    if (a.length() > b.length())
        return -1;
    if (a.length() < b.length())
        return 1;
    return 0;
};

template <typename T>
bool isSorted(T *array, int count, AbstractTester<T> &test)
{
    for (int i = 1; i < count; i++)
    {
        if (test.Test(array[i], array[i - 1]) > 0)
        {
            return false;
        }
    }
    return true;
};

// long makeCalculation(int *array, int count, AbstractSort &algorithm)
// {
//     int *arrayCopy = new int[count];
//     for (int i = 0; i < count; i++)
//     {
//         arrayCopy[i] = array[i];
//     }
//     Timer timer = Timer();
//     timer.init_timer();
//     algorithm.Sort(arrayCopy, count);
//     long time = timer.get_timer();
//     if (!isSorted(arrayCopy, count))
//     {
//         throw new exception();
//     }

//     return time;
// }

// int **generateArrays(int *sizes, int sizes_count)
// {
//     int **arrays = new int *[sizes_count * 4];
//     for (int i = 0; i < sizes_count; i++)
//     {
//         arrays[i * 4] = Randomizer::generateOrderedArray(sizes[i]);
//         arrays[i * 4 + 1] = Randomizer::generateReversedArray(sizes[i]);
//         arrays[i * 4 + 2] = Randomizer::generateDegenerateArray(sizes[i]);
//         arrays[i * 4 + 3] = Randomizer::generateRandomArray(sizes[i]);
//     }
//     return arrays;
// }

// int main()
// {
//     srand((unsigned int)time(NULL));
//     const int count = 7;
//     const int width = 32;
//     int sizes[count] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

//     int **arraysPointer = generateArrays(sizes, count);
//     vector<AbstractSort *> sortAlgorithms{
//         new BubbleSort(),
//         new QuickSort(),
//         new BinaryTreeSort(),
//         new ShakeSort(),
//         new CombSort(),
//         new InsertionSort(),
//         new SelectionSort(),
//         new MergeSort(),
//         new HeapSort(),
//         new ShellSort(),
//         new GnomeSort()
//         };

//     cout << std::left << setw(width) << "Sort/Size";
//     for (int i = 0; i < count; i++)
//     {
//         cout << setw(width) << sizes[i];
//     }
//     cout << endl;

//     for (AbstractSort *sort : sortAlgorithms)
//     {
//         cout << setw(width) << sort->getName();

//         for (int i = 0; i < count; i++)
//         {
//             string out = "";
//             for (int j = 0; j < 4; j++)
//             {
//                 long time = makeCalculation(arraysPointer[i * 4 + j], sizes[i], *sort);
//                 if (j != 0)
//                 {
//                     out += "/";
//                 }
//                 out += to_string(time);
//             }
//             cout << setw(width) << out;
//         }

//         cout << endl;
//     };

//     return 0;
// };

// CountingSort??
// RadixLSD??
// RadixMSD??

int main()
{
    srand((unsigned int)time(NULL));
    int size = 64000;
    string *array = (new StringRandomizer())->generateDegenerateArray(size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t\t";
    }
    cout << endl;
    AbstractTester<string> *tester = new StringTester();
    CountingSort<string> sort = CountingSort<string>(*tester);
    sort.Sort(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t\t";
    }
    cout << endl;

    cout << isSorted<string>(array, size, *tester);
    cout << endl;
}