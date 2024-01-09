# if <a: int> in <b: list> 로 풀게 되면 O(n^2)
# dictionary 로 만들고 if <b: dict>.get(<a: int>) 로 풀게 되면 O(2n)

def main():
    N = int(input())
    sangGeun = {i: 1 for i in list(map(int, input().split(" ")))}
    M = int(input())
    nominates = list(map(int, input().split(" ")))
    
    result = []
    for nominate in nominates:
        if sangGeun.get(nominate):
            result.append("1")
        else:
            result.append("0")
    
    print(" ".join(result))


if __name__ == "__main__":
    main()