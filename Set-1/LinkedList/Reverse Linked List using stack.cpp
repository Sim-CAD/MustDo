  //Problem Name: Reverse a linked list using stack
 //Source : GeeksForGeeks
 /****************************************/
struct Node* reverseList(struct Node *head)
{
          Node *curr = head;
          stack<Node*>st;
          
          while(curr){
              st.push(curr);
              curr = curr->next;
          }
          
          Node *tmp = st.top();
          head = tmp;
          st.pop();
          
          while(!st.empty()){
              tmp->next = st.top();
              st.pop();
              tmp = tmp->next;
          }
         tmp->next = NULL;
         return head;
}