#include "abstracttester.h"
namespace TestNamespace
{
    class IntTester : public AbstractTester<int>
    {
        public:
        int Test(int a, int b) override
        {
            return a-b;
        }
    };
};