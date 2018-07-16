  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        ListNode* result_node;
        ListNode* pre_node=result_node;
        do {
            int val = l1->val + l2->val + up;
            int node_val = val % 10;
            up = val / 10;
            ListNode* next_node = new ListNode(node_val);
            pre_node->next = next_node;
            pre_node = next_node;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 == nullptr || l2 == nullptr)
                break;
        } while(true);
        if(l1 == nullptr && l2 == nullptr) {
        }
        else if(l1 == nullptr) {
            do {
                int val = l2->val + up;
                int node_val = val % 10;
                up = val/10;
                ListNode* next_node = new ListNode(node_val);
                pre_node->next = next_node;
                pre_node = next_node;
                l2 = l2->next;
                if(l2 == nullptr)
                    break;
            } while(true);
        }
        else {
            do {
                int val = l1->val + up;
                int node_val = val % 10;
                up = val/10;
                ListNode* next_node = new ListNode(node_val);
                pre_node->next = next_node;
                pre_node = next_node;
                l1 = l1->next;
                if(l1 == nullptr)
                    break;
            } while(true);
        }
         if(up != 0) {
                ListNode* next_node = new ListNode(up);
                pre_node->next = next_node;
        }

        return result_node->next;
    }
};

int main() {
    return 0;
}
