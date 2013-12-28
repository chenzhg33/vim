#!/bin/bash
#program
#	to config the ubuntu system with my favarite
# history:
# 2013-12-28 chen First Realese

apt-get update >> /dev/null
git init
flag0=$?
if [ $flag0 -eq 0]; then
	echo "no git found, install git..." >> config.log
	apt-get install git >> /dev/null
else
	echo "already install git" >> config.log
fi
vimAndSource()
{
	if [ $1 -eq 0 ];then
		which vim	
		vimflag=$?
		if [ $vimflag -eq 0 ]; then
			echo "vim already exist" >> config.log
		else
			echo "install vim..." >> config.log
			apt-get install vim
		fi
		git clone http://github.com/chenzhg33/vim > /dev/null
		echo "copy .vimrc to ~" >> config.log
		cp ~/vim/.vimrc ~/
		echo "copy sources.list to /ect/apt/" >> config.log
		cp ~/vim/sources.list /etc/apt/
		rm -rf ~/vim
	fi
	return 0
}

vimAndSource 0

installChrome() {
	which wget
	if [ $? -ne 0 ]; then
		echo "not find wget, install wget---" >> config.log
		apt-get install wget
		echo "install wget sccessfully!" >> config.log
	fi
	echo "download chrome...." >> config.log
	wget https://dl.google.com/linux/direct/google-chrome-stable_current_i386.deb
	echo "install chrome" >> config.log
	dkpg -i google-chrome-stable_current_i386.deb
	if [ $? -ne 0 ]; then
		echo "error happened, run apt-get -f install.." >> config.log
		apt-get -f install
	else
		return
	fi
	echo "install again.." >> config.log
	dkpg -i google-chrome-stable_current_i386.deb
}

installChrome

installSublime() {
	echo "begin install sublime---" >> config.log
	which wget
	if [ $? -ne 0 ]; then
		echo "not find wget, install wget---" >> config.log
		apt-get install wget
		echo "install wget sccessfully!" >> config.log
	fi
	if [ -e "Sublime Text 2.0.2.tar.bz2" ];then
		echo "unpackage sublime--" >> config.log
		bzip2 -d "Sublime Text 2.0.2.tar.bz2" > /dev/null
		tar -xvf "Sublime Text 2.0.2.tar"  > /dev/null
		python "Sublime Text 2/PackageSetup.py" install
		return
	fi
	echo "download sublime.." >> config.log
	wget http://c758482.r82.cf2.rackcdn.com/Sublime%20Text%202.0.2.tar.bz2
	bzip2 -d "Sublime Text 2.0.2.tar.bz2" >> config.log
	tar -xvf "Sublime Text 2.0.2.tar" >> config.log
	python "Sublime Text 2/PackageSetup.py" install
	echo "install sublime successfully!" >> config.log
	return 0
}
installSublime
