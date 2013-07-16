#!/bin/sh

RESULT=`curl http://gitlab.freebit.net:9090/jenkins/job/SilkBrowser/lastBuild/api/xml | perl -le '$_=<>;print [/<result>(.+?)</]->[0]'`

echo $RESULT

if [ $RESULT = SUCCESS ]
then
    echo "success"
    curl http://localhost:3000/status?status=s
else
    echo "error"
    curl http://localhost:3000/status?status=e
fi
