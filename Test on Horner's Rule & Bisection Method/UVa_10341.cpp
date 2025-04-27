/// C221060
/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1282

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll p,q,r,s,t,u;

double calc(double x)
{
    return ( (double)p *  exp(-x) ) + ( (double)q  * sin(x) ) + ( (double)r *cos(x)) + ( (double)s * tan(x)) + ( (double)t * x * x ) + (double)u ;
}

int main()
{
    while(cin >> p >> q >> r >> s >> t >> u)
    {
        double l = 0.0, r = 1.0;
        if( (calc(l) * calc(r) ) > 0.0)
        {
            cout << "No solution" << endl;
            continue;
        }
        ll c = 0;
        while(c++ <= 50)
        {
            double m = (l + r)/ 2.0;
            if( calc(m) > 0.0)
                l = m;
            else
                r = m;
        }
        cout << fixed << setprecision(4) << r << endl;
    }
    return 0;
}
