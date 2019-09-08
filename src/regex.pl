#!/usr/bin/env perl

use strict;
use warnings;

my $string;

print "String for Palindrome Check?\n";
$string = <STDIN>;

print $string =~ /^ ((.) (?:(?1)|.?) \2) $/xi ? '' : 'Not ', "Matched\n";

print "String for Balanced Parens Check?\n";
$string = <STDIN>;

use re qw(eval);
no strict qw(vars);
my $match_check_regex = qr/^
     (?{ $d = 0 })         # Set depth to 0
     (?:
         \(                # When you see an open parenthesis...
         (?{ ++$d })       #  ...increment the depth
      |
         \)                # or you could see a close parenthesis...
         (?{ --$d })       #  ...in which case decrement the depth...
         (?:               #  ...and check...
           (?{ $d < 0 })   #  ...if there was no matching open paren...
           (?!)            #  ...then fail.
         )
      |
         (?> [^()]* )      # or you could see some non-parenthesis text
                           # (but don't bother backtracking into it)
     )*                    # After you match as much as possible...
     (?:                   # ...check to see if...
       (?{ $d })           # ...there were unmatched open parentheses...
       (?!)                # ...if so then fail.
     )
$/x;
use strict qw(vars);
no re qw(eval);

print $string =~ $match_check_regex ? '' : 'Not ', "Balanced Parens\n";
