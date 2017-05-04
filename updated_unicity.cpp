#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

map<int, char> revcode = { { 'a', 1 }, { 'b', 2 }, { 'c', 3 }, { 'd', 4 } };

set<string> combinationUtil(set<string> ans, int arr[], int data[], int start, int end,
    int index, int r)
{
    set<string> a;
    string q;
    if (index == r) {
        for (int j = 0; j < r; j++) {
            q += to_string(data[j]);
        }
        a.insert(q);
        return a;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        set<string> an = combinationUtil(ans, arr, data, i + 1, end, index + 1, r);
        for (auto f : an) {
            ans.insert(f);
        }
    }
    return ans;
}
set<string> printCombination(int arr[], int n, int r)
{
    int data[r];
    set<string> ans;
    set<string> a = combinationUtil(ans, arr, data, 0, n - 1, 0, r);
    return a;
}

map<string, vector<vector<int> > > final_ans;

void print_unicities(vector<vector<int> > data, int length, string val)
{
    if (length == 0)
        return;

    int arr[] = { 1, 2, 3, 4 };
    set<string> a = printCombination(arr, 4, length);
    for (auto f : a) {
        if (final_ans.find(f) == final_ans.end()) {
            map<string, int> data_freq;
            map<string, vector<int> > da;
            for (int i = 0; i < data.size(); i++) {
                val = "";
                for (int j = 0; j < length; j++) {
                    val += to_string(data[i][f[j]]);
                }
                if (data_freq.find(val) == data_freq.end()) {
                    data_freq.insert(pair<string, int>(val, 1));
                    da.insert(pair<string, vector<int> >(val, data[i]));
                }
                else {
                    data_freq[val] += 1;
                }
            }
            vector<vector<int> > n_d;
            for (const auto& sm_pair : data_freq) {
                if (sm_pair.second == 1) {
                    n_d.push_back(da[sm_pair.first]);
                }
            }
            final_ans.insert(pair<string, vector<vector<int> > >(f, n_d));
            print_unicities(n_d, length - 1, f);
        }
    }
    return;
}

int main()
{
    string a = "11111 1 1 1 1\n\
12222 1 2 2 2\n\
13333 2 1 3 3\n\
14444 2 2 1 4\n\
15555 3 1 2 1\n\
16666 3 2 3 2\n\
17777 1 3 1 3\n\
18888 2 3 2 4\n\
19999 3 3 3 1\n\
20000 1 1 1 2\n\
21111 2 2 2 3\n\
22222 3 3 3 4\n\
22223 4 1 1 1\n\
22224 4 2 2 2\n\
22225 4 3 3 3\n\
22226 4 4 4 4";
    vector<vector<int> > cols;

    istringstream ss(a);
    string token;

    vector<int> temp;
    while (getline(ss, token, '\n')) {
        temp.clear();
        istringstream inner(token);
        string t;
        while (getline(inner, t, ' ')) {
            temp.push_back(stoi(t));
        }
        cols.push_back(temp);
    }
    string set = "abcd";
    int set_size = 4;
    print_unicities(cols, set_size, set);

    for (const auto& sm_pair : final_ans) {
        cout << sm_pair.first << endl;
        for (int i = 0; i < sm_pair.second.size(); i++) {
            for (int j = 1; j < sm_pair.second[i].size(); j++) {
                cout << sm_pair.second[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
}
