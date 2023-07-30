#include <bits/stdc++.h> 
bool sortArr(int n, vector<int> &arr) {
     
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
 
    sort(temp, temp + n);
 
    
    int front;
    for (front = 0; front < n; front++)
        if (temp[front] != arr[front])
            break;
 
    int back;
    for (back = n - 1; back >= 0; back--)
        if (temp[back] != arr[back])
            break;
 
    // If whole array is sorted
    if (front >= back)
        return true;
 
     while (front != back) {
        front++;
        if (arr[front - 1] < arr[front])
            return false;
    }
    return true;
}
