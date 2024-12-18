#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


void almostSorted(vector<int> arr)
{
    int n = arr.size();
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    if (arr == sortedArr)
    {
        cout << "yes" << endl;
        return;
    }

    int l = 0, r = n - 1;
    while (l < n && arr[l] == sortedArr[l]) l++;
    while (r > l && arr[r] == sortedArr[r]) r--;

    swap(arr[l], arr[r]);
    if (arr == sortedArr)
    {
        cout << "yes" << endl;
        cout << "swap " << l + 1 << " " << r + 1 << endl;
        return;
    }
    
    swap(arr[l], arr[r]);
    reverse(arr.begin() + l, arr.begin() + r + 1);
    if (arr == sortedArr)
    {
        cout << "yes" << endl;
        cout << "reverse " << l + 1 << " " << r + 1 << endl;
        return;
    }

    cout << "no" << endl;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);
    s.erase(
        std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(),
        s.end()
    );
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    std::istringstream iss(str);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
