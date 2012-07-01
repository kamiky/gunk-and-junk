#!/bin/bash

echo $1
if test "$1"
then
    export LD_PRELOAD=`pwd`/../libasm.so
    $1
fi