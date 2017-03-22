/*  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.

* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.

* For the purpose of this problem, we define empty string as valid palindrome. 
*/

#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for ( int i = 0, j = s.length()-1; i < j; ) {
            if ( !isalnum(s[i]) ) {
                i++;
            } else if ( !isalnum(s[j]) ) {
                j--;
            } else if ( toupper(s[i]) != toupper(s[j]) ) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    string s = "A man, a plan, a canal: Panama";
    // string s = "0P";
    
    Solution sol;
    
    cout << (sol.isPalindrome(s) ? "Yes" : "No") << endl;
    
    return 0;
}
