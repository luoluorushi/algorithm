  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head_node = new ListNode(0);
        ListNode* pre_node=head_node;
        while (l1 != nullptr && l2 != nullptr) {
            carry = l1->val + l2->val + carry;
            int node_val = carry % 10;
            carry = carry / 10;
            l1 = l1->next;
            l2 = l2->next;
            pre_node->next = new ListNode(node_val);
            pre_node = pre_node->next;
        };
        if(l1 == nullptr && l2 == nullptr) {
        }
        else if(l1 == nullptr) {
            while(l2 != nullptr) {
                carry = l2->val + carry;
                int node_val = carry % 10;
                carry = carry/10;
                l2 = l2->next;
                pre_node->next = new ListNode(node_val);
                pre_node = pre_node->next;
            };
        }
        else {
            while(l1 != nullptr) {
                carry = l1->val + carry;
                int node_val =  carry % 10;
                carry = carry/10;
                l1 = l1->next;
                pre_node->next = new ListNode(node_val);
                pre_node = pre_node->next;
            };
        }
         if(carry != 0) {
                pre_node->next = new ListNode(carry);
        }

        return head_node->next;
    }
};

int main() {
    return 0;
}
