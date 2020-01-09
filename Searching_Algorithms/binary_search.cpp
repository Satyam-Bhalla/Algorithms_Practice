#include <iostream>

using namespace std;

int binary_search_loop(int arr[],int left, int right, int x){
    int mid = 0;
    while (true)
    {
        if(left<=right){
            mid = left + (right-left)/2;
            if(arr[mid]==x){
                return mid;
            }else if(arr[mid]>x){
                right = mid-1;
            }else if(arr[mid]<x){
                left = mid+1;
            }
        }else{
            return -1;
        }
    }
    return 0;
}

int binary_search_recursion(int arr[],int left, int right, int x){
    int mid = 0;
    if(left<=right){
        mid = left + (right-left)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]>x){
            return binary_search_recursion(arr,left,mid-1,x);
        }else if(arr[mid]<x){
            return binary_search_recursion(arr,mid+1,right,x);
        }
    }else{
        return -1;
    }
    return 0;
}



int main(){
    int n, arr[50],i,x,left,right;
    cout << "Enter the size of the array: "<<endl;
    cin >> n;
    left = 0;
    right = n;
    cout << "Enter the elements separated by new line" << endl;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the element to search"<<endl;
    cin >> x;
    cout << "The element is available at index " << binary_search_loop(arr,left,right-1,x);
    cout << "The element is available at index " << binary_search_recursion(arr,left,right-1,x);
    return 0;
}
