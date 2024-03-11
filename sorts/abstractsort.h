#include <functional>
#include "../utils/testers/abstracttester.h"
#pragma once
using namespace std;
using namespace TestNamespace;
namespace Sorts
{
    template<typename T=int>
    class AbstractSort
    {
    protected:
        AbstractTester<T> *tester;

    public:
        AbstractSort(AbstractTester<T> &tester)
        {
            this->tester = &tester;
        }
        virtual string getName() const = 0;
        virtual void Sort(T *array, int count) = 0;
    };
};