#include <iostream>
#include <deque>
using namespace std;
int main() {
    string S;
    cin>>S;
    int n;
    cin>>n;
    deque<int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    bool reverse = false;
    for(auto s:S){
        if(s=='R')
            reverse=!reverse;
        if(s=='D'){
            if(!reverse){
                arr.pop_front();
            }else{
                arr.pop_back();
            }
        }
    }
    while(!arr.empty()){
        if(!reverse){
            cout << arr.front()<<" ";
            arr.pop_front();
        }else{
            cout << arr.back()<<" ";
            arr.pop_back();
        }
    }

    
    return 0;
}