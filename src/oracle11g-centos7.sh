#!/usr/bin/env bash

sudo yum update
sudo yum install libaio bc flex
cd Oracle11g/
sudo rpm -ivh oracle-xe-11.2.0-1.0.x86_64.rpm
sudo /etc/init.d/oracle-xe configure
vim .bashrc
vim .bash_profile
sudo updatedb
locate oracle-env
sudo vim /u01/app/oracle/product/11.2.0/xe/bin/oracle_env.sh
grep -i osdba /etc/group
grep -i osdba /etc/passwd
grep -i dba /etc/passwd
grep -i dba /etc/group
grep -i oper /etc/group
sudo usermod -a -G dba ankitpati
sudo firewall-cmd --permanent --add-port=8080/tcp
echo 'execute dbms_xdb.setListenerLocalAccess(false);' | sqlplus -s / as sysdba
tar xJf apex_5.1.4.tar.xz 
rm apex_5.1.4.tar.xz 
sudo mv apex/ /opt/
sudo chown root:root -hR /opt/apex/
sudo -k
cd /opt/apex/
echo '@apexins SYSAUX SYSAUX TEMP /i/' | sqlplus -s / as sysdba
echo '@apex_epg_config /opt' | sqlplus -s / as sysdba
echo '@apxchpwd' | sqlplus -s / as sysdba
systemctl reboot
echo startup | sqlplus -s / as sysdba && lsnrctl start
ss -tulpn
