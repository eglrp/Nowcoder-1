#include <iostream>
#include <map>
#include <cstdio>
#include <stack> //preorder 要用到.
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {} //结构体初始化方法
};

TreeNode *get_node(map<int, TreeNode *> &a, int val) //对stl的变量都需要&才能在外部改变
{
    if (val == 0)
        return NULL;
    if (a.find(val) == a.end()) //map找不到就返回end()迭代器
    {
        a[val] = new TreeNode(val); //new 表示开辟一个新空间, 返回指针
    }
    return a[val];
}

void preorder_recursion(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder_recursion(root->left);
    preorder_recursion(root->right);
}
void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s1;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top(); s1.pop(); //拿出第一个
        cout << root->val << " "; //输出
        if (root->left != NULL)
            s1.push(root->right);
        if (root->right != NULL)
            s1.push(root->left); // 因为下一次要让left先出来,因此left后放.
    }
}


void inorder_recursion(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_recursion(root->left);
    cout << root->val << " ";
    inorder_recursion(root->right);
}
void inorder(TreeNode *root)
{   //中序遍历 左中右, 叶子节点左为NULL,打印中间val,然后再换到右边节点
    //仍然利用stack的特性, 先遍历left节点,存入stack, 然后一个一个抛出
    //抛出的节点答应.再探索其右节点cur->right, 再对right节点重复上述过程即可.
    if (root == NULL)
        return;
    stack<TreeNode *> s1;
    while (!s1.empty() || root!=NULL) //中间状态stack可能为空,root不为空
    {
        if (root != NULL) //一直压入左节点
        {
            s1.push(root);
            root = root->left; //指针变量的改变.
        }
        else
        {   //很巧妙的一点就是s1.pop()的节点只会找right, 而当前节点只会找left,两者互不干扰.
            root = s1.top();s1.pop(); 
            cout << root->val << " "; 
            root = root->right;
        }
    }
}

void postorder_recursion(TreeNode* root)
{
    if (root ==NULL) return;
    postorder_recursion(root->left);
    postorder_recursion(root->right);
    cout<<root->val<<" ";
}
void postorder(TreeNode* root)
{
    //原理也很简单, 后续遍历左右中, 第一个栈存左, 第二个栈存中右//
    //s1.pop的节点都依次存入s2中, s2就是后续遍历
    if (root ==NULL) return ;
    stack<TreeNode*> s1,s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top(); s2.push(root); s1.pop(); //一气呵成.
        if (root->left!=NULL) s1.push(root->left);
        if(root->right!=NULL) s1.push(root->right); //这样一来肯定是right先pop出来
    }
    while (!s2.empty())
    {
        cout << s2.top()->val<<" ";
        s2.pop();
    }
}


int main()
{
    TreeNode *root = NULL;
    int n, t;
    map<int, TreeNode *> treemap;
    cin >> n >> t;

    root = new TreeNode(t); //对指针变量指向新的地址.
    treemap[t] = root;      //进行索引, map很好用
    int fa, l1, r1;
    for (int i = 0; i < n; i++)
    {
        cin >> fa >> l1 >> r1;
        get_node(treemap, fa)->left = get_node(treemap, l1); //get 即是索引又是新建
        get_node(treemap, fa)->right = get_node(treemap, r1);
    }
    //新建完成. 开始遍历
    cout << "preorder_recursion: ";
    preorder_recursion(root);
    cout << endl  << "preorder_not_recursion: ";
    preorder(root);
    cout << endl  << "inorder_recursion: ";
    inorder_recursion(root);
    cout << endl  << "inorder_not_recursion: ";
    inorder(root);
    cout << endl << "postorder_recursion: ";
    postorder_recursion(root);
    cout << endl << "postorder_not_recursion: ";
    postorder(root); 
    return 0;
}