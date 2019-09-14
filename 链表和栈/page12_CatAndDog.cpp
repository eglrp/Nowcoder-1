#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


queue<int> cat;
queue<int> cat_num;
queue<int> dog;
queue<int> dog_num;


void add(int i)
{
    string kind;
    int number;
    cin >> kind >> number; 

    if (kind == (string)"cat")
    {
        cat.push(number);
        cat_num.push(i);
    }
    else
    {
        dog.push(number);
        dog_num.push(i); 
    }
}

void pollAll()
{
    while (!cat.empty()&&!dog.empty())
    {
        if (cat_num.front()<dog_num.front())
        {
            cout << "cat "<<cat.front()<<endl;
            cat.pop(); cat_num.pop();
        }
        else
        {
            cout << "dog "<<dog.front()<<endl;
            dog.pop(); dog_num.pop();
        }  
    }
    while(!cat.empty())
    {
        cout << "cat "<<cat.front()<<endl;
        cat.pop(); cat_num.pop();       
    }
    while(!dog.empty())
    {
        cout << "dog "<<dog.front()<<endl;
        dog.pop(); dog_num.pop();       
    }   
}
void isEmpty()
{
    string output =(cat.empty()&&dog.empty())?"yes":"no";
    cout << output  << endl;
}

void isCatEmpty()
{
    string output =cat.empty()?"yes":"no";
    cout << output  << endl;
}
void isDogEmpty()
{
    string output = dog.empty()?"yes":"no";
    cout << output  << endl;
}
void pollDog()
{
    while(!dog.empty())
    {
        cout << "dog "<<dog.front()<<endl;
        dog.pop(); dog_num.pop();       
    }   
    
}
void pollCat()
{
    while(!cat.empty())
    {
        cout << "cat "<<cat.front()<<endl;
        cat.pop(); cat_num.pop();       
    }
}
int main()
{

    int n; 
    cin >>n;
    for (int i=0;i<n;i++)
    {
        string order;
        cin >> order;
        if (order == (string) "add") add(i);
        if (order == (string) "pollAll") pollAll();
        if (order == (string) "pollDog") pollDog();
        if (order == (string) "pollCat") pollCat();
        if (order == (string) "isEmpty") isEmpty();
        if (order == (string) "isDogEmpty") isDogEmpty();
        if (order == (string) "isCatEmpty") isCatEmpty();
    }



    return 0;
}