#!/bin/sh

tr '[:upper:]' '[:lower:]' < emails.txt | sponge emails.txt
    # lowercase all the things

grep '<' emails.txt
    # identify names, like this: ankit pati <contact@ankitpati.in>

sort emails.txt | uniq | sponge emails.txt
    # sort and remove duplicates in-place

cut -d'@' -f2 emails.txt | sort | uniq
    # list all email providers
    # identify obvious mistakes like: gmai.vom

rev emails.txt | sort | rev | grep -v gmail.com
    # filter out gmail addresses to take a closer look
    # group by email providers

