#!/usr/bin/env bash

domain='google.com'
ip='10.10.220.1/24'

nmap --privileged -v -A -Pn -O --osscan-guess -p 443 "$domain"
nmap --privileged -sS -p 443 "$domain"
nmap --privileged -sS -Pn -p 443 "$domain"
nmap --privileged -sS -n "$ip" -p 80 # reveal MAC addresses
proxychains nmap --privileged -v -A -Pn -O --osscan-guess -p 443 "$domain"
