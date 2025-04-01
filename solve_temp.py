def solve(arr):
    indexed_arr = []
    for i in range(len(arr)):
        indexed_arr.append((arr[i], i))

    _, diff_sum = mergesort(indexed_arr)
    return diff_sum

def mergesort(indexed_arr):
    if len(indexed_arr) <= 1:
        return indexed_arr, 0

    mid = len(indexed_arr) // 2
    left = indexed_arr[:mid]
    right = indexed_arr[mid:]

    left_sorted, left_sum = mergesort(left)
    right_sorted, right_sum = mergesort(right)

    merged, split_sum = merge(left_sorted, right_sorted)

    total_sum = left_sum + right_sum + split_sum
    return merged, total_sum

def merge(left, right):
    merged = []
    diff_sum = 0
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i][0] <= right[j][0]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            # Count differences:
            for k in range(i, len(left)):
                if left[k][1] < right[j][1]:
                    diff_sum += left[k][0] - right[j][0]
            j += 1

    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged, diff_sum

arr = [5, 4, 3, 2, 1]
# arr = [2, 4, 3, 5, 1]
print(solve(arr))