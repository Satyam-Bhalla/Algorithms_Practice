def binary_search_recursion(lst,left,right,x):
    
    if right>=left:
        mid = int(left + (right-left)/2)
        if lst[mid] == x:
            return mid
        elif lst[mid] > x:
            return binary_search_recursion(lst,left,mid-1,x)
        elif lst[mid] < x:
            return binary_search_recursion(lst,mid+1,right,x)
    else:
        return -1
    

def binary_search_loop(lst,left,right,x):
    mid = 0
    while True:
        if left<=right:
            mid = left + int((right-left)/2)
            if lst[mid]==x:
                return mid
            elif lst[mid]>x:
                right=mid-1
            elif lst[mid]<x:
                left=mid+1
        else:
            return -1

if __name__ == "__main__":
    print("Enter the total number of elements")
    left = 0
    right = int(input())
    lst = []
    print("Enter the elements separated by new line")
    for i in range(right):
        lst.append(int(input()))
    x = int(input("Enter the element to search: "))
    print("The element is available at ",binary_search_recursion(lst,left,right-1,x))
    print("The element is available at ",binary_search_loop(lst,left,right-1,x))
