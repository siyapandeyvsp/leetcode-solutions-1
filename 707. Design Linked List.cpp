#include <iostream>

using namespace std;

class MyLinkedList {

private:
    class Node{
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int val, Node* prev, Node* next): val(val), prev(prev), next(next){}
        Node(int val): Node(val, NULL, NULL){}
    };

    Node* dummyHead;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyHead = new Node(-1);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

        Node* cur = dummyHead->next;
        for(int i = 0; i < index && cur; i ++)
            cur = cur->next;

        if(!cur) return -1;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        dummyHead->next = new Node(val, dummyHead, dummyHead->next);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        Node* pre = dummyHead;
        while(pre->next)
            pre = pre->next;
        pre->next = new Node(val, pre, NULL);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        Node* pre = dummyHead;
        for(int i = 0; i < index && pre; i ++)
            pre = pre->next;

        if(pre)
            pre->next = new Node(val, pre, pre->next);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        Node* pre = dummyHead;
        for(int i = 0; i < index && pre; i ++)
            pre = pre->next;

        if(pre && pre->next){
            Node* delNode = pre->next;
            pre->next = delNode->next;
            if(pre->next)
                pre->next->prev = pre;
            delete delNode;
        }
    }
};


int main() {

    return 0;
}
