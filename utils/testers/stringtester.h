#include "abstracttester.h"
#include <string>
#include <map>
using namespace std;
namespace TestNamespace
{
    class StringTester : public AbstractTester<string>
    {
        public:
        int Test(string a, string b) override
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
        }
    };
};