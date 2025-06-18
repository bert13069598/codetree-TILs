#include <iostream>
#include <string>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    int p = s.size();
    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if (command == 'P') {
            char c;
            cin >> c;
            s.resize(s.size() + 1);
            int p0 = s.size() - 1;
            while(p0 > p){
                s[p0] = s[p0 - 1];
                p0--;
            }
            s[p] = c;
            p++;
        } else if ( command == 'L' && p != 0) {
            p--;
        } else if ( command == 'R' && p != s.size()) {
            p++;
        } else if ( command == 'D') {
            if (p != s.size()){
                int p0 = p;
                while(p0 < s.size() - 1){
                    s[p0] = s[p0 + 1];
                    p0++;
                }
            }
            s.resize(s.size() - 1);
        }
    }
    cout << s;
    return 0;
}
