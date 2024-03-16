#include "abstracttester.h"
#include <string>
#include <map>
using namespace std;
namespace TestNamespace
{
    class StringTester : public AbstractTester<string>
    {
        map<char, int> alphabet;

        public:
        StringTester()
        {
            string str = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789";
            
            for (int i = 0; i < str.length(); i++)
            {
                alphabet[str[i]] = i;
            }
        }

        int Test(string a, string b) override
        {
            for (int i = 0; i < a.length() && i < b.length(); i++)
            {
                if (alphabet[a[i]] > alphabet[b[i]])
                    return 1;
                if (alphabet[b[i]] > alphabet[a[i]])
                    return -1;
            }
            if (a.length() > b.length())
                return 1;
            if (a.length() < b.length())
                return -1;
            return 0;
        }
    };
};