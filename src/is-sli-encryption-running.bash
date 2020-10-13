#!/usr/bin/env bash

test -z "$(ps -Ao command | \
    grep -E "^java\\b.*\\bjar\\b.*\\bSLIEncryption\\.jar\\b")" && {
        echo 'Failed'
        exit 1
    }

echo 'Success'
