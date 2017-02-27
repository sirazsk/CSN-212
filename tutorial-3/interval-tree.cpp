#include <iostream>
using namespace std;

struct Interval
{
    int low, high;
};
struct ITNode
{
    Interval *i;  
    int max;
    ITNode *left, *right;
};
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
};
ITNode *minValueNode(ITNode *root)
{
    ITNode *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
} 
ITNode *insert(ITNode *root, Interval i)
{
    if (root == NULL)
        return newNode(i);
    int l = root->i->low;
 
    if (i.low < l)
        root->left = insert(root->left, i);
 
    else
        root->right = insert(root->right, i);
 
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}
 
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
 
void overlapSearch(ITNode *root, Interval i)
{
    if (root == NULL) return ;
 
    if (doOVerlap(*(root->i), i))
    {
        cout << "Overlaps with [" << root->i->low << ", " << root->i->high << "]\n";
    }
 
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
 
    return overlapSearch(root->right, i);
}

int maximum(int a,int b,int c)
{
    if(a>=b&&a>=c)
        return a;
    if(b>=a&&b>=c)
        return b;
    return c;
}

int maximum(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void updateMax(ITNode*root)
{
    if(root==NULL)
        return ;
    updateMax(root->left);
    updateMax(root->right);
    if(root->left==NULL&&root->right==NULL)
        root->max=root->i->high;

    else if(root->left==NULL)
    {
        root->max=maximum(root->i->high,root->right->max);
    } 
    else if(root->right==NULL)
    {
        root->max=maximum(root->i->high,root->left->max);
    }
    else
    root->max=maximum(root->i->high,root->right->max,root->left->max);
}

ITNode *deleteNode(ITNode *root,Interval x)
{
    if(root==NULL)
        return root;
    if(x.low<root->i->low)
        root->left=deleteNode(root->left,x);
    else if(x.low<root->i->low)
        root->right=deleteNode(root->right,x);

    else
    {
        if(root->left==NULL)
        {
            ITNode *temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            ITNode *temp=root->left;
            delete(root);
            return temp;
        }
        ITNode *temp=minValueNode(root->right);
        root->i=temp->i;
        Interval k={temp->i->low,temp->i->high};
        root->right=deleteNode(root->right,k);
    }
    return root;
}  
void inorder(ITNode *root)
{
    if (root == NULL) return;
 
    inorder(root->left);
 
    cout << "[" << root->i->low << ", " << root->i->high << "]"
         << " max = " << root->max << endl;
 
    inorder(root->right);
}
 
void delete_Interval(ITNode *root,Interval y)
{
    root=deleteNode(root,y);
    updateMax(root);
}

int main()
{
    int n;
    cin>>n;
    Interval a[n]; 
    for(int i=0;i<n;i++)
    {
        Interval x;
        cin>>x.low>>x.high;
        a[i]=x;
    }
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, a[i]);
    cout << "Inorder traversal of constructed Interval Tree is\n";
    inorder(root);
    int q;
    cin>>q;
    while(q--)
    {
        Interval x;
        cin>>x.low>>x.high;
        cout << "\nSearching for interval [" << x.low << "," << x.high << "]\n";
        overlapSearch(root, x);
    }  
    int d;
    cin>>d;
    while(d--)
    {
        Interval y;
        cin>>y.low>>y.high;
        delete_Interval(root,y);
        cout<<"\nInorder traversal after deleting ["<<y.low<<","<<y.high<<"] is\n";
        inorder(root);
    }
    return 0;
}
