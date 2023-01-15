#include <bits/stdc++.h>


// AAACATCGT
// TACCTAAAA
using namespace std;

string s1,s2;
int lcs[1001][1001];
string result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1;
    cin >> s2;

    int maxl = max(s1.length(), s2.length());
    s1 = '0' + s1;
    s2 = '0' + s2;

    for(int i = 0; i <= maxl; i++){
        for(int j = 0; j <= maxl; j++){
            if(i == 0 || j == 0){
                lcs[i][j] = 0;
                continue;
            } 
            // 두 문자가 같다면 lcs[i - 1][j - 1] 대각선 값에 +1을 함
            if(s1[i] == s2[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                
                // 두문자가 다르다면 lcs[i - 1][j], lcs[i][j - 1]중 큰 값을 집어넣음
            else{
                if (lcs[i - 1][j] > lcs[i][j - 1])
                    lcs[i][j] = lcs[i - 1][j];
                else
                    lcs[i][j] = lcs[i][j - 1];
            }
        }        
    }
  
    cout << lcs[s1.length() - 1][s2.length() - 1];

    return 0;
}
