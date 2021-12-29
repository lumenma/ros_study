./configure --prefix=/usr/local/python3 --enable-optimizations

ln -s /usr/local/python3/bin/python3.6 /usr/bin/python36

ln -s /usr/local/python3/bin/pip3.6 /usr/bin/pip36

python36 -V

sudo update-alternatives --install /usr/bin/python3 python3 /usr/local/bin/python3.6 2 

sudo python36 get-pip.py

python36 pip36 install