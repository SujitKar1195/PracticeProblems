#include <bits/stdc++.h>
using namespace std;

void permute(int index, vector<int> &nums, vector<vector<int>> &ans)
{

    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
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

    vector<vector<int>> ans;
    permute(0, nums, ans);

    set<vector<int>> st;
    for (vector<int> &v : ans)
        st.insert(v);
    ans.clear();
    for (const vector<int> &v : st)
        ans.push_back(v);
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