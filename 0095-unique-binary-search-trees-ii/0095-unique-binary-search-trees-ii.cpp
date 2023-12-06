class Solution {
public:
    TreeNode* changeVal(TreeNode *root,int i){
        if(root==NULL)
            return root;

        // root->val+=i;
        // if we change the value in original tree then later we will have problem in next call
        // eg if i=3 and the val of root=1;
        // if we make it 1+3=4
        // then it will be updated for all the trees later as 4

        // instead make a new tree with updated values
        TreeNode *newRoot=new TreeNode(root->val+i);
        newRoot->right=changeVal(root->right,i);
        newRoot->left=changeVal(root->left,i);
        return newRoot;
    }
    vector<TreeNode*> f(int n, vector<TreeNode*> dp[]){
        if(n==0){
            return {NULL};
        }
        if(dp[n].size()!=0){
            return dp[n];
        }
        vector<TreeNode*> ans;
        // we choose every node one by one to be the root and attach the left and right subtrees to it
        // if we choose i to be root then we have i-1 nodes in left and n-i nodes in right 

        for(int i=1;i<=n;i++){
            vector<TreeNode*> left=f(i-1,dp);
            vector<TreeNode*> right=f(n-i,dp);
            // the structure of right will be correct 
            // but the values in it will be from 1 to n-i
            // so just increase the value of each node by i in right subtree
            vector<TreeNode*> newRight;
            for(int ind=0;ind<right.size();ind++){
                TreeNode* node=right[ind];
                node=changeVal(node,i);
                newRight.push_back(node);
            }


            for(int ind1=0;ind1<left.size();ind1++){
                for(int ind2=0;ind2<right.size();ind2++){

                    TreeNode *root=new TreeNode(i);
                    root->left=left[ind1];
                    root->right=newRight[ind2];
                    
                    ans.push_back(root);

                }
            }
            
        }
        return dp[n]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[n+1];
        return f(n,dp);
    }
};