#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        long long temp = x;
        long long reverse = 0;
        while (temp != 0)
        {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }
        if (reverse == x)
        {
            cout << x << " is palindrome" << endl;
            return true;
        }
        else
        {
            cout << x << " is not palindrome" << endl;
            return false;
        }
    }
};

int main()
{
    Solution sol;
    sol.isPalindrome(121);
    sol.isPalindrome(1232123);
    return 0;
}
