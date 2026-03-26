#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

void dataSet(int n, vector<int> &a)
{
    for (int i = 0; i < n; i++)
    {
        a.push_back(rand());
    }
}

int main()
{
    srand(time(0));

    vector<int> a;
    dataSet(1e5, a);

    clock_t start = clock();

    quickSort(a, 0, a.size() - 1);

    clock_t end = clock();

    double durationMs = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    cout << fixed << setprecision(3);
    cout << "Name : Shahriar Shayekh" << endl;
    cout << "ID: C243020" << endl;
    cout << "Algo Name : Quick Sort" << endl;
    cout << "Input Time : 1e4" << endl;
    cout << "Sorting time: " << durationMs << " ms " << endl;

    return 0;
}