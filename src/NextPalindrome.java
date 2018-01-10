/* NextPalindrome.java */
/* Date  : 13 October 2016
 * Author: Ankit Pati
 */

import java.util.Scanner;

class NextPalindrome {
    static long reverse(long n) {
        long rev = 0;
        do rev = rev * 10 + n % 10;
        while ((n /= 10) != 0);
        return rev;
    }

    static long nextPalindrome(long n) {
        long rhs, palin, len, tmp, shft_div, shift;

        for (len = 1, tmp = n; (tmp /= 10) != 0; ++len);
        for (shft_div = 1, shift = len / 2; shift-- != 0; shft_div *= 10);

        rhs = reverse((palin = n / shft_div) / (len % 2 != 0 ? 10 : 1));
        palin = palin * shft_div + rhs;

        if (palin <= n) {
            rhs = reverse((palin = n / shft_div + 1) / (len % 2 != 0 ? 10 : 1));
            palin = palin * shft_div + rhs;
        }

        return palin;
    }

    public static void main(String args[]) {
        System.out.println("Number?");
        System.out.println("Next Palindrome:\n"
                           + nextPalindrome(new Scanner(System.in).nextInt()));
    }
};
/* end of NextPalindrome.java */
