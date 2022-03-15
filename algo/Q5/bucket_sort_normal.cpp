#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ff first
#define rep(i, a, b) for(ll i=a;i<b;i++)
#define ss second

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int N = 500000;

double FindMax(double a[], int n){
    int mx = INT_MIN;
    for(int i = 0;i < n;i++){
        if(mx < a[i]){
            mx = a[i];
        }
    }

    return mx;
}

double FindMin(double a[], int n){
    double mx = INT_MAX;
    for(int i = 0;i < n;i++){
        if(mx > a[i]){
            mx = a[i];
        }
    }

    return mx;
}

void insertSort(vector<double> &arr, int n){
    double key;
    int j;
    for(int i = 1;i < n;i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(double arr[], int n){
    vector<double> b[n];

    for (int i = 0; i < n; i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        insertSort(b[i], b[i].size());
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("normal_data_normed.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif


    double a[1000];
    for(int i = 0;i < 1000;i++){
        cin >> a[i];
    }
    
    double b[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    // double mx = FindMax(a, 10000);
    // double mn = FindMin(a, 10000);
    
    //cout << mx << " " << mn << endl;
    //cout << a[0] - mn << " " << mx - mn << endl;
    //double x = 37 / 4;
   // cout << x << endl;

   bucketSort(a, 1000);
   for(int i = 0;i < 1000;i++){
       cout << a[i] << " ";
   }
   cout << endl;
}