#include <bits/stdc++.h> 

// void swap(int a, int b){
//     int c= a;
//     a= b;
//     b = c;
// }

int partition(int start, int end, vector<int> &arr){
    int pivot = arr[start];
    int i = start;
    int j = end;
    while( i < j ){
        while(arr[i] <= pivot && i < end){
            i++;
        }

        while(arr[j] > pivot && j > start ){
            j--;
        }
        if(i < j)swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
}

void qSort(int start, int end, vector<int> &arr){
    if(start < end){
        int pIndex = partition(start, end, arr);
        qSort(start, pIndex-1, arr);
        qSort(pIndex+1, end, arr);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    int n = arr.size();
    qSort(0, n-1, arr);
    return arr;
}
