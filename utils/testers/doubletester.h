#include "abstracttester.h"
namespace TestNamespace
{
    class DoubleTester : public AbstractTester<double>
    {
        public:
        int Test(double a, double b) override
        {
            if (a < b)
                return -1;
            if (a > b)
                return 1;
            return 0;
        }
    };
};