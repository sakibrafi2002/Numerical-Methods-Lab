/// Write a program to count number of significant digits in a given number.
/// C221060

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string number;
    cin >> number;
    deque<char>integer,decimal;
    bool point = false;
    for(auto a : number){
        if(a == '.'){
            point = true;
            break;
        }
        else{
            integer.push_back(a);
        }
    }
    if(point){
        string t = number;
        reverse(t.begin(),t.end());
        for(auto a : t){
            if(a == '.') break;
            decimal.push_front(a);
        }
        while(integer.size() != 0 and integer.front() == '0'){
            integer.pop_front();
        }
        if(integer.size() == 0){
            while(decimal.size() != 0 and decimal.front() == '0'){
                decimal.pop_front();
            }
            cout << "Total number of Significant digits: " << ( decimal.size() ) << endl;
        }
        else{
            cout << "Total number of Significant digits: " << ( integer.size() + decimal.size() ) << endl;
        }




    }
    else{
         while(integer.size() != 0 and integer.front() == '0'){
            integer.pop_front();
         }
         while(integer.size() != 0 and integer.back() == '0'){
            integer.pop_back();
         }

         cout << "Total number of Significant digits: " << integer.size() << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}

/*

5
00200
200
002.00200
0.00
0.00300

*/
