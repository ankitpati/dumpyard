#!/usr/bin/env bash

# bash_history.sh
# Ubuntu MATE i386 boronLen
# Saturday, 07 September 2019

sudo ufw enable
sudo nano /etc/default/apport

sudo apt-get update
sudo apt-get dist-upgrade
sudo rm /etc/apt/apt.conf.d/20auto-upgrades.ucf-old

sudo vim /etc/default/apport
sudo service apport restart
sudo cp ssh_config sshd_config /etc/ssh/

sudo apt install aria2
sudo apt install astyle
sudo apt install bleachbit
sudo apt install blender
sudo apt install chromium-browser
sudo apt install default-jdk
sudo apt install dia-gnome
sudo apt install g++
sudo apt install geany
sudo apt install geany-plugins
sudo apt install git
sudo apt install git-sh
sudo apt install gitg
sudo apt install gksu
sudo apt install gufw
sudo apt install idle-python3.5
sudo apt install indent
sudo apt install inkscape
sudo apt install kolourpaint4
sudo apt install krename
sudo apt install lamp-server^
sudo apt install libappindicator1
sudo apt install meld
sudo apt install mtpaint
sudo apt install netbeans
sudo apt install openshot
sudo apt install openssh-server
sudo apt install p7zip
sudo apt install p7zip-full
sudo apt install pdfchain
sudo apt install planner
sudo apt install polipo
sudo apt install ubuntu-restricted-extras

sudo mysql_secure_installation
gksu-properties

sudo dpkg -i google-chrome-stable_54.0.2840.71-1_amd64.deb
sudo dpkg -i atom-amd64.deb
