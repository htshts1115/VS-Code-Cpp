#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

//83 Remove Duplicates from Sorted List
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head; 
        while (cur && cur->next){
            if (cur->val == cur->next->val){
                ListNode* temp = cur->next->next;
                delete cur->next;
                cur->next = temp;
            }
            else cur = cur->next;
        }
        return head;
    }
};

