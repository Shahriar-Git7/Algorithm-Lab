#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <iomanip>
using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
    vector<int> temp(v.size());
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] > v[j])
            temp[k++] = v[j++];
        else
            temp[k++] = v[i++];
    }

    while (i <= mid)
        temp[k++] = v[i++];
    while (j <= end)
        temp[k++] = v[j++];

    for (int i = start; i <= end; i++)
        v[i] = temp[i];
}

void mergeSort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

void dataSet(int n, vector<int> &a)
{
    unordered_set<int> used;

    while (used.size() < n)
    {
        int x = rand() % 1000000 + 1;
        if (used.insert(x).second)
            a.push_back(x);
    }
}

int main()
{
    srand(time(0));

    vector<int> a;
    dataSet(1000, a);

    clock_t start = clock();

    mergeSort(a, 0, a.size() - 1);

    clock_t end = clock();

    double durationMs = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    cout << fixed << setprecision(3);
    cout << "Name : Shahriar Shayekh" << endl;
    cout << "ID: C243020" << endl;
    cout << "Algo Name : Merge Sort" << endl;
    cout << "Input Time : 1e4" << endl;
    cout << "Sorting time: " << durationMs << " ms" << endl;

    return 0;
}