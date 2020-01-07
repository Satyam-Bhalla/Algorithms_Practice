def linear_search(lst,n,x):
    if x in lst:
        return lst.index(x)
    return -1



if __name__ == "__main__":
    print("Enter the total number of elements")
    n = int(input())
    lst = []
    print("Enter the elements separated by new line")
    for i in range(n):
        lst.append(int(input()))
    x = int(input("Enter the element to search: "))
    print(linear_search(lst,n,x))
