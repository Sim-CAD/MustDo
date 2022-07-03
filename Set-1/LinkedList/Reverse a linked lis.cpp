  //Problem Name: Reverse a linked lis
 //Source : GeeksForGeeks
 /****************************************/
 struct Node* reverseList(struct Node *head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next_node = NULL;
        
        while(curr){
            next_node = curr->next;
            curr->next = prev;
            //Update the pointers
            prev = curr;
            curr = next_node;
        }
        return prev;
    }