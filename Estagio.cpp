
#include <bits/stdc++.h>
using namespace std;
int main()
{
// boraaa
   string input;
   cin >> input;
   set<char> setDoInput;
    for (char c : input){
        setDoInput.insert(c);
    }
    for (char c : setDoInput){
        cout << c ;
    }
    return 0;
}
