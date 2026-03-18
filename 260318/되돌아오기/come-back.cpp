#include <iostream>

using namespace std;

int N;
char dir[100];
int dist[100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dir[i] >> dist[i];
    }

    int answer=-1,x=0,y=0;
    for(int i=0;i<N;i++){
        while(dist[i]--){
            answer++;
            if(dir[i]=='E'){
                x+=dx[0];
                y+=dy[0];
            }else if(dir[i]=='S'){
                x+=dx[1];
                y+=dy[1];
            }else if(dir[i]=='W'){
                x+=dx[2];
                y+=dy[2];
            }else if(dir[i]=='N'){
                x+=dx[3];
                y+=dy[3];
            }
            if(x==0 && y==0)
                break;
        }
        if(x==0 && y==0)
            break;
    }
    cout<<(answer>0 ? answer+1 : -1);

    return 0;
}