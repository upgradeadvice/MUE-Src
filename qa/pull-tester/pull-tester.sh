#!/bin/sh
# Copyright (c) 2009-2015 Bitcoin Developers
# Copyright (c) 2014-2015 MonetaryUnit Developers
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
#
# Helper script for pull-tester.
#Param 1: path to monetaryunit srcroot
#Param ...: arguments for build-test.sh

if [ $# -lt 1 ]; then
  echo "usage: $0 [monetaryunit srcroot] build-test arguments..."
fi

killall -q monetaryunit-cli
killall -q monetaryunitd

cd $1
shift

./autogen.sh
./configure
./qa/pull-tester/build-tests.sh "$@"
