// PRoblem link: https://takeuforward.org/plus/dsa/problems/find-the-length-of-the-linked-list

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        
        ListNode* temp = head;
        int l = 0;

        while(temp != NULL) {
            l++;
            temp = temp->next;
        }

        return l;
    }
};