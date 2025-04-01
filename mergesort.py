def merge(left, right):
    sorted_arr = []
    i = j = 0

    # Merge two sorted lists
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_arr.append(left[i])
            i += 1
        else:
            sorted_arr.append(right[j])
            j += 1

    # Append remaining elements
    sorted_arr.extend(left[i:])
    sorted_arr.extend(right[j:])

    return sorted_arr

def merge_sort(arr):
    if len(arr) <= 1:
        return arr  # Base case: already sorted

    # Split the array into halves
    mid = len(arr) // 2
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])

    # Merge the sorted halves
    return merge(left_half, right_half)

# Example Usage
arr = [5, 2, 9, 1, 5, 6]
sorted_arr = merge_sort(arr)
print(sorted_arr)  # Output: [1, 2, 5, 5, 6, 9]