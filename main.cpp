#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

int n = 10;

vector <int> tmp(1000000, 0); // Для merge
long long comp = 0, m = 0;

void selection_sort(vector <int> &arr){
    int cur_index = 0;
    int min_val = int(1e9), min_index, i = 0, j = 0;
    while (i < arr.size()){
        j = i;
        while (j < arr.size()){
            comp ++;
            if (min_val > arr[j]){
                min_val = arr[j];
                min_index = j;
            }
            ++j;
        }
        if (cur_index != min_index) m++;
        swap(arr[cur_index++], arr[min_index]);
        min_val = int(1e9);
        min_index = -1;
        ++i;
    }
}

void mergeSort(vector <int> &a, int l, int r)
{
    if (l == r) return; 
    int mid = (l + r) / 2; 
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int i = l;  
    int j = mid + 1; 
    for (int step = 0; step < r - l + 1; step++) 
    {
    
        ++comp;
        ++m;

        if ((j > r) || ((i <= mid) && (a[i] < a[j]))) 
        {
            tmp[step] = a[i];
            i++;
        }
        else 
        {
            tmp[step] = a[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++){
        a[l + step] = tmp[step];
        ++m;
    }
}
void heapify(vector <int> &arr, int n, int i)
{
    int root = i;   
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    if (l < n && arr[l] > arr[root])
        root = l;
    ++comp;
    if (r < n && arr[r] > arr[root]){
        root = r;
        ++comp;
    }
    if (root != i)
    {
        swap(arr[i], arr[root]);
        ++m;
        heapify(arr, n, root);
    }
}

void heap_Sort(vector <int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        m++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    
    srand( time(0) );
    vector <int> b(n);
    for (int i = 0; i < n; ++i)    b[i] = n - i;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i)    b[i] = rand();
    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    cout << '\n';
    heap_Sort(b, b.size());
    for (int i = 0; i < n; ++i){
        cout << b[i] << ' ' ;
    }
    //100, 1000, 10000, 100000, 1000000
    

    //mergeSort(b, 0, b.size() - 1);
    //heapSort(b);
    //selection_sort(b);
    /*
    for (int i = 0; i < 5; ++i){
        comp = 0;
        m = 0;
        n = n * 10;
        vector <int> b(n);
        for (int i = 0; i < n; ++i)    b[i] = n - i;
        auto start = std::chrono::steady_clock::now();
        
        heapSort(b);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << n << '\n';
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        cout << comp << '+' << m << '\n';
    }
    */
    return 0;
}