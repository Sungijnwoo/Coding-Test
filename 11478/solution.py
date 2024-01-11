def main():
    S = input()
    subStringList = []
    for i in range(1, len(S)+1):
        for j in range(len(S) - i + 1):
            subString = S[j: j+i]
            subStringList.append(subString)
    subStringSet = set(subStringList)
    print(len(subStringSet))
    

if __name__ == "__main__":
    main()


