//Problem link: https://takeuforward.org/plus/dsa/problems/search-in-linked-list

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        
        ListNode* temp = head;

        while(temp != NULL) {
            if(temp->val == key) return true;
            temp = temp->next;
        }

        return false;
    }
};