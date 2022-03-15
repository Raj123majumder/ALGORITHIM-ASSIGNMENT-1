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
        //insertSort(b[i], b[i].size());
        sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }

    for(int i = 0;i < n;i++){
        b[i].clear();
    }
}


void makearr(double arr[], int n){
    random_device rd;
    mt19937 gen(rd());
    // uniform_int_distribution<> distrib(1,500);
    normal_distribution<double> distrib(1000,1);

    for(int i = 0;i < n;i++){
        double num = distrib(gen);
        arr[i] = num;
    }

    int mx = FindMax(arr, n);
    int mn = FindMin(arr, n);

    for(int i = 0;i < n;i++){
        double x = ((arr[i] - mn) / (mx - mn));
        arr[i] = x;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("normal_data_normed.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif


    int epochs = 10;

    double a[1000];
    makearr(a, 1000);

    for(int i = 2;i <= 512;i*=2){
        int size = i;
        long long total_comp = 0;
        float total_time = 0;
        for(int j = 0;j < epochs;j++){
            float start_time = clock();
            bucketSort(a, size);
            float end_time = clock();

            //total_comp += comp;

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            total_time += time_taken;

        }

        float avg_time = total_time / epochs;
        long long avg_count = total_comp / epochs;

        cout << size << ", " << avg_time << endl;

    }
}