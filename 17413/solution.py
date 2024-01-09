def main():
    S = list(input())
    isOpenBracket = False
    startPoint = 0
    for idx, s in enumerate(S):
        if s == " " and not isOpenBracket:
            word = S[startPoint: idx]
            S[startPoint: idx] = word[::-1]
            startPoint = idx + 1
        elif s == "<" and not isOpenBracket:
            isOpenBracket = True
            word = S[startPoint: idx]
            S[startPoint: idx] = word[::-1]
        elif s == ">" and isOpenBracket:
            isOpenBracket = False
            startPoint = idx + 1
    
    if startPoint != len(S):
        word = S[startPoint:]
        S[startPoint:] = word[::-1]

    result = "".join(S)
    print(result)

if __name__ == "__main__":
    main()
