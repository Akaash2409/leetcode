/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(!root)return root;
       Node * temp=NULL;
       Node *fi=root;
       while(fi && !temp)
       {
       if(fi->next)
        {
          if(fi->next->left)
          temp= fi->next->left;
          else 
          temp= fi->next->right;
        }
       fi=fi->next;
       }

       if(root->left && root->right)
       {
           root->left->next= root->right;
           root->right->next=temp;
       } 
       else 
       {

           if(root->left)
           {
               root->left->next=temp;
           }else
           {   if(root->right)
               root->right->next=temp;
           }
       }
       connect(root->right);
       connect(root->left);
       
       return root;
    }
    
};