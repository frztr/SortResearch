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
#include "utils/randomizer.h"
// #include "utils/customTimer.h"
#include <vector>

using namespace std;
using namespace Sorts;
using namespace RandomDigits;
// using namespace TimerNamespace;

bool isSorted(int *array, int count)
{
    for (int i = 1; i < count; i++)
    {
        if (array[i] > array[i - 1])
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
//     delete arrayCopy;
//     return time;
// }

int **generateArrays(int *sizes, int sizes_count)
{
    int **arrays = new int *[sizes_count * 4];
    for (int i = 0; i < sizes_count; i++)
    {
        arrays[i * 4] = Randomizer::generateOrderedArray(sizes[i]);
        arrays[i * 4 + 1] = Randomizer::generateReversedArray(sizes[i]);
        arrays[i * 4 + 2] = Randomizer::generateDegenerateArray(sizes[i]);
        arrays[i * 4 + 3] = Randomizer::generateRandomArray(sizes[i]);
    }
    return arrays;
}

// int main()
// {
//     srand((unsigned int) time(NULL));
//     const int count = 7;
//     const int width = 32;
//     int sizes[count] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

//     int **arraysPointer = generateArrays(sizes, count);
//     vector<AbstractSort*> sortAlgorithms{
//     new BubbleSort(),
//     // new QuickSort(),
//     // new BinaryTreeSort(),
//     // new ShakeSort(),
//     new CombSort()
//     };

//     cout << std::left << setw(width) << "Sort/Size";
//     for (int i = 0; i < count; i++)
//     {
//         cout << setw(width) << sizes[i];
//     }
//     cout << endl;

//     for (AbstractSort* sort: sortAlgorithms)
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

int main(){
    srand((unsigned int) time(NULL));
    int size = 1000;
    int* array = Randomizer::generateRandomArray(size);
    for(int i = 0;i < size;i++){
        cout << array[i] <<"\t";
    }
    cout << endl;
    InsertionSort sort = InsertionSort();
    sort.Sort(array,size);
    for(int i = 0;i < size;i++){
        cout << array[i] <<"\t";
    }
    cout << endl;
}