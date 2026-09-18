#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void partitionString(
    const string &s,
    int start,
    vector<string> &current,
    vector<vector<string>> &answer
) {
    if (start == s.size()) {
        answer.push_back(current);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));

            partitionString(s, end + 1, current, answer);

            current.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<vector<string>> answer;
    vector<string> current;

    partitionString(s, 0, current, answer);

    cout << "Palindrome Partitions:\n";

    for (auto &partition : answer) {
        for (auto &word : partition)
            cout << word << " ";

        cout << endl;
    }

    return 0;
}
