// Input format :
// The first line contains an integer, representing the number of elements in the array.
// The second line contains n space-separated integers, where each integer is either 0 or 1.

// Output format :
// The output displays the following result:
// If the input contains elements other than 0 and 1, print "Invalid input.".
// Otherwise, print a single line containing n space-separated integers, representing the sorted array in ascending order.

#include<iostream>
using namespace std;

void merge(int *arr, int l, int mid, int r) {
    int m = mid - l + 1;
    int n = r - mid;

    int *a = new int[m];
    int *b = new int[n];

    for(int i = 0; i < m; i++) {
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while(i < m && j < n) {
        if(a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < m) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j < n) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements (0 or 1): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input." << endl;
            return 0;
        }
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
