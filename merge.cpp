#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

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

    for (int idx = start; idx <= end; idx++)
        v[idx] = temp[idx];
}

void mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(v, temp, start, mid);
        mergeSort(v, temp, mid + 1, end);
        merge(v, temp, start, mid, end);
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
    srand(static_cast<unsigned int>(time(0)));

    vector<int> a;
    dataSet(100000, a);

    vector<int> temp(a.size());

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    mergeSort(a, temp, 0, static_cast<int>(a.size()) - 1);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    chrono::microseconds durationUs = chrono::duration_cast<chrono::microseconds>(end - start);
    double durationMs = durationUs.count() / 1000.0;

    cout << fixed << setprecision(3);
    cout << "Name : Shahriar Shayekh" << endl;
    cout << "ID: C243020" << endl;
    cout << "Algo Name : Merge Sort" << endl;
    cout << "Input Time : 1e5" << endl;
    cout << "Sorting time: " << durationMs << " ms (" << durationUs.count() << " us)" << endl;

    return 0;
}