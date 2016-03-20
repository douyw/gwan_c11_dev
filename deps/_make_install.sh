sudo cp date/date.h /usr/local/include/

cd build-sqlpp11
sudo make install

cd ../build-sqlpp11-connector-sqlite3
sudo make install

cd ../build-sqlpp11-connector-mysql
sudo make install
