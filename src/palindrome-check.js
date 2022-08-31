#!/usr/bin/env node

function isPalindrome(string) {
    for (let i = 0, j = string.length - 1; i <= j; ++i, --j) {
        if (string[i] != string[j]) {
            return false;
        }
    }

    return true;
}

["hello, world", "able was I saw elba", "carac", "caac"].forEach(string =>
    isPalindrome(string)
        ? console.log(`“${string}” is palindrome`)
        : console.log(`“${string}” is not palindrome`)
);
