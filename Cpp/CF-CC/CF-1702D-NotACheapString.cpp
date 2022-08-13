#include <bits/stdc++.h>
using namespace std;
bool sortBySec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void solve(string w, int p)
{
    /* Utilities :
     i) map to store whether character will be printed or deleted. (named keep)
     ii) A vector of pair to store costs of each character (pair<int,int>: first = index and second is cost)
     iii) A vector of int to store sum of costs till that index
     Note: indexing from 1 is followed.
    */
    int size = w.size();
    string ans = "";
    map<int, bool> keep;
    vector<pair<int, int>> costArr;
    int sumArr[size + 1];
    sumArr[0] = 0;
    costArr.push_back(make_pair(0, 0));
    for (int i = 0; i < size; i++)
    {
        int chrCost = w[i] - 'a' + 1; // represents cost of character
        costArr.push_back(make_pair(i + 1, chrCost));
        keep[i + 1] = true;
    }
    sort(costArr.begin(), costArr.end(), sortBySec);
    for (int i = 1; i < costArr.size(); i++)
    {
        sumArr[i] = sumArr[i - 1] + costArr[i].second;
    }
    for (int i = size; i >= 0; i--)
    {
        if (sumArr[i] > p)
        {
            int index = costArr[i].first;
            keep[index] = false;
        }
        else
            break;
    }
    for (int i = 0; i < size; i++)
    {
        if (keep[i + 1])
        {
            ans.push_back(w[i]);
        }
    }
    cout << ans << "\n";
}
int main()
{
    int t, p;
    string w;
    cin >> t;
    while (t--)
    {
        cin >> w;
        cin >> p;
        solve(w, p);
    }
    return 0;
}