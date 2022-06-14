/*Boil use this snippet in Snippet Generator and merge with VS code
NAME: SUBHODIP ROY
BRANCH: COMPUTER SCIENCE AND ENGINEERING
COLLEGE: NETAJI SUBHASH ENGINEERING COLLEGE
GITHUB: subh-23
CODEFORCES: subh_23
CODECHEF: subh_23
GRADUATION YEAR: 2024
*/
// Header Files and Macros//------------------------------------------------------------------>>
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define int long long int
#define float double
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define mod (int)1e9
#define printCase(x) cout << "Case #" << x << ": "
#define nline '\n'
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// End Here//--------------------------------------------------------------------------------->>
void readVector(vi &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
}
void printVector(vi &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << nline;
}
// decreasing order
bool cmp(int a, int b)
{
    return b > a;
}

// put function
bool checkPalindrome(string s)
{
    if (s[0] == s[3] && s[1] == s[2])
        return true;
    return false;
}

// Code Here --------------------------------------------------------------------------------->>
void solve(int z)
{
    // Input//
    // int n; cin >> n;
    string s;
    cin >> s;
    int perMin;
    cin >> perMin;
    s.erase(s.begin() + 2);
    // cout << s << nline;
    // string parent = s;

    int count = 0;
    if (checkPalindrome(s))
        count++;

    int finalparentHr, finalparentMin, parentHr, parentMin;

    string parenthr;
    parenthr.push_back(s[0]);
    parenthr.push_back(s[1]);
    string parentmin;
    parentmin.push_back(s[2]);
    parentmin.push_back(s[3]);
    // parent integer ready
    // for only check
    finalparentHr = atoi(parenthr.c_str());
    finalparentMin = atoi(parentmin.c_str());

    parentHr = finalparentHr;
    parentMin = finalparentMin;

    while (true)
    {
        int breakperHr = perMin / 60;
        int breakperMin = perMin % 60;

        // new converted string is ready
        parentHr += breakperHr;
        parentHr %= 24;
        parentMin += breakperMin;
        // if it's exceeding to hr, take the hr value
        parentHr += (parentMin / 60);
        parentHr %= 24;
        parentMin %= 60;
        // for checking purpose has to change string
        // cout << parentHr << " " << parentMin << nline;
        if (parentHr == finalparentHr && parentMin == finalparentMin)
            break;

        // only for checking purpose
        string temphr, tempmin, finall;

        string f = to_string(parentHr);
        if (parentHr / 10 == 0)
        {
            temphr.push_back('0');
            temphr += f;
        }
        string d = to_string(parentMin);
        if (parentMin / 10 == 0)
        {
            tempmin.push_back('0');
            tempmin += d;
        }
        if (temphr.size() == 0)
        {
            temphr = to_string(parentHr);
        }
        if (tempmin.size() == 0)
        {
            tempmin = to_string(parentMin);
        }
        // finall
        temphr += tempmin;
        finall = temphr;
        if (checkPalindrome(finall))
            count++;
        // s = temp;
    }
    // printCase(z); //(For Google Competitions)
    // Code it Here
    cout << count << nline;
}
//-------------------------------------------------------------------------------------------->>
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int google = 1;
    cin >> google; // if not multiple testcase, remove it
    for (int i = 1; i <= google; i++)
    {
        solve(i);
    }
    return 0;
}
/*
INSTRUCTIONS TO KEEP IN MIND
-> Read the problem statement very clearly.
-> Dig deep into the problem statement and try to find the crispy part
   of the question (basically Logic).
-> Find out how the crispy part is helping you to design the algorithm
   to solve the current question
-> Try to find the edgecases (smaller & random cases).
-> Formulate the code in paper.
-> Code it.. Woohhhaaaahhh!! (Accepted)
*/