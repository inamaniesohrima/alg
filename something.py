def merge_sort_iterative_solution(arr, n):
 total_inv = 0
 width = 1
 while width < n:
  for left in range(0, n, 2 * width):
   mid = min(left + width, n)
   right = min(left + 2 * width, n)
   inv, merged = merge_two(arr, left, mid, right)
   total_inv += inv
   arr[left:right] = merged
  width *= 2
 return total_inv


def merge_two(arr, left, mid, right):
 i = left
 j = mid
 merged = []
 inv = 0
 nL = mid - left
 suff = [0] * (nL + 1)
 s_val = 0
 for k in range(mid - 1, left - 1, -1):
  s_val += arr[k][1]
  suff[k - left] = s_val
 while i < mid and j < right:
  if arr[i][0] <= arr[j][0]:
   merged.append(arr[i])
   i += 1
  else:
   count = mid - i
   inv += arr[j][1] * count - suff[i - left]
   merged.append(arr[j])
   j += 1
 while i < mid:
  merged.append(arr[i])
  i += 1
 while j < right:
  merged.append(arr[j])
  j += 1
 return inv, merged

# data = inputs.split()
# n = int(data[0])
# arr = [(int(data[i]), i) for i in range(1, n + 1)]

n = int(input())
arr = list(map(int, input().split())) 
arr = [(arr[i], i) for i in range(n)]
 
print(merge_sort_iterative_solution(arr, n))