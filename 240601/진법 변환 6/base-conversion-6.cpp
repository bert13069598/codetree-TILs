#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main() {
    int a,b;
    string n;
    cin>>a>>n>>b;
    int num=0;
    for(int i=0;i<n.size();i++)
        num += pow(a,i)*(n[n.size()-1-i] - '0');
    stack<char> st;
    while(true){
        char s;
        if(num%b>10)
            s = num%b+'W';
        else
            s = num%b+'0';
        st.emplace(s);
        num/=b;
        if(num<1)
            break;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}