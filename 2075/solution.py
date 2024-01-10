import heapq

def main():
    heap = []
    N = int(input())
    for _ in range(N):
        numbers = map(int, input().split())
        for number in numbers:
            if len(heap) < N:
                heapq.heappush(heap, number)
            else:
                if heap[0] < number:
                    heapq.heappop(heap)
                    heapq.heappush(heap, number)
    print(heap[0])    
    
if __name__ == "__main__":
    main()