/*
Problem: Job sequencing with deadlines.

Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).

*/

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

static bool comp(const Job &a, const Job &b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comp);

    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int jobProfit = 0;
    int countJobs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return {countJobs, jobProfit};
}

int main()
{
    int n;
    cout << "No of jobs: ";
    cin >> n;
    Job a[n];
    for (int i = 0; i < n; i++)
    {
        int id, dead, profit;
        cin >> id >> dead >> profit;
        a[i].id = id;
        a[i].dead = dead;
        a[i].profit = profit;
    }

    vector<int> ans = JobScheduling(a, n);

    cout << "Total jobs:-> " << ans[0] << " ||  Profit:-> " << ans[1] << endl;

    return 0;
}