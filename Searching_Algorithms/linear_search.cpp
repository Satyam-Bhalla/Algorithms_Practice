#include <iostream>

using namespace std;

int search(int arr[],int n, int x){
    for(int i =0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, arr[50],i,x;
    cout << "Enter the size of the array: "<<endl;
    cin >> n;
    cout << "Enter the elements separated by new line" << endl;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the element to search"<<endl;
    cin >> x;
    cout << "The element is available at index " << search(arr,n,x);
}
