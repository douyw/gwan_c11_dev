# gwan_c11_dev
gwan c++11 devel environment install


## Install 

* install deps [sqlpp11](https://github.com/rbock/sqlpp11), [sqlpp11-connector-sqlite3](https://github.com/rbock/sqlpp11-connector-sqlite3), etc
* install tools (Optional)
* install gwan
* install examples

### Install deps

    sh deps/install_all.sh

### Install tools (Optional)

    sh tools/_build_weighttp.sh
    sh tools/compile_abc.sh

### Install gwan

    sh install_gwan.sh

### Install examples

    sh install_examples.sh


## Run

    cd gwan_linux64-bit
    ./gwan
    (or)
    sudo ./gwan

## Browse

    http://<YourHost>:8080/?hello11.cpp
    http://<YourHost>:8080/?sqlpp11_select.cpp (TIP: The output is plain text, view source for better format)
  
Have fun!

