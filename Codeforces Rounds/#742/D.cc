int n;

int base = 11;
str d = "0123456789abcdef";

int getval(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'a' + 10;
}

str plusbase(str a, str b) {
    if (sz(b) > sz(a)) swap(a, b);

    str ans = "";
    int j = sz(b) - 1, carry = 0;

    RFOR(i, sz(a) - 1, 0, 1) {
        int da = getval(a[i]), db = 0;
        if (j >= 0) db = getval(b[j]);

        int sum = da + db + carry;
        if (sum >= base) {
            int left = sum % base;
            carry = 1;
            ans = d[left] + ans;
        } else {
            ans = d[sum] + ans;
            carry = 0;
        }
        --j;
    }
    if (carry) ans = '1' + ans;

    return ans;
}

int pw10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

int main(int argc, char* argv[]) {
    FastIO();
    hardio("input");

    int tc; cin >> tc;
    while (tc--) {
        int x, n; cin >> x >> n;
        string ans[106] = {};

        FORW(i, 1, n, 1) {
            int mx = pw10[sz(to_string(x)) - 1];

            if (i == n) { // It's last number, what do you do? Just take it
                ans[i] = to_string(x);
                break;
            }

            if (x - x / mx * mx >= (n - i)) { // Greedy
                ans[i] = to_string(x / mx * mx);
                x -= x / mx * mx;
            } else { // else just get median
                int med = x / (n - i + 1);
                FORW(j, i, n, 1) {
                    if (j == i) ans[j] = to_string(med + x - (n - i + 1) * med);
                    else ans[j] = to_string(med);
                }
                break;
            }
        }

        string plusans = "0";
        FORW(i, 1, n, 1) {
            cout << ans[i] << ' ';
            plusans = plusbase(plusans, ans[i]);
        }
        // cout << " | " << plusans;
        cout << endl;
    }
    return 0; }
