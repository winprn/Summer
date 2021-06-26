#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=rnd.next(atoi(argv[1]), atoi(argv[1]));
    string regex = "[1-9][0-9]{" + to_string(n) + "}";

    cout<<rnd.next(regex)<<endl;
    return 0;
}