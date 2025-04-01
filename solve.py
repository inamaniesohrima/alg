
def merge_and_count(arr, temp, left, mid, right):
    print("start merge arr:", arr, "left:", left, "mid:", mid, "right:", right)
    print("start merge temp:", temp)
    i, j, k = left, mid + 1, left
    inv_count = 0
    
    while i <= mid and j <= right:
        if arr[i] > arr[j]:  # Count inversions: arr[i] > arr[j]
            inv_count += (mid - i + 1) * abs(i - j)
            # inv_count += (mid - i + 1) * (((mid + i) // 2) + (j - mid)) 
            temp[k] = arr[j]
            j += 1
        else:
            temp[k] = arr[i]
            i += 1
        k += 1

    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1

    for i in range(left, right + 1):
        arr[i] = temp[i]

    print("end merge arr:", arr)
    print("end merge temp:", temp)
    print('inv count', inv_count)
 
    return inv_count

def merge_sort_and_count(arr, temp, left, right):
    print("merge called", "left:", left, "right:", right)
    if left >= right:
        return 0

    mid = (left + right) // 2
    inv_count = merge_sort_and_count(arr, temp, left, mid)
    inv_count += merge_sort_and_count(arr, temp, mid + 1, right)
    inv_count += merge_and_count(arr, temp, left, mid, right)

    return inv_count

def solve():
    n = int(input("Enter n: "))
    arr = input(f"Enter 1 to {n} in any order: ").split(" ")
    temp = arr[:]
    result = merge_sort_and_count(arr, temp, 0, n - 1)
    print(arr)
    print(result)

solve()