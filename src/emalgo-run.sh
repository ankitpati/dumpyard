#!/usr/bin/env bash

sudo apt install -y 'python' 'python-virtualenv' 'python-dev' 'python-tk' && \
sudo mkdir -p '/opt/virtualenvs/' && \
sudo chown "$USER:$USER" -hR '/opt/virtualenvs/' && \
sudo -k && \
\
cd '/opt/virtualenvs/' && \
rm -rf 'emalgo' && \
virtualenv 'emalgo' && \
cd 'emalgo/' && \
. 'bin/activate' && \
pip install 'numpy' 'matplotlib' && \
\
git clone 'https://github.com/ali92hm/expectation-maximization.git' && \
mv 'expectation-maximization/' 'app/' && \
cd 'app/' && \
\
python demo.py 'sample_input/input.csv' && \
eog 'sample_result.png' && \
echo 'Done!'
