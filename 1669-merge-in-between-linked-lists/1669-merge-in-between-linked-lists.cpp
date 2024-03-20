class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(!list2) return list1;
        ListNode* prev=nullptr;
        ListNode* start=list1;
        ListNode* end=list1;
        int d=b-a;
        while (end!=nullptr && d--) {
            end=end->next;
        }
        while (start!=nullptr && end!=nullptr && a--) {
            prev=start;
            start=start->next;
            end=end->next;
        }
        
        ListNode* end2=list2;
        while(end2->next!=nullptr)
            end2=end2->next;
        
        prev->next=list2;
        
        
        end2->next=end->next;
        end->next=nullptr;
        cout<<prev->val<<" "<<start->val<<" "<<end->val<<" "<<end2->val<<endl;
        
        return list1;
    }
};
