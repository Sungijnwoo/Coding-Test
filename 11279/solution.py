class MaxHeap():
    def __init__(self):
        self.heap_list = [-1]
        self.size = 0
    
    def add(self, number):
        self.size += 1
        self.heap_list.append(number)
        current_index = self.size
        while current_index > 1:
            parent_index = self.get_parent_index(current_index)
            if self.heap_list[parent_index] < self.heap_list[current_index]:
                self.change(parent_index, current_index)
                current_index = parent_index
            else:
                break

    def pop(self):
        if self.size == 0:
            return 0
        self.change(1, self.size)
        max_number = self.heap_list.pop(-1)
        self.size -= 1        
        current_index = 1
        while self.get_left_child_index(current_index) <= len(self.heap_list)-1:
            max_child_index = self.get_max_child(current_index)
            if self.heap_list[current_index-1] < self.heap_list[max_child_index-1]:
                self.change(current_index, max_child_index)
                current_index = max_child_index
        return max_number
    
    def get_max_child(self, index):
        left_child_index = self.get_left_child_index(index)
        right_child_index = self.get_right_child_index(index)
        if right_child_index >= len(self.heap_list):
            return left_child_index
        return left_child_index if self.heap_list[left_child_index] >= self.heap_list[right_child_index] else right_child_index

    def get_parent_index(self, index):
        return index // 2

    def get_left_child_index(self, index):
        return index * 2
    
    def get_right_child_index(self, index):
        return index * 2 + 1
    
    def change(self, parent_index, child_index):
        self.heap_list[parent_index], self.heap_list[child_index] = self.heap_list[child_index], self.heap_list[parent_index]


def main():
    import sys
    q_input = sys.stdin.readline
    N = int(q_input())
    heap = MaxHeap()
    for i in range(N):
        operation = int(q_input())
        if operation:
            heap.add(operation)
        else:
            print(heap.pop())
            


if __name__ == "__main__":
    main()