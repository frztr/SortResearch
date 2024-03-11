#pragma once
namespace TestNamespace{
    template <typename T> 
    class AbstractTester{
        public:
        virtual int Test(T a, T b) = 0;
    };
}