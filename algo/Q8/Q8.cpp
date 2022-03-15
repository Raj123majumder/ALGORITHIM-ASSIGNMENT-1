#include <bits/stdc++.h>

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

void insertsort(short arr[], int str, int end){
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

int median(short arr[], int str, int end){
    insertsort(arr, str, end);
    int mid = (str + end) / 2;
    return arr[mid];
}

int MOM(short arr[], int arr_size, int subarr_size){
    if (arr_size < subarr_size){
        int med = median(arr, 0, arr_size - 1);
        return med;
    }

    int full_size_arr = arr_size / subarr_size;
    int rem = arr_size % subarr_size;

    int next_size;

    if (rem == 0){
        next_size = full_size_arr;
    }
    else{
        next_size = full_size_arr + 1;
    }

    short next_arr[next_size];

    for (int i = 0; i < next_size; i++){
        if (i == next_size - 1){
            next_arr[i] = median(arr, subarr_size * i, arr_size - 1);
        }
        else{
            next_arr[i] = median(arr, subarr_size * i, subarr_size * (i + 1) - 1);
        }
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

    int size = 10000;
    int epochs = 10;
    double avg_time, start_time, end_time, time_taken;

    int subarr_size;

    short arr[size];

    for (int k = 3; k <= 3000; k+=2){
        subarr_size = k;
        avg_time = 0;

        for (int i = 0; i < epochs; i++){
            for (int j = 0; j < size; j++)
                arr[j] = rand() % 100;

            start_time = clock();
            int temp = MOM(arr, size, subarr_size);
            end_time = clock();

            time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            avg_time += time_taken;
        }

        avg_time = avg_time / epochs;

        cout << subarr_size << ", " << avg_time << endl;
    }
}