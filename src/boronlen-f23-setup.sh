#!/usr/bin/env bash

# bash_history.sh
# Fedora 23 i386 boronLen
# Sunday, 06 March 2016

# initial upgrade + chromium
sudo dnf copr enable spot/chromium
sudo dnf check-update
sudo dnf upgrade
sudo dnf install chromium

# Consult https://www.rpmfind.net/

# WLAN hardware
lspci | grep BCM4312
lsmod | grep b43

cd ~/Downloads/
wget https://downloads.openwrt.org/sources/broadcom-wl-4.150.10.5.tar.bz2
tar xjf broadcom-wl-4.150.10.5.tar.bz2

cd ~/Downloads/broadcom-wl-4.150.10.5/driver/
sudo b43-fwcutter -w /lib/firmware wl_apsta_mimo.o

cd ~/Downloads/
rm -rf broadcom-wl-4.150.10.5*

: ' Algorithm to decide which wireless drivers are needed.
    < ... > Denotes path taken in the script above.

                                       lspci
                                         |
                                Any of these listed?
                                        4301
                                        4303
                                        4306
                                        4309
                                        4311
                                        4312
                                        4318
                                       /    \
                                      /      \
                                     /        \
                                    /          \
                                < Yes >         No
                                  /              \
                                 /                \
                                /                  \
                             lsmod                4310?
                              /                   /   \
                             /                   /     \
                            /                  Yes      No
                          b43                  /         \
                        loaded?               /          43XG
                        /    \           ndiswrapper   4313,43224
                       /      No                        4321,43225
                      /        \                         4322,43227
                     /          \                         4328,43228
                 < Yes >     b43legacy                      /   \
                   /          loaded?                      /     \
                  /           /     \                    Yes      No
                 /          Yes      No                  /         \
                /           /         \                 /           \
             4306?         /           \          broadcom-wl      4320?
            4311?      Install        4311?                     (from lsusb
           4318?      version 3        4312?                   or other means)
           /   \      firmware         /   \                        /    \
          /     \                     /     \                      /      \
        Yes    < No >               Yes      No                  Yes       No
        /         \                 /         \                  /          \
       /           \               /           \                /            \
b43-openfwwf   < Install     broadcom-wl   ndiswrapper    b43-openfwwf   ndiswr-
    or          version 4                                       or        -apper
  Install       firmware >                                  rndis_wlan
 version 4
 firmware

'

# essentials
sudo dnf install bleachbit gcc gcc-g++ git nmap npm octave gstreamer

# LAMP stack
sudo dnf install httpd

sudo dnf install mysql mysql-server
sudo systemctl start mariadb.service
sudo /usr/bin/mysql_secure_installation

sudo dnf install php php-mysql
sudo dnf search php-

sudo systemctl start httpd.service

sudo chkconfig httpd on
sudo chkconfig mariadb on

sudo chown -hR ankitpati:ankitpati /var/www/html/

# Java
sudo dnf install java-1.8.0-openjdk.i686 java-1.8.0-openjdk-javadoc.noarch \
    java-1.8.0-openjdk-headless.i686 java-1.8.0-openjdk-devel.i686 \
    icedtea-web.i686

# end of bash_history.sh
