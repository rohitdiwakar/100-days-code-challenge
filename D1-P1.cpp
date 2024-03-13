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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        unordered_map<int,ListNode*>mp;

        dummy->next=head;
        int prefixsum=0;
        mp[0]=dummy;
        while(head!=nullptr){
             prefixsum+=head->val;
           
             if(mp.find(prefixsum)!=mp.end()){
                  ListNode* start=mp[prefixsum];
                  
                    int sum=prefixsum;
                  while(start!=nullptr &&start!=head){
                    
                    start=start->next;
                    sum+=start->val;
                    if(start!=head)
                    mp.erase(sum);
                  }

                  mp[prefixsum]->next=head->next;
             }
             else{
                mp[prefixsum]=head;
             }
             head=head->next;
        }
        return dummy->next;
    }
};