#!/usr/bin/env perl

use strict;
use warnings;

my @inputs  = (0.5, -0.5);
my @weights = (2, -1);
my $bias    = 0.5;
my $target  = 0;

for (;;) {
    my $sum = $bias;
    $sum += $inputs[$_] * $weights[$_] foreach 0 .. $#inputs;

    my $output = $sum >= 0;
    last if $output == $target;

    my $delta_sign = $target - $output;
    $weights[$_] = $weights[$_] + $delta_sign*$inputs[$_] foreach 0 .. $#inputs;
}

print 'Trained Weights are ';
print "$_ " foreach @weights;
print "\n";
