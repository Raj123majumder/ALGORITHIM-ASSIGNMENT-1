#include <cassert>
#include <cctype>
#include <algorithm>
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

//#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ff first
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define ss second

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int N = 500000;

void insertSort(short arr[], int str, int end){
    for (int i = str; i <= end; i++) {
        int val = arr[i];
        int pos = i - 1;
        while ((pos >= str) && (arr[pos] > val)) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = val;
    }
}

int median(short arr[], int str, int end){
    insertSort(arr, str, end);
    int mid = (str + end) / 2;
    return arr[mid];
}

int MOM(short arr[], int arr_size, int subarr_size){
    if (arr_size < subarr_size){
        int med = median(arr, 0, arr_size - 1);
        return med;
    }

    int full_size_arr = arr_size / subarr_size;
    int rem = arr_size % subarr_size, next_size;

    if (rem == 0){
        next_size = full_size_arr;
    }   
    else{
        next_size = full_size_arr + 1;
    }
        
    short next_arr[next_size];

    for (int i = 0; i < next_size; i++){
        if (i == arr_size)
            next_arr[i] = median(arr, subarr_size * i, arr_size - 1);
        else
            next_arr[i] = median(arr, subarr_size * i, subarr_size * (i + 1) - 1);
    }

    return MOM(next_arr, next_size, subarr_size);
}


int main(){
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int size = 16;
    short a[size];
    for(int i = 0;i < size;i++){
        a[i] = rand() % 1000;
    }
    
    for(int i = 0;i < size;i++){
        cout << b[i] << " ";
    }
    cout << endl;

    int x = MOM(b, size, 5);
    cout << x << endl;

}