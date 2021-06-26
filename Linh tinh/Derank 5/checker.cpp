#include "testlib.h"
using namespace std;

int main(int args, char * argv[]){
    registerTestlibCmd(args, argv);
    int kq=ans.readInt();
    int user=ouf.readInt();
    if(kq!=user)quitf(_wa, "expected %d, found %d", kq, user);
    quitf(_ok, "correct answer");
}
