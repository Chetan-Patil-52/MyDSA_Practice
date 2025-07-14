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

    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* last = reverseLL(head->next);

        head->next->next = head;
        head->next = NULL;

        return last;
    }

    int getDecimalValue(ListNode* head) {
        head = reverseLL(head);

        int power = 0;
        int result = 0;

        while(head != NULL){
            if(head->val == 1){
                result += pow(2,power);
            }
            head = head->next;
            power++;
        }

        return result;
    }
};

// BM
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
    int getDecimalValue(ListNode* head) {
        
        int result = 0;

        while(head){
            result = (result<<1) | (head->val);
            head = head->next;
        }

        return result;
    }
};
