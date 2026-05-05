/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // function for finding list length
    int listlength(ListNode* head)
    {
        int len = 1;
        ListNode* temp = head;
        while(temp->next!= nullptr)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int len = listlength(head);
        k = k % len;

        if (k == 0) return head;
        
        
        // last element pointer should point to head "make it circular"
        ListNode* temp = head;
        while(temp->next!= nullptr)
        {
            temp = temp->next;
        }
        temp->next = head;

        // move to new tail (len - k steps)
        int steps = len-k;
        ListNode* newTail = head;
        for(int i = 1;i< steps; i++)
        {
            newTail = newTail->next;
        }
        
        // new head
        head =  newTail->next;
        // break circuler
        newTail->next = nullptr;

        return head;
    }
};
