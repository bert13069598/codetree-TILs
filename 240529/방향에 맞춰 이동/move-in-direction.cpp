#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    char dir;
    int d;
    cin >> n;
    int x=0,y=0;
    while(n--){
        cin >> dir>>d;
        if(dir=='N')
            y+=d;
        else if(dir=='E')
            x+=d;
        else if(dir=='S')
            y-=d;
        else if(dir=='W')
            x-=d;
    }
    cout << x << " " << y;
    return 0;
}