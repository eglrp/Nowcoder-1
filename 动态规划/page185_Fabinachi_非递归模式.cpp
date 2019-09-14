#include <iostream>

using namespace std;


int main()
{

    int n; 
    cin >> n;
    if (n<3)
    {
        cout <<1;
        return 0;
    }
    int pre1=1, temp, ans = 1;
    for (n-=2;n>0;n--)
    {
        temp = ans;
        ans = ans + pre1;
        pre1 = temp; 
    }
    cout << ans<<endl;

    return 0;
}