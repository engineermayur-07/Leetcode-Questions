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
    bool isPalindrome(ListNode* head) {
        vector <int> queue ;
        int rear = -1 ;
        int front = 0 ;
        ListNode * temp = head ;
        while( temp != NULL){
            rear++ ;
            queue.push_back(temp->val) ;
            temp = temp->next ;
        }
        while( front <= rear ){
            if( queue[front] != queue[rear] ) return false ;
            front++ ;
            rear-- ;
        }
        return true ;
    }
};