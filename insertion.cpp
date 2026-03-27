#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(vector<int> &a)
{
    for (int j = 1; j < a.size(); j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            --i;
        }
        a[i + 1] = key;
    }
}

void dataSet(int n, vector<int> &a)
{
    unordered_set<int> used;
    while (used.size() < n)
    {
        int x = rand() % 1000000 + 1;
        if (used.insert(x).second)
        {
            a.push_back(x);
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    vector<int> a;
    dataSet(100000, a);

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    insertionSort(a);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    chrono::microseconds durationUs = chrono::duration_cast<chrono::microseconds>(end - start);
    double durationMs = durationUs.count() / 1000.0;

    cout << fixed << setprecision(3);
    cout << "Name : Shahriar Shayekh" << endl;
    cout << "ID: C243020" << endl;
    cout << "Algo Name : Insertion Sort" << endl;
    cout << "Input Time : 1e5" << endl;
    cout << "Sorting time: " << durationMs << " ms (" << durationUs.count() << " us)" << endl;

    return 0;
}