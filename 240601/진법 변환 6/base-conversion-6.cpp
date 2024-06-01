#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int main() {
    int a,b;
    string n;
    cin>>a>>n>>b;
    int num=0;
    for(int i=0;i<n.size();i++){
        int k;
        if(n[n.size()-1-i] - '0'>=10)   
            k=n[n.size()-1-i] - 'W';
        else
            k=n[n.size()-1-i] - '0';

        num += pow(a,i)*(k);
    }
    stack<char> st;
    while(true){
        char s;
        if(num%b>=10)
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