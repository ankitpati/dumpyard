#!/usr/bin/env bash

sudo yum update
sudo yum install bugzilla
sudo yum install 'perl(Apache2::SizeLimit)'
sudo yum install 'perl(Authen::Radius)'
sudo yum install 'perl(Authen::SASL)'
sudo yum install 'perl(CGI)'
sudo yum install 'perl(Cache::Memcached)'
sudo yum install 'perl(Chart::Lines)'
sudo yum install 'perl(DBI)'
sudo yum install 'perl(Daemon::Generic)'
sudo yum install 'perl(Date::Format)'
sudo yum install 'perl(DateTime)'
sudo yum install 'perl(DateTime::TimeZone)'
sudo yum install 'perl(Digest::SHA)'
sudo yum install 'perl(Email::MIME)'
sudo yum install 'perl(Email::Reply)'
sudo yum install 'perl(Email::Sender)'
sudo yum install 'perl(Encode)'
sudo yum install 'perl(Encode::Detect)'
sudo yum install 'perl(File::MimeInfo::Magic)'
sudo yum install 'perl(File::Slurp)'
sudo yum install 'perl(File::Which)'
sudo yum install 'perl(GD)'
sudo yum install 'perl(GD::Graph)'
sudo yum install 'perl(GD::Text)'
sudo yum install 'perl(HTML::FormatText::WithLinks)'
sudo yum install 'perl(HTML::Parser)'
sudo yum install 'perl(HTML::Scrubber)'
sudo yum install 'perl(IO::Scalar)'
sudo yum install 'perl(JSON::RPC)'
sudo yum install 'perl(JSON::XS)'
sudo yum install 'perl(LWP::UserAgent)'
sudo yum install 'perl(List::MoreUtils)'
sudo yum install 'perl(MIME::Parser)'
sudo yum install 'perl(Math::Random::ISAAC)'
sudo yum install 'perl(Net::LDAP)'
sudo yum install 'perl(Net::SMTP::SSL)'
sudo yum install 'perl(PatchReader)'
sudo yum install 'perl(SOAP::Lite)'
sudo yum install 'perl(Template)'
sudo yum install 'perl(Template::Plugin::GD::Image)'
sudo yum install 'perl(Test::Taint)'
sudo yum install 'perl(TheSchwartz)'
sudo yum install 'perl(URI)'
sudo yum install 'perl(XML::Twig)'
sudo yum install 'perl(XMLRPC::Lite)'
sudo yum install 'perl(mod_perl2)'
sudo yum install gcc
sudo yum install gd-devel
sudo yum install graphviz
sudo yum install httpd-devel
sudo yum install mariadb-devel
sudo yum install mod_perl-devel
sudo yum install patchutils
sudo yum install rst2pdf
git clone --branch release-5.0-stable https://github.com/bugzilla/bugzilla.git

./checksetup.pl
./collectstats.pl
./testserver.pl http://localhost/bugzilla
bgserve
cd /etc/httpd/conf.d/
cd /var/www/
cd /var/www/html/
git clone --branch release-5.0-stable https://github.com/bugzilla/bugzilla.git
grep apache /etc/group
grep www-data /etc/group
mysql -ubugs -p
perl Build.PL
perl Build.PL Build manifest
perl Build.PL manifest
sudo ./checksetup.pl
sudo chmod 640 bugzilla/bugs.conf
sudo chown -hR ankitpati:ankitpati html/
sudo chown root:apache bugzilla/bugs.conf
sudo find bugzilla/ -type f \( -name '*.pl' -o -name '*.cgi' \) -exec chcon -t httpd_sys_script_exec_t {} +
sudo ln -T /var/www/html/bugzilla/bugs.conf bugs.conf
sudo restorecon -vr html/
sudo systemctl restart httpd.service
sudo systemctl restart mariadb.service
sudo vi /etc/httpd/conf/httpd.conf
sudo vi /etc/my.cnf
sudo vi /var/www/html/bugzilla/localconfig
sudo vi bugs.conf
sudo vi bugzilla/bugs.conf
vim .my.cnf
vim autoindex.conf
vim localconfig
vim perl.conf
