def main():
    N = int(input())
    A = list(map(int, input().split(" ")))
    M = int(input())
    L = list(map(int, input().split(" ")))

    A.sort()

    sorted_L = sorted(L)

    result = {i: 0 for i in L}
    A_idx = 0
    for number in sorted_L:
        while True:
            if A_idx == len(A):
                break
            elif number == A[A_idx]:
                result[number] = 1
                break
            elif number < A[A_idx]:
                break
            elif number > A[A_idx]:
                A_idx += 1
            
    for i in L:
        print(result[i])
if __name__ == "__main__":
    main()