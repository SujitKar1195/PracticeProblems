#include <iostream>
#include <string>

using namespace std;

int countAnagrams(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int freqText[26] = {0};
    int freqPattern[26] = {0};
    int count = 0;

    // Initialize frequency of each character in pattern
    for (int i = 0; i < m; i++) {
        freqPattern[pattern[i] - 'a']++;
    }

    // Iterate through first m characters in text
    for (int i = 0; i < m; i++) {
        freqText[text[i] - 'a']++;
    }

    // Sliding window technique
    int left = 0, right = m;
    while (right <= n) {
        // If frequency of each character is equal
        if (equal(begin(freqPattern), end(freqPattern), begin(freqText))) {
            count++;
        }
        // Move the window by 1
        freqText[text[left] - 'a']--;
        freqText[text[right] - 'a']++;
        left++;
        right++;
    }

    return count;
}

int main() {
    string text = "aabaabaa";
    string pattern = "aaba";
    cout << "Count of anagrams: " << countAnagrams(text, pattern) << endl;
    return 0;
}
