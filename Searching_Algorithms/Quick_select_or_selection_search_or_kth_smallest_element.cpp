#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int arr[],int left,int right){
    int x = arr[right];
    int i = left;
    for(int j=left;j<right;j++){
        if(arr[j]<=x){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

int kthSmallestElement(int arr[],int left, int right, int k){
    int pos;
    if(k>0 && k<=right-left+1){
        pos = partition(arr,left,right);
        // If position is same as k 
        if (pos-left == k-1) 
            return arr[pos]; 
        if (pos-left > k-1)  // If position is more, recur for left subarray 
            return kthSmallestElement(arr, left, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallestElement(arr, pos+1, right, k-pos+left-1); 

    }
    return -1;
}


int basic_solution(int arr[],int left, int right, int k){
    if(k>0 && k<=right-left+1){
        sort(arr, arr + right + 1);
        return arr[k-1];
    }
    return -1;
}

int main(){
    int n, arr[50],i,k,left,right;
    cout << "Enter the size of the array: "<<endl;
    cin >> n;
    cout << "Enter the elements separated by new line" << endl;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    left = 0;
    right = n;
    cout << "Enter the kth smallest element to search"<<endl;
    cin >> k;
    cout << "The kth smallest element is  " << kthSmallestElement(arr,left,right-1,k)<<endl;
    cout << "The kth smallest element is  " << basic_solution(arr,left,right-1,k);
    return 0;
}
