#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char* argv[]){
  registerGen(argc, argv, 1);
  int n=rnd.next(atoi(argv[2]),atoi(argv[3]));
  cout<<n<<endl;
  for(int i=0;i<n-1;++i){
    int j=rnd.next(0,1);
    cout<<j<<' ';
  }
  cout<<rnd.next(0,1)<<endl;
  return 0;
}
