def shuffle_array(N, X):
    arr = list(range(1, N+1))
    for i in range(X):
        odd_elems = arr[0::2]
        even_elems = arr[1::2]
        arr = odd_elems + even_elems
    return arr


N, X = map(int, input().split())
result = shuffle_array(N, X)
print(result)
