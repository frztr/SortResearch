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
using namespace TimerNamespace;

template <typename T>
bool isSorted(T *array, int count, AbstractTester<T> &test)
{
    for (int i = 1; i < count; i++)
    {
        if (test.Test(array[i], array[i - 1]) > 0)
        {
            // cout << endl << array[i] << "|" << array[i-1] << endl;
            // throw new exception();
            return false;
        }
    }
    return true;
};

template <typename T>
long makeCalculation(T *array, int count, AbstractSort<T> &algorithm, AbstractTester<T> &test)
{
    T *arrayCopy = new T[count];
    for (int i = 0; i < count; i++)
    {
        arrayCopy[i] = array[i];
    }
    Timer timer = Timer();
    timer.init_timer();
    algorithm.Sort(arrayCopy, count);
    long time = timer.get_timer();
    if (!isSorted<T>(arrayCopy, count,test))
    {
        throw new exception();
    }

    return time;
}

template <typename T>
T **generateArrays(vector<int> sizes, int sizes_count, AbstractRandomizer<T> &randomizer)
{
    T **arrays = new T *[sizes_count * 4];
    for (int i = 0; i < sizes_count; i++)
    {
        arrays[i * 4] = randomizer.generateOrderedArray(sizes[i]);
        arrays[i * 4 + 1] = randomizer.generateReversedArray(sizes[i]);
        arrays[i * 4 + 2] = randomizer.generateDegenerateArray(sizes[i]);
        arrays[i * 4 + 3] = randomizer.generateRandomArray(sizes[i]);
    }
    return arrays;
}

template <typename T>
void TypeResearch(AbstractRandomizer<T> &randomizer, AbstractTester<T> &tester)
{
    cout << "Type: " << typeid(T).name() << endl;
    const int width = 32;
    
    // vector<int> sizes = {1000, 2000, 4000, 8000, 16000, 32000, 64000};
    vector<int> sizes = {1000,2000,4000,8000,16000};

    T **arraysPointer = generateArrays<T>(sizes, sizes.size(),randomizer);
    vector<AbstractSort<T> *> sortAlgorithms{
        new BubbleSort<T>(tester),
        new QuickSort<T>(tester),
        new BinaryTreeSort<T>(tester),
        new ShakeSort<T>(tester),
        new CombSort<T>(tester),
        new InsertionSort<T>(tester),
        new SelectionSort<T>(tester),
        new MergeSort<T>(tester),
        new HeapSort<T>(tester),
        new ShellSort<T>(tester),
        new GnomeSort<T>(tester),
        new CountingSort<T>(tester),
        new RadixSortLSD<T>(tester),
        new RadixSortMSD<T>(tester)
        };

    cout << std::left << setw(width) << "Sort/Size";
    for (int i = 0; i < sizes.size(); i++)
    {
        cout << setw(width) << sizes[i];
    }
    cout << endl;

    for (AbstractSort<T> *sort : sortAlgorithms)
    {
        cout << setw(width) << sort->getName();

        for (int i = 0; i < sizes.size(); i++)
        {
            string out = "";
            for (int j = 0; j < 4; j++)
            {
                long time = makeCalculation(arraysPointer[i * 4 + j], sizes[i], *sort, tester);
                if (j != 0)
                {
                    out += "/";
                }
                out += to_string(time);
            }
            cout << setw(width) << out;
        }

        cout << endl;
    };
}

int main()
{
    srand((unsigned int)time(NULL));
    TypeResearch<int>(*(new IntRandomizer()),*(new IntTester()));
    TypeResearch<double>(*(new DoubleRandomizer()),*(new DoubleTester()));
    TypeResearch<string>(*(new StringRandomizer()),*(new StringTester()));
    return 0;
};

// CountingSort??
// RadixLSD??
// RadixMSD??

// int main()
// {
//     using arrayType = double;
//     using arrayRandomizer = DoubleRandomizer;
//     using arrayTester = DoubleTester;

//     srand((unsigned int)time(NULL));
//     int size = 64000;
//     arrayType *array = (new arrayRandomizer())->generateReversedArray(size);
//     for (int i = 0; i < size; i++)
//     {
//         cout << array[i] << "\t\t";
//     }
//     cout << endl;
//     AbstractTester<arrayType> *tester = new arrayTester();
//     RadixSortMSD<arrayType> sort = RadixSortMSD<arrayType>(*tester);
//     sort.Sort(array, size);
//     for (int i = 0; i < size; i++)
//     {
//         cout << array[i] << "\t\t";
//     }
//     cout << endl;

//     cout << isSorted<arrayType>(array, size, *tester);
//     cout << endl;
// }