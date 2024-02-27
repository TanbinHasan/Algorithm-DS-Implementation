/**
 *    author:  Tanbin_Hasan
 *    created: 16.06.2021 16:27:47
 **/
#include <bits/stdc++.h>

using namespace std;

void TowerofHanoi(int n, char from, char to, char aux) {
  if (n == 1) {
    cout << "Move disk 1 from rod " << from << " to rod " << to << '\n';
    return;
  }
  TowerofHanoi(n - 1, from, aux, to);
  cout << "Move disk " << n << " from rod " << from << " to rod " << to << '\n';
  TowerofHanoi(n - 1, aux, to, from);
}

/*
  For remember ,
  from = 1
  to = 2
  aux = 3
  Initial call : 1 , 2 , 3 // Take it as reference
  Inside function :
    1st call : 1 , 3 , 2 // swap 2 , 3
    2nd call : 3 , 2 , 1 // swap 1 , 3
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  TowerofHanoi(n, 'A', 'C', 'B');
  return 0;
}