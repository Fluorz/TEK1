#
# test42sh_2.sh for test42sh in /home/hugo/cours/Code/Semestre 2/Programming Shell/PSU_2016_42sh/
#
# Made by Hugo Bleuzen
# Login   <hugo.bleuzen@epitech.eu>
#
# Started on  Wed May 31 14:24:02 2017 Hugo Bleuzen
# Last update Apr May 31 17:39:06 2017
#

#!/bin/bash

SHELL=./mysh
TCSH=tcsh

if [ ! -x ./42sh ]; then
  echo "Can't open your shell"
  exit
fi

declare -a tests=
(
"cd /bin/bash"
"ls"
"ls | cat -e"
"<<"
">>"
"echo coucou"
"env env env env env env ls && env env env ls && env ls && ls && env env env env env env env env env env env env `echo ls` && ls && env env env env env env env env env env env env env env env ls"
"test || test && test && test || test ; ; ; ; ; ; ; ungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoustest || test && test && test || test ; ; ; ; ; ; ; ungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertoussatoussaungrosbuffertous;"
"|"
";"
"&"
"&&"
"||"
"\\"
"ls /bin"
"cat /etc/resolv.conf"
"ls | | | ||||"
";;;;;ls;;;;;"
"ls && dfe"
"ls ../ && ls"
"ls || ls ../"
"\"\\"\\"\"\"\""
"cd /; cd cd /; cd ../; cd;"
"cat Makefile"
"Unexisting"
"ls | grep include"
"ls | grep e | grep a > toto ; cat toto ; rm toto"
"ls > cul | ls < EOF"
"cat toto"
"cat -e Makefile | grep 'CC'"
"ls /root || ls"
"ls;ls"
"ls ; ls"
"|"
""
"&"
"&&"
"||"
";"
";;"
"cd ../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../../ ; pwd ; cd -"
"unsetenv OLD_PWD ; unsetenv OLDPWD ; cd -"
"cat /etc/passwd | tr : # | tr -s abcdefghijklmnopqrstuvwxyz| cut -c 2 | grep -e a -e b -e\
 c -e d -e e -e f -e g -e h -e i -e j -e k -e l -e m -e n -e o -e p -e q -e r -e s -e \
t -e u -e v -e w -e x -e y -e z |sort|uniq -c"
"echo `cat main.c | more` | more"
"ls /dev | grep tty | sort -r | rev > toto ; < toto cat | rev | wc -l > titi"
"\t\t    ls\t     \t-l    \t\t  \t -a /usr   \t\t"
"who"
"/bin/kill -11 0"
"ls > toto ; date >> toto ; >> toto ls ; < toto cat"
"<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; ; < ma_note cat ;"
"unsetenv HOSTTYPE"
"unsetenv VENDOR"
"unsetenv OSTYPE"
"unsetenv MACHTYPE"
"unsetenv SHLVL"
"unsetenv PWD"
"unsetenv LOGNAME"
"unsetenv USER"
"unsetenv GROUP"
"unsetenv HOST"
"unsetenv REMOTEHOST"
"unsetenv _"
)

for i in "${tests[@]}"
do

echo "Test : $i"


(echo "$i" | $SHELL 2>&1) >/dev/null
res1=$?
(echo "$i" | $TCSH 2>&1) >/dev/null
res2=$?

echo -en "\tRETURN : "
[ $res1 == $res2 ] && echo -e "OK" || echo -e "KO"

done
