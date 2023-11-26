#include <bits/stdc++.h>
using namespace std;

void recPermute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, bool freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = true;
            ds.push_back(nums[i]);
            recPermute(nums, ds, ans, freq);
            freq[i] = false;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    bool freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = false;

    recPermute(nums, ds, ans, freq);
    return ans;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}