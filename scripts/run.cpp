#include <bits/stdc++.h>
#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
#include "tchar.h"
#include "stdio.h"
#include "shellapi.h"
using namespace std;

signed main(int argv, char* argc[2]){
    string name = argc[1];
    cout<<name<<endl;
    system(("start /wait " + name + ".exe").c_str());
    cout<<GetLastError()<<endl;
}
