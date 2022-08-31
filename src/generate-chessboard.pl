#!/usr/bin/env perl

use strict;
use warnings;

our $VERSION = '0.01';

my $me = (split m{/}, $0)[-1];

@ARGV or die "Usage:\n\t$me <n>...\n";

foreach my $n (@ARGV) {
    foreach my $row (0 .. $n - 1) {
        foreach my $col (0 .. $n - 1) {
            printf '%2d ', $row * $n + $col;
        }
        print "\n";
    }
}
