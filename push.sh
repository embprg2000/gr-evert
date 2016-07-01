#!/bin/sh
#
# Quick script to commit and push. Mainly to prevent the build
# directory from being pushed onto the server.
#
# Evert H. Rozendaal  -- embprg2000@gmail.com
#

if [ -z "$1" ]; then 
    echo "Commit message to short" ; 
    exit
else

    echo "Adding"

    git add CMakeLists.txt
    git add MANIFEST.md
    git add README.md
    git add push.sh

    git add apps/*
    git add cmake/*
    git add docs/*
    git add examples/*
    git add grc/*
    git add include/*
    git add lib/*
    git add python/*
    git add swig/*

    echo "Commiting"
    git commit -m "$1"

    git push

fi
