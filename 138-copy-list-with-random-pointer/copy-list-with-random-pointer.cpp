class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> mp;

        Node* current = head;

        while (current != nullptr) {
            mp[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        while (current != nullptr) {
            mp[current]->next = mp[current->next];
            mp[current]->random = mp[current->random];
            current = current->next;
        }

        return mp[head];
    }
};