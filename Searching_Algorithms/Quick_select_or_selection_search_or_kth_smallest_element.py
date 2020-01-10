# Instead of recursing into both sides, as in quicksort, quickselect only recurses into one side –
# the side with the element it is searching for.
# This reduces the average complexity from O(n log n) to O(n), with a worst case of O(n2).

def partition(arr,left,right):
    x = arr[right]
    i = left
    for j in range(left,right):
        if arr[j]<x:
            arr[j],arr[i]=arr[i],arr[j]
            i += 1
    arr[i],arr[right] = arr[right],arr[i]
    return i

def kthSmallestElement(arr,left,right,k):
    # If k is smaller than number of  
    # elements in array 
    if (k > 0 and k <= right - left + 1): 
      
        # Partition the array around last  
        # element and get position of pivot 
        # element in sorted array 
        pos = partition(arr, left, right) 
        if (pos - left == k - 1): 
            return arr[pos] 
        if (pos - left > k - 1): # If position is more,  
                              # recur for left subarray 
            return kthSmallestElement(arr, left, pos - 1, k) 
  
        # Else recur for right subarray 
        return kthSmallestElement(arr, pos + 1, right, k - pos + left - 1)
    return "not available"

def basic_solution(arr,left,right,k):
    if (k > 0 and k <= right - left + 1):
        arr = sorted(arr)
        return arr[k-1]
    else:
        return "not available"


if __name__ == "__main__":
    print("Enter the total number of elements")
    left = 0
    right = int(input())
    arr = []
    print("Enter the elements separated by new line")
    for i in range(right):
        arr.append(int(input()))
    k = int(input("Enter the kth smallest element to search: "))
    print("The kth smallest element is  ",kthSmallestElement(arr,left,right-1,k))
    print("The kth smallest element is  ",basic_solution(arr,left,right-1,k))   
