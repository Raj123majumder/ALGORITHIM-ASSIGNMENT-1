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

void merge(double arr[], int p, int q, int r, int *comp) {
  int n1 = q - p + 1;
  int n2 = r - q;

  double L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2){
    if (L[i] <= M[j]){
        arr[k] = L[i];
        i++;
        (*comp) += 1;
    } 
    else{
        arr[k] = M[j];
        j++;
        (*comp) += 1;
    }
    k++;
  }

  while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
        (*comp) += 1;
  }

  while (j < n2){
        arr[k] = M[j];
        j++;
        k++;
        (*comp) += 1;
  }
}

void mergeSort(double arr[], int l, int r, int *comp) {
  if (l < r){
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, comp);
    mergeSort(arr, m + 1, r, comp);

    merge(arr, l, m, r, comp);
  }
}

void makearr(double arr[], int n){
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> distrib(1000,1);

    for(int i = 0;i < n;i++){
        double num = distrib(gen);
        arr[i] = num;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int epochs = 10;

    for(int i = 1;i <= 131072 * 2;i*=2){
        int size = i;
        long long total_comp = 0;
        float total_time = 0;
        for(int j = 0;j < epochs;j++){
            double a[size];
            int comp = 0;
            makearr(a, i);

            float start_time = clock();
            mergeSort(a, 0, size - 1, &comp);
            float end_time = clock();

            total_comp += comp;

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            total_time += time_taken;

        }

        float avg_time = total_time / epochs;
        long long avg_count = total_comp / epochs;

        cout << size << ", " << avg_time << ", " << avg_count << endl;

    }
}