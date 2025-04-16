// Problem 1: Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;        
    }
};

// Problem 2: Remove Duplicates from Sorted List II
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy ;
        prev->next = head;
        while(temp!=nullptr&&temp->next!=nullptr){
            if(temp->next->val==temp->val){
                int v = temp->val;
                while(temp!=nullptr){
                    if(temp->val==v)temp = temp->next;
                    else break ;
                }
                prev->next = temp;
            }
            else{
                prev = temp ;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};

// 
