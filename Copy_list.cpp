#include<iostream> 
#include<unordered_map> 

using namespace std; 

class Node{
public: 
     int val; 
     Node* next; 
     Node* random; 
     Node(int _val): val(_val), next(NULL), random(NULL){}
};
class Solution{
public: 
      Node* copyRandomList(Node* head){
        if(head==NULL) return NULL; 
        unordered_map<Node*, Node*> mp; 
        Node* curr = head; 
        while(curr){
          mp[curr] = new Node(curr->val); 
          curr = curr->next; 
        }
        curr = head; 
        while(curr){
          mp[curr]->next = mp[curr->next]; 
          mp[curr]->random = mp[curr->random]; 
          curr = curr->next; 
        }
        return mp[head]; 
      }
};
void printList(Node* head){
    Node* curr = head;
    while (curr) {
        cout << "Node val: " << curr->val;
        if (curr->random)
            cout << ", Random points to: " << curr->random->val << endl;
        else
            cout << ", Random points to: null" << endl;
        curr = curr->next;
    }
}
int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    // Link next pointers
    node1->next = node2;
    node2->next = node3;

    // Link random pointers
    node1->random = node3; // 1 -> 3
    node2->random = node1; // 2 -> 1
    node3->random = node3; // 3 -> 
    cout << "Original list:" << endl;
    printList(node1);

    // Make a deep copy
    Solution sol;
    Node* copiedHead = sol.copyRandomList(node1);

    cout << "\nCopied list:" << endl;
    printList(copiedHead);
    return 0; 
}
