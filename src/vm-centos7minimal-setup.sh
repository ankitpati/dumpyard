#!/bin/bash

# bash_history.sh
# CentOS 7 Minimal amd64 vcent
# Saturday, 07 September 2019

sudo systemctl poweroff
sudo systemctl reboot

sudo dhclient
ping google.com
sudo vi /etc/sysconfig/network-scripts/ifcfg-enp0s3

sudo yum update
sudo yum install bash-completion
sudo yum install bzip2
sudo yum install deltarpm
sudo yum install ftp
sudo yum install gcc
sudo yum install gcc-c++
sudo yum install git
sudo yum install gnutls-utils
sudo yum install nano
sudo yum install patch
sudo yum install perl-CPAN
sudo yum install perl-CPAN-Changes
sudo yum install perl-CPAN-Meta
sudo yum install perl-CPAN-Meta-Requirements
sudo yum install perl-CPAN-Meta-YAML
sudo yum install perl-CPAN-Meta-YAML.noarch
sudo yum install perl-Crypt-SSLeay
sudo yum install perl-Net-SSLeay
sudo yum install perl-YAML-Syck
sudo yum install perl-YAML-Tiny.noarch
sudo yum install perl-YAML.noarch
sudo yum install telnet
sudo yum install unzip
sudo yum install vim
sudo yum install wget

sudo chkconfig sshd on

hostname -I
sudo systemctl status firewalld
sudo firewall-cmd --state
sudo firewall-cmd --permanent --add-port=22/tcp

git config --global user.name 'Ankit Pati'
git config --global user.email 'contact@ankitpati.in'
git config --global color.ui auto

git clone https://github.com/rtomayko/git-sh.git
cd git-sh/
make
sudo make install

set | grep PERL

sudo yum --enablerepo=rpmforge

gnutls-cli ankitpati.in
telnet ankitpati.in
