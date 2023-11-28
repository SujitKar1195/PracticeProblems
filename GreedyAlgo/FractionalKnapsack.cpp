/*
 Problem:

 Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.

Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
Output: 240
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg.
Hence total price will be 60+100+(2/3)(120) = 240
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit;
    int weight;
};

// Comparator function

static bool comp(const Item &a, const Item &b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item a[], int n, int capacity)
{
    // Sort items by (profit/ weight) in descending order.
    sort(a, a + n, comp);

    // Compute how much amount of weights we have taken in the knapsack.
    int currWeight = 0;

    // Maximum possible profit
    double finalValue = 0.0;

    // Calculation.
    for (int i = 0; i < n; i++)
    {
        if (currWeight + a[i].weight <= capacity)
        {
            currWeight += a[i].weight;
            finalValue = finalValue + a[i].profit;
        }
        else
        {
            int remainingWeight = capacity - currWeight;
            finalValue += (a[i].profit / (double)a[i].weight) * (double)remainingWeight;
            break;
        }
    }
    return finalValue;
}

int main()
{
    int n;
    cout << "Enter no of items: ";
    cin >> n;
    Item a[n];
    for (int i = 0; i < n; i++)
    {
        int profit;
        cin >> profit;
        int weight;
        cin >> weight;
        a[i].profit = profit;
        a[i].weight = weight;
    }

    int knapCapacity;
    cout << "Enter knap capacity: ";
    cin >> knapCapacity;

    cout << "Maximum profit: " << fractionalKnapsack(a, n, knapCapacity) << endl;

    return 0;
}