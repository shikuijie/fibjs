#!/bin/bash

set -ev

if [[ $TRAVIS_OS_NAME == 'osx' ]]; then
    sh build -j2 ${ARCH} ci
else
    echo "start docker build..."
    if [[ "${TARGET}" == "alpine" ]]; then
        DIR=`pwd`;sudo docker run -it -v ${DIR}:/home/ci xicilion/fibjs-build-alpine /bin/sh -c "cd /home/ci; sh build -j2 ${ARCH} ci"
    else
        DIR=`pwd`;sudo docker run -it -v ${DIR}:/home/ci fibjs/build-env /bin/sh -c "cd /home/ci; sh build -j2 ${ARCH} ci"
    fi
fi

exit 0;