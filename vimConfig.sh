#!/bin/bash
# to config the vim
#History
#2013-12-4 chen First release
PATH=/usr/lib/lightdm/lightdm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
export PATH

git > /dev/null
if [ $? != 1 ]; then
	sudo apt-get install git > /dev/null
fi

if [ -e ~/.vimrc ]; then
	echo ".vimrc already exist"
	echo "delete .vimrc"
	rm ~/.vimrc > /dev/null
fi
cd ~
git clone https://github.com/chenzhg33/vim
cp ~/vim/.vimrc ~
rm -rf ~/vim

