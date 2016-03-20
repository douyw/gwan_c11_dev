#!/bin/bash

cmake_deps() {
  echo "cmake building $1 ..."

  pkg="$1"
  builddir="build-$1"
  echo $builddir
  if [ ! -d $builddir ]; then
    mkdir -p $builddir
  fi

  cd $builddir
  cmake ../$pkg $2 $3 $4 $5
  make
  cd ..

  echo 'done'
}

build_sqlpp11() {
  cmake_deps 'sqlpp11'
  cmake_deps 'sqlpp11-connector-sqlite3' -DCMAKE_CXX_FLAGS=-fPIC
  cmake_deps 'sqlpp11-connector-mysql' -DCMAKE_CXX_FLAGS=-fPIC
}

clone_all() {
  git clone https://github.com/HowardHinnant/date.git
  git clone https://github.com/rbock/sqlpp11.git
  git clone https://github.com/rbock/sqlpp11-connector-sqlite3.git
  git clone https://github.com/rbock/sqlpp11-connector-mysql.git
}

clone_all

build_sqlpp11
