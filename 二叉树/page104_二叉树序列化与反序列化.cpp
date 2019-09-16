#include <queue>
#include <string> 
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a): val(a),left(NULL),right(NULL) {}
};

class Solution{
    public:
    char* Serialize(TreeNode* root)
    {
        char* temp;
        strcpy(temp,(pre_serialize(root)).c_str());
        return temp;
    }
    string pre_serialize(TreeNode* root)
    {
        string a;
        stringstream ss;
        if (root==NULL) 
        {
            a = a+"#!";
            return a;
        }
        ss << root->val <<"!";
        //常规操作后, 开始递归
        ss >> a; 
        a = a + pre_serialize(root->left);
        a = a + pre_serialize(root->right);
        return a;

    }
    TreeNode* Deserialize(char* str)
    {  //先序反序列化
        queue<string> qs = get_nums(str);  //得到序列的数组
        return recon_preorder(qs);
    }
    TreeNode* recon_preorder(queue<string> &qs) //引用
    {
        string temp = qs.front(); qs.pop();
        if (temp[0]=='#') return NULL;
        TreeNode* head =  new TreeNode(atoi(temp.c_str()));
        head->left = recon_preorder(qs);
        head->right = recon_preorder(qs);
        return head;
    }
    queue<string> get_nums(char* str)
    {
        queue<string> ans;
        int left=-1, right =0;
        string temp = str; 

        for(right=0;right<temp.size();right++)
        {
             //cpp就是高级, 直接转
            if (temp[right] == '!')
            {
                ans.push(temp.substr(left+1,right-left-1)); //pos+个数
                left = right;
            }
        }
        return ans;
    }
};

int main()
{
    string a = "12!3!#!#!#!";
    Solution solu;
    char *temp;
    strcpy(temp,a.c_str()); //const char* to char* 不错的函数
    cout << temp<<endl;
    TreeNode* root = solu.Deserialize(temp);
    char* str = solu.Serialize(root);
    cout << str <<endl; 
    return 0;
}