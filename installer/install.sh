#! /bin/sh

add_to_bashrc_if_not_exist()
{
	grep -q -F "$1" ~/.bashrc || echo "$1" >> ~/.bashrc
}

if [ -d ~/.graph_programming ];
then
	echo "Removing old .graph_programming folder"
	rm -rf ~/.graph_programming
fi

mkdir -p ~/.graph_programming/lib
mkdir -p ~/.graph_programming/include

echo "Copying development libraries."
cp -R -a lib/lib*.so* ~/.graph_programming/lib/.
echo "Copying header files."
cp -R include/* ~/.graph_programming/include/.

echo "Setting up environement variable."
add_to_bashrc_if_not_exist "### C Graphical Programming Environement Variable"
add_to_bashrc_if_not_exist "export LIBRARY_PATH=\$LIBRARY_PATH:${HOME}/.graph_programming/lib"
add_to_bashrc_if_not_exist "export LD_LIBRARY_PATH=\$LIBRARY_PATH:${HOME}/.graph_programming/lib"
add_to_bashrc_if_not_exist "export CPATH=\$CPATH:${HOME}/.graph_programming/include"

echo
echo "Please execute: source ~/.bashrc"
