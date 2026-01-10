class Solution {
public:
    int intersectPoint(Node* head1, Node* head2) {
        Node* t1 = head1;
        Node* t2 = head2;

        while (t1 != t2) {
            t1 = (t1 == NULL) ? head2 : t1->next;
            t2 = (t2 == NULL) ? head1 : t2->next;
        }

        return t1->data;  // intersection node
    }
};
