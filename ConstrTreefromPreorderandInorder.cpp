#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
BinaryTreeNode<int>*helper(int *preorder,int prest ,int preend, int *inorder, int inst,int inend)
{
    if(prest>preend||inst>inend)
    {
        return NULL ;
    }
    
    int idx=-1 ;
    int rootdata=preorder[prest];
    for(int i=inst;i<=inend;i++)
    {
        if(rootdata==inorder[i])
        {
            idx=i ;
            break ;
        }
    }
    
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
        
    
    int linst=inst ;
    int linend=idx-1 ;
    int lprest=prest+1 ;
    int lpreend=linend-linst+lprest;
    int rinst=idx+1;
    int rpreend=preend ;
    int rinend=inend;
    int rprest=lpreend+1 ;
    
    
    root->left=helper(preorder,lprest,lpreend,inorder,linst,linend);
    root->right=helper(preorder,rprest,rpreend,inorder,rinst,rinend);
    
    return root ;
    
    
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>*root=helper(preorder,0,preLength-1,inorder,0,inLength-1);
    return root ;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}