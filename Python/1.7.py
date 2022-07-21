"""
如何把链表相邻元素翻转
"""
class LNode:
    def __init__(self, x):
        self.data = x
        self.next = None
    

def reverse(head):
    if head == None or head.next == None:
        return 
    
    cur = head.next
    pre = head
    next = None

    while cur != None and cur.next != None:
        next = cur.next.next
        pre.next = cur.next
        cur.next.next = cur
        cur.next = next
        pre = cur
        cur = next

if __name__ == "__main__":
    i = 1
    head = LNode(i)
    head.next = None
    tmp = None
    cur = head
    while i < 8:
        tmp = LNode(i)
        tmp.data = i
        tmp.next = None
        cur.next = tmp
        cur = tmp
        i += 1
    cur = head.next
    while cur != None:
        print(cur.data,end=' ')
        cur = cur.next
    print('\n')
    reverse(head)
    cur = head.next
    while cur != None:
        print(cur.data,end=' ')
        cur = cur.next