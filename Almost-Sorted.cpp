#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// https://www.hackerrank.com/challenges/almost-sorted/forum from kljsandjb

void almostSorted(vector<int> arr)
{
    if (std::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "yes" << '\n';
        return;
    }
    
    int size = arr.size();
    int i = 0;
    int j = size - 1;
    
    for (; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
    }
    for (; j > 0; j--)
    {
        if (arr[j] < arr[j - 1])
        {
            break;
        }
    }

    std::swap(arr[i], arr[j]);
    if (std::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "yes" << '\n';
        std::cout << "swap " << i + 1 << " " << j + 1 << '\n';
        return;
    }
    
    std::swap(arr[i], arr[j]);
    std::reverse(arr.begin() + i, arr.begin() + j + 1);
    if (std::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "yes" << '\n';
        std::cout << "reverse " << i + 1 << " " << j + 1 << '\n';
        return;
    }

    std::cout << "no" << '\n';
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
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

