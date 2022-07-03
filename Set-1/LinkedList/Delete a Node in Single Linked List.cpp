//Problem Name: Delete a Node in Single Linked List
 //Source : GeeksForGeeks
 /****************************************/
Node* deleteNode(Node *head,int x)
{
   if(head == NULL) return head;
    
   if(x == 1) {
       return head->next;
   }
   
    Node* curr = head;
    int i ;
    for( i = 1; (i <= x - 2 && curr != NULL); i++){
       curr = curr->next; 
    }
     
    if(curr == NULL)
        return head;
    
    curr->next = curr->next->next;
    return head;
}