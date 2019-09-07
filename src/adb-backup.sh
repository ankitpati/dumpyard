#!/usr/bin/env bash

adb backup -apk -all -f backup.ab
adb restore backup.ab

adb backup -noapk com.threye.iaf.gots -f appdata.ab

# For an unencrypted backup, do
adb backup -noapk com.threye.iaf.gots -f appdata.ab
dd if=appdata.ab bs=1 skip=24 > compressed-data
printf "\x1f\x8b\x08\x00\x00\x00\x00\x00" | cat - compressed-data | \
                                            gunzip -c > decompressed-data.tar
tar xf decompressed-data.tar
