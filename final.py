def mergesort(arr, left, right):
 if right - left <= 1:
  return 0
 mid = (left + right) // 2
 inv = mergesort(arr, left, mid)
 inv += mergesort(arr, mid, right)
 inv2, merged = merge(arr, left, mid, right)
 arr[left:right] = merged
 return inv + inv2

def merge(arr, left, mid, right):
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

n = int(input())
arr = list(map(int, input().split())) 
arr = [(arr[i], i) for i in range(n)]
 
print(mergesort(arr, 0, n))