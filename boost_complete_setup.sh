apt-get install mpi-default-dev libicu-dev python-dev python3-dev libbz2-dev zlib1g-dev
./b2 install --build-type=complete --layout=versioned threading=multi --prefix=<boostdir>
