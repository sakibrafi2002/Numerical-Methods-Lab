#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    getline(cin, text);
    vector<int>v;
    string  temp = "";
    text += ' ';
    for( int i = 0 ; i < text.size(); i++)
    {
        if(text[i] == ' ')
        {
            int x = stoi(temp);
            v.push_back(x);
            temp = "";
            continue;
        }
        temp += text[i];

    }
    cout << "The integers in texts are: " << endl;
    for(auto i : v)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
