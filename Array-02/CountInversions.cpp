#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr , int st, int mid , int end){
    vector<int> temp;
    int i = st;
    int j = mid+1;
    int count = 0;

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
            count += mid - i + 1;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=st; i<=end; i++){
        arr[i] = temp[i-st];
    }

    return count;
}

int mergeSort(vector<int>& arr, int st, int end){
    if(st >= end){
        return 0;
    }

    int mid = (st+end)/2;
    int count = 0;
    count += mergeSort(arr, st, mid);
    count += mergeSort(arr, mid+1, end);
    count += merge(arr, st, mid, end);

    return count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    cout<<mergeSort(arr, 0, arr.size()-1);
    return 0;
}