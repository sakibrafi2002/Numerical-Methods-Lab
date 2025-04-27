/// C221060
/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=439

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    string t, tt;

    while (getline(cin, t)) {
        if (!getline(cin, tt)) break;

        vector<ll> coefficient, x;
        stringstream ss1(t), ss2(tt);
        ll num;

        while (ss1 >> num) {
            coefficient.push_back(num);
        }

        while (ss2 >> num) {
            x.push_back(num);
        }

        vector<ll> ans;

        for (auto val : x) {
            ll result = coefficient[0];
            for (int i = 1; i < coefficient.size(); i++) {
                result = (result * val) + coefficient[i];
            }
            ans.push_back(result);
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
        }
    }

    return 0;
}
