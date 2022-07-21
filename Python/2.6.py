"""
如何用两个栈模拟队列操作
"""

class Stack:
    # 模拟栈
    def __init__(self):
        self.items = []
    # 判断栈是否为空
    def empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)
    
    def peek(self):
        if not self.empty():
            return self.items[len(self.items) - 1]
        else:
            return None
    
    def pop(self):
        if len(self.items) > 0:
            return self.items.pop()
        else:
            print("Empty Stack!")
            return None

    def push(self, item):
        self.items.append(item)

class MyStack:
    def __init__(self):
        self.A = Stack()
        self.B = Stack()
    
    def push(self, data):
        self.A.push(data)

    def pop(self):
        if self.B.empty():
            while not self.A.empty():
                self.B.push(self.A.peek())
                self.A.pop()
        first = self.B.peek()
        self.B.pop()
        return first

if __name__=="__main__":
    stack = MyStack()
    stack.push(1)
    stack.push(2)
    print("队列首元素为: " + str(stack.pop()))
    print("队列首元素为: " + str(stack.pop()))
