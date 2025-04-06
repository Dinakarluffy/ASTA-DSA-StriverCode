#include <bits/stdc++.h>
using namespace std;

void explainpair()
{
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> ps = {1, {2, 3}};
    cout << ps.first << " " << ps.second.first << " " << ps.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 3}};
    cout << arr[1].second << endl;
}

void explainvector()
{
    vector<int> v;

    v.push_back(1);

    v.emplace_back(2);

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});

    vector<int> v1(5);

    vector<int> v2(v1);

    vector<int> v3(3, 20);

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it = it + 2;

    vector<int>::iterator it1 = v.end();
    // vector<int>::iterator it2=v.rend();
    // vector<int>::iterator it3=v.rbegin();

    cout << v[0] << " " << v.at(0);

    cout << v.back() << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    for (auto it : v)
    {
        cout << it;
    }

    v.erase(v.begin() + 1);
    v.erase(v.begin() + 1, v.begin() + 4);

    
}
int main()
{
}