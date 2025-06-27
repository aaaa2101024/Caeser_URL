#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aaaaa";
    int _ = 0;
    set<char> character;
    character.insert('.');
    character.insert('/');
    character.insert('?');
    character.insert(':');
    character.insert('=');
    cout << "出力するURLの数" << endl;
    cin >> _;
    cout << "鍵は?" << endl;
    int x;
    cin >> x;
    vector<string> S(_);
    cout << "URLを入力" << endl;
    for (int i = 0; i < _; i++)
    {
        cin >> S[i];
    }
    cout << "---Start---" << endl;
    for (int __ = 0; __ < _; __++)
    {
        cout << "https://";
        string s = S[__];
        set<int> is_num;
        for (int i = 0; i < s.size(); i++)
        {
            if (0 <= int(s[i] - '0') && int(s[i] - '0') <= 9)
            {
                is_num.insert(i);
            }
        }
        for (int j = 8; j < s.size(); j++)
        {
            if (!character.count(s[j]))
            {
                if (is_num.count(j))
                {
                    cout << int(s[j] - '0' + x) % 10;
                }
                else if (isupper(s[j]))
                {
                    cout << char(int(s[j] + x - 'A') % 26 + 'A');
                }
                else
                {
                    cout << char(int(s[j] + x - 'a') % 26 + 'a');
                }
            }
            else
            {
                cout << s[j];
            }
        }
        cout << endl;
    }
    cout << "鍵は" << x << endl;
    cout << "---END---" << endl; 
}