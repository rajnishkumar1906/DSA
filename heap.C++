#include <iostream>
#define size 100
using namespace std;

class heap
{
public:
    int *arr;
    int n;

    heap()
    {
        arr = new int[size];
        arr[0] = -1;
        n = 0;
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void min_heap_insert(int val) // Min heap
    {
        n++;
        int index = n;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index]) // Changed to make it a min-heap
            {
                swap(&arr[index], &arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void max_heap_insert(int value)
    {
        n++;
        int index = n;
        arr[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(&arr[parent], &arr[index]);
                index = parent; // Updation of index to parent
            }
            else
            {
                return;
            }
        }
    }

    void heapify(int i) // Min Heapification
    {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right <= n && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(&arr[smallest], &arr[i]);
            heapify(smallest);
        }
    }

    void deleteFromHeap()
    {
        if (n == 0)
        {
            cout << "Heap is empty. Cannot delete." << endl;
            return;
        }

        arr[1] = arr[n];
        n--;
        heapify(1);
    }

    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void minHeapify(int *arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right <= n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        minHeapify(arr, n, i);
    }

    for (int i = n; i > 0; i--)
    {
        swap(arr[1], arr[i]);
        minHeapify(arr, i - 1, 1);
    }
}

int main()
{
    heap h;
    h.min_heap_insert(10);
    h.min_heap_insert(20);
    h.min_heap_insert(30);
    h.min_heap_insert(40);
    h.min_heap_insert(15);
    h.min_heap_insert(12);

    cout << "Min-Heap: ";
    h.print();

    h.max_heap_insert(10);
    h.max_heap_insert(20);
    h.max_heap_insert(30);
    h.max_heap_insert(50);
    h.max_heap_insert(40);

    cout << "Max heap : ";
    h.print();

    int array[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        minHeapify(array, n, i);
    }

    cout << "Min Heapified Array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << array[i] << " ";
    }

    heapSort(array, n);

    cout << "\nSorted Array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << array[i] << " ";
    }
    h.deleteFromHeap();
    cout << "\nNew heap after deletion : ";
    h.print();
    return 0;
}