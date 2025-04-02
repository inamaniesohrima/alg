def solve(arr):
    res = {}
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            a = find_a(arr[i][0], arr[i][1], arr[j][0], arr[j][1])
            b1 = find_b(arr[i][0], arr[i][1], a)
            b2 = find_b(arr[j][0], arr[j][1], a)
            if(b1 == b2):
                if((a, b1) in res):
                    if(arr[i] not in res[(a , b1)]):
                        res[(a , b1)].append(arr[i])
                    if(arr[j] not in res[(a , b1)]):
                        res[(a , b1)].append(arr[j])
                else:
                    res[(a , b1)] = [arr[i], arr[j]]
    return max([len(res[i]) for i in res])

def find_a(x1, y1, x2, y2):
    if x1 == x2: return -1
    return  abs(y1 - y2) / abs(x1 - x2) 
def find_b(x1, y1, a):
    if(a == -1): return x1
    return y1 - a * x1

n = int(input())
arr = []

for i in range(n):
    t = list(map(int, input().split()))
    arr.append((t[0], t[1]))

print(solve(arr))
