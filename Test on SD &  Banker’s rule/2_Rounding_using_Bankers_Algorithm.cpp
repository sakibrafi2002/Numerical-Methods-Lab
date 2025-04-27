/// Write a program to round off a number with n digits after decimal point using bankers rule.
/// C221060

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string number;
    cin >> number;
    int digit;
    cin >> digit;
    int point;
    for(int i = 0; i < number.size(); i++){
        if(number[i] == '.'){
            point = i;
            break;
        }
    }
    if( (number[point + digit + 1] < '5') || (number[point + digit + 1] == '5' and (number[point + digit] - '0') % 2 == 0 )){
        cout << "The answer is: ";
        for(int i = 0; i <= point + digit; i++){
            cout << number[i];
        }
        cout << endl;
    }
    else{
        bool f = false,inc = false;
        if(number[point + digit] != '9') f = true;
        string ans = "";
        if(f){
            number[point + digit] = char(number[point + digit] + 1);
            cout << "The answer is: ";
            for(int i = 0; i <= point + digit; i++){
                cout << number[i];
            }
            cout << endl;

        }
        else{
            for(int i = point + digit; i >= 0; i--){
                if(number[i] != '9' and number[i] != '.') f = true;
                if(number[i] == '.'){
                    ans += number[i];
                    continue;
                }
                if(f == true and inc == true){
                    ans += number[i];
                }
                else if(f == false and inc == false){
                    ans += '0';
                }
                else if(f == true and inc == false){
                    ans += char(number[i] + 1);
                    inc = true;
                }
            }
            if(f == false){
                ans += '1';
            }

            reverse(ans.begin(),ans.end());
            cout << "The answer is: ";
            cout << ans << endl;

        }

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

Input:

5
2.9956
3
2.9966
3
99.99999
3
98.99999
3
5.9996
3

Output:

The answer is: 2.996
The answer is: 2.997
The answer is: 100.000
The answer is: 99.000
The answer is: 6.000


*/

