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
ListNode* findKNode(ListNode* head, int k){
    ListNode* temp=head;
    k--;
    while(temp!=NULL && k!=0){
        k--;
        temp=temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)return head;
        int len=1;
        ListNode* Tail=head;
        while(Tail->next!=NULL){
            len++;
            Tail=Tail->next;
        }
        if(k%len==0)return head;
        k=k%len;
        ListNode* kNode=findKNode(head,len-k);
        Tail->next=head;
        head=kNode->next;
        kNode->next=nullptr;
        return head;
    }
};