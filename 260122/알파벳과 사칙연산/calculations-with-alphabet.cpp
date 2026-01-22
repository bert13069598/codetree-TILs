#include <iostream>
#include <map>

using namespace std;

string expression;
int abcdef[6]{};
map<char,int> ctoi{{'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5}};

int dfs(int now){
    if(now==6){
        int ret=abcdef[ctoi[expression[0]]];
        for(int i=0;i<expression.size()/2;i++){
            if(expression[2*i+1]=='+')
                ret+=abcdef[ctoi[expression[2*i+2]]];
            else if(expression[2*i+1]=='-')
                ret-=abcdef[ctoi[expression[2*i+2]]];
            else if(expression[2*i+1]=='*')
                ret*=abcdef[ctoi[expression[2*i+2]]];
        }
        return ret;
    }
    int answer=0;
    int next=now+1;
    for(;next<6;next++)
        if(abcdef[next])
            break;
    for(int i=0;i<4;i++){
        abcdef[next]=i+1;
        answer=max(answer,dfs(next));
    }
    return answer;
}

int main() {
    cin >> expression;
    for(auto e:expression)
        abcdef[ctoi[e]]=1;
    
    cout<<dfs(-1);

    return 0;
}
