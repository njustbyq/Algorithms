"""
如何实现链表的逆序
"""
class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

class SingleLink:
    def __init__(self, head):
        self.head = head


def reverse(link: SingleLink):
    if link.head is None or link.head.next is None:
        return None
    cur = link.head.next  # cur指向第一个结点
    pre = link.head  # pre指向头结点
    while cur.next is not None:  # 如果cur不是最后一个结点
        ne = cur.next  # ne记住当前结点的下一个结点
        if pre != link.head:  # 如果cur不是第一个结点
            cur.next = pre  # 把当前结点的next指向前一个结点
        else:
            cur.next = None
        pre = cur  # pre结点后移到当前结点
        cur = ne  # 当前结点后移一位
        ne = ne.next  # ne结点后移一位
    # cur指向tail了
    cur.next = pre  # 当cur指向了最后一个结点，循环结束，把最后一个结点指向倒数第二个结点
    link.head.next = cur  # head指向最后一个结点，即cur


if __name__ == "__main__":
    i = 1
    tmp = Node(i, None)
    head = Node(None, tmp)
    while i < 8:
        tmp.next = Node(i, None)
        tmp = tmp.next
        i += 1
    print("正序是: ", end="")
    cur = head
    while cur.next is not None:
        cur = cur.next
        print(cur.data, end=" ")
    print()
    link1 = SingleLink(head)
    reverse(link1)
    print("逆序是: ", end="")
    cur = link1.head
    while cur.next is not None:
        cur = cur.next
        print(cur.data, end=" ")
