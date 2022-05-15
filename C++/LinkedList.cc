/*
 * Q:
 * 1.给一个单链表, 判断其中是否有环的存在;
 * 2.如果存在环, 找出环的入口点;
 * 3.如果存在环, 求出环上节点的个数;
 * 4.如果存在环, 求出链表的长度;
 * 5.如果存在环，求出环上距离任意一个节点最远的点（对面节点;
 * 6.（扩展）如何判断两个无环链表是否相交;
 * 7.（扩展）如果相交，求出第一个相交的节点.
 */

/* A 1:快慢指针
 * 定义两个指针fast和slow, 开始时两个指针都指向链表头head
 * 每一步操作中slow每次一步 fast每次两步.
 * 由于fast比slow移动的快,如果有环，fast一定会先进入环，而slow后进入环。
 * 当两个指针都进入环之后，经过一定步的操作之后二者一定能够在环上相遇，并且此时slow还没有绕环一圈
 */ 
typedef struct node
{
    char data;
    node *next;
}Node;

bool ExitLoop(Node *next)
{
    Node *fast, *slow;
    slow = fast = head;

    while (slow != nullptr && fast != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast)
        {
            return true;
        }

        return false;
    }
}

/* A 2:从Q1中可知当fast和slow相遇时, slow还未走完链表,
 * 假设fast已经在环内循环了n(n >= 1)圈, slow走了s步, 则fast走了2s步
 * 又由于fast走过的步数 = s + n * r(s + 在环上多走的n圈), 则:
 * 2 * s = s + n * r;
 * s = n * r
 * 如果假设整个链表的长度是L，入口和相遇点的距离是x，起点到入口点的距离是a，则：
 * a + x = s = n * r; (3)  由（2）推出
 * a + x = (n - 1) * r + r  = (n - 1) * r + (L - a) (4) 由环的长度 = 链表总长度 - 起点到入口点的距离求出
 * a = (n - 1) * r + (L -a -x) (5)
 * 集合式子（5）以及上图我们可以看出，从链表起点head开始到入口点的距离a,与从slow和fast的相遇点到入口点的距离相等.(假设n = 1)
 * 因此我们就可以分别用一个指针（ptr1, prt2），同时从head与slow和fast的相遇点出发，每一次操作走一步，直到ptr1 == ptr2，此时的位置也就是入口点！
 */

Node *FindLoopStart(Node *head)
{
    Node *fast, *slow;
    slow = fast = head;

    while (slow != nullptr && fast -> next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow == nullptr || fast->next == nullptr) return NULL;

    Node *ptr1 = head;
    Node *ptr2 = slow; //相遇点
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1; //找到入口点
}