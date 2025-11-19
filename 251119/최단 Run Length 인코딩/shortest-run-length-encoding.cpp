#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int answer=A.size()*2;
    for(int i=0;i<A.size();i++){
        int sum=2;
        for(int j=0;j<A.size()-1;j++){
            if(A[j]!=A[j+1])
                sum+=2;
        }
        // cout << sum << " " << A << "\n";
        answer=min(answer,sum);

        char temp=A[A.size()-1];
        for(int j=A.size()-1;j>0;j--)
            A[j]=A[j-1];
        A[0]=temp;
    }
    if(answer==2)
        answer=3;

    cout << answer;

    return 0;
}
