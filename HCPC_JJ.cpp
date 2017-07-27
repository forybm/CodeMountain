#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using std::string;
using namespace std;

int testcase;
int R = -1;
int p = -1;
string str;
string str2;
int radius[500000];

void myf() {
    memset(radius, 0, sizeof(radius));
    cin >> str;
    str2 = "";
    for (int i=0; i<str.length(); i++) {
        str2 += str[i];
        if (i != str.length()-1) str2 += "#";
    }
//    cout << str2 + "\n";
    for (int i=0; i<str2.length(); i++) {
        int temp_radius;
        if (i <= R && 2*p-i >= 0) temp_radius = min(radius[2*p - i], R - i);
        if (i > R) temp_radius = 0;
        while (i-1-temp_radius >= 0 && i+1+temp_radius < str2.length() && str2[i-1-temp_radius] == str2[i+1+temp_radius]) temp_radius++;
        radius[i] = temp_radius;
        if (i + radius[i] > R) {
            R = i + radius[i];
            p = i;
        }
    }
//    for (int i=0; i<str2.length(); i++) {
//        cout << radius[i];
//        cout << " ";
//    }   cout << "\n";
    int max_index = max_element(radius, radius+str2.length()) - radius;
    int max_radius = radius[max_index];
    if (max_radius%2 == 1) {
        if (max_radius == 1) {
            cout << 1;
            cout << "\n";
            return;
        }
        else if(str2[max_index + max_radius] == '#') {
            cout << max_radius;
            cout << "\n";
            return;
        }
        else {
            cout << max_radius+1;
            cout << "\n";
            return;
        }
    }
    if (max_radius%2 == 0) {
        if (max_radius == 0) {
            cout << 1;
            cout << "\n";
            return;
        }
        else if(str2[max_index + max_radius] == '#') {
            cout << max_radius;
            cout << "\n";
            return;
        }
        else {
            cout << max_radius+1;
            cout << "\n";
            return;
        }
    }
}

int main(void)
{
//    sort(test, test+5);
    scanf("%d", &testcase);
    while (testcase--) myf();
    return 0;
}
