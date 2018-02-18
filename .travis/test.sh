#!/bin/bash

set -ev

if [[ $TRAVIS_OS_NAME == 'osx' ]]; then
    if [[ $ARCH == "amd64" ]]; then
        ./bin/Darwin_amd64_release/fibjs --prof test
    else
        ./bin/Darwin_i386_release/fibjs --prof test
    fi
else # linux
    if [[ $ARCH == "amd64" ]]; then
        ./bin/Linux_amd64_release/fibjs --prof test
    fi
fi

exit 0;