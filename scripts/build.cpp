#include <bits/stdc++.h>
using namespace std;

signed main(int argv,char* argc[2]){
    //cout<<argc[1]<<endl;
    string name = argc[1];
    system(("g++ -Wfatal-errors -Wextra -Wall -std=c++11 -c " + name + ".cpp -o " + name + ".o").c_str());
    system(("g++ -o " + name + ".exe " + name + ".o -O2 -Wl,-stack,268435456").c_str());
}
