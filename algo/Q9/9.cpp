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

void insertsort(int arr[], int str, int end){
    for (int i = str; i <= end; i++){
        int val = arr[i];
        int pos = i - 1;
        while (pos >= str && arr[pos] > val){
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = val;
    }
}

int median(int arr[], int str, int end){
    insertsort(arr, str, end);
    int mid = (str + end) / 2;
    return arr[mid];
}

int MOM(int arr[], int arr_size, int subarr_size){
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

    int next_arr[next_size];
    for (int i = 0; i < next_size; i++){
        if (i == next_size - 1){
            //next_arr[i] = arr[median(arr, subarr_size * i, arr_size - 1)];
            next_arr[i] = median(arr, subarr_size * i, arr_size - 1);
        }
        else{
            //next_arr[i] = arr[median(arr, subarr_size * i, subarr_size * (i + 1) - 1)];
            next_arr[i] = median(arr, subarr_size * i, subarr_size * (i + 1) - 1);
        }
    }
    return MOM(next_arr, next_size, subarr_size);
}

void makearr(int arr[], int n){
    random_device rd;
    mt19937 gen(rd());
    unordered_set<int> s;
    //normal_distribution<double> distrib(1000,1);
    uniform_int_distribution<> distrib(1,1000);

    while(s.size() != n){
        int num = distrib(gen);
        s.insert(num);
    }

    int i = 0;
    for(unordered_set<int>::iterator it = s.begin();it != s.end();it++){
        arr[i] = *it;
        i += 1;
    }
}

void shuffle_array(int arr[], int n){
    unsigned seed = 0;
    random_shuffle(arr, arr + n);
}

int position(int arr[], int n, int mom){
    int b[n];
    for(int i = 0;i < n;i++){
        b[i] = arr[i];
    }

    int idx;
    sort(b, b + n);
    for(int i = 0;i < n;i++){
        if(b[i] == mom){
            idx = i;
            break;
        }
    }

    return idx;
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
    

    int size = 10000;
    int epochs = 10;
    double avg_time, start_time, end_time, time_taken;

    int subarr_size;
    subarr_size = 5;

    int arr[size];
    for(int i = 101;i <= 31072;i+=2){
        int size = i;
        float total_time = 0;
        int total_part_size = 0;
        int a[size];
        makearr(a, i);
        for(int j = 0;j < epochs;j++){
            shuffle_array(a, size);

            float start_time = clock();
            int ele = MOM(a, size, subarr_size);
            float end_time = clock();

            int part_size = abs(position(a, size, ele) - (size / 2));

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            total_time += time_taken;
            total_part_size += part_size;
        }

        float avg_time = total_time / epochs;
        float avg_size = total_part_size / epochs;
        cout << size << ", " << avg_time << ", " << avg_size << endl;

    }
}