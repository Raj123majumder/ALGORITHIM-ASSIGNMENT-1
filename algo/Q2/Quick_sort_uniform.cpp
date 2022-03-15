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

class QuickSort{
    public:
    void Sort(int arr[], int low, int high){
        if (low >= high){
            return;
        }
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

    public:
    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1;

        for (int curr = low; curr <= high; curr++){
            if (arr[curr] < pivot){
                i++;
                swap(arr[i], arr[curr]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("uniform_data.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif


    int a[10000];
    for(int i = 0;i < 10000;i++){
        cin >> a[i];
    }
    
    QuickSort x;
    x.Sort(a, 0, 9999);

    for(int i = 0;i < 10000;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}