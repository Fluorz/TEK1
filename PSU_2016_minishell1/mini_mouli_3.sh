#!/bin/sh
## mini_mouli_3.sh for minishell1 in /home/Thery/Desktop/PSU_2016_minishell1
## 
## Made by Thery Fouchter
## Login   <thery.fouchter@epitech.eu>
## 
## Started on  Wed Jan 18 01:40:59 2017 Thery Fouchter
## Last update Thu Jan 19 18:03:59 2017 Thery Fouchter
##

init () {
    if [ ! -f ./mysh ]
    then
	while true
	do
	    read -p './mysh not found, execute make re ? [y/n] ' answer
	    if [ "$answer" = 'y' ] || [ "$answer" = 'Y' ]
	    then
		make re
		break
	    fi
	    if [ "$answer" = 'n' ] || [ "$answer" = 'N' ]
	    then
		exit
	    fi
	done
    fi
    mkdir -p logs
    echo 'minishell1' > logs/logs_mysh
    echo 'minishell1' > logs/logs_tcsh
    echo 'Therynosaure Alpha' > logs/logs.txt
    echo "int main(void){char *str;str=0;*str=42;}" > logs/segfault.c
    echo "int main(void){int i=0;int a=42/i;}" > logs/float.c
    echo "#include <unistd.h>" > logs/hello.c
    echo "int main(void){write(1,\"Hello World !\",13);char c=10;write(1,&c,1);return(0);}" >> logs/hello.c
    echo "int main(void){return(42);}" > logs/42.c
    gcc -o segfault logs/segfault.c
    gcc -o float logs/float.c
    gcc -o hello logs/hello.c
    gcc -o 42 logs/42.c
    mv -t logs segfault float hello 42
    cp -n logs/hello logs/hello_nw
    chmod 000 logs/hello_nw
    verbose='y'
}

title () {
    echo '==========================================================' >> logs/logs.txt
    echo '==========================================================' >> logs/logs_mysh
    echo '==========================================================' >> logs/logs_tcsh
}

log_diff () {
    diff -I '_=*' logs/tmp1 logs/tmp2
    res_diff=$?
    log
}

log_grep () {
    cat logs/tmp1 | grep $1 > logs/tmp1
    cat logs/tmp2 | grep $1 > logs/tmp2
    diff logs/tmp1 logs/tmp2
    res_diff=$?
    log
}

log () {
    if [ $verbose = 'y' ]
    then
	if [ $res_diff -ne 0 ]
	then
	    out='Output : KO'
	else
	    out='Output : OK'
	fi
	if [ $ret1 -eq $ret2 ]
	then
	    ret="Return : OK ($ret1)"
	else
	    ret="Return : KO ($ret1 / $ret2)"
	fi
	if [ $res_diff -ne 0 ] || [ ! $ret1 -eq $ret2 ]
	then
	    echo $out >> logs/logs.txt
	    echo $ret >> logs/logs.txt
	    echo '-------------------------> OUTPUT : ./mysh <-------------------------' >> logs/logs.txt
	    cat logs/tmp1 >> logs/logs.txt
	    echo '-------------------------> OUTPUT : tcsh   <-------------------------' >> logs/logs.txt
	    cat logs/tmp2 >> logs/logs.txt
	    echo '-------------------------> OUTPUT : diff   <-------------------------' >> logs/logs.txt 
	    diff -I '_=*' logs/tmp1 logs/tmp2 >> logs/logs.txt 2>&1
	else
	    echo 'OK' >> logs/logs.txt
	fi
	echo $out
	echo $ret
	echo $out >> logs/logs_mysh
	echo $ret >> logs/logs_mysh
	echo $out >> logs/logs_tcsh
	echo $ret >> logs/logs_tcsh
	cat logs/tmp1 >> logs/logs_mysh
	cat logs/tmp2 >> logs/logs_tcsh
    fi
}

one () {
    if [ $verbose = 'y' ]
    then
	title
	echo $1 $2
	echo $1 $2 >> logs/logs.txt
	echo $1 $2 >> logs/logs_mysh
	echo $1 $2 >> logs/logs_tcsh
	title
    fi
    echo $2 | ./mysh > logs/tmp1 2>&1
    ret1=$?
    echo $2 | tcsh > logs/tmp2 2>&1
    ret2=$?
    log_diff
}

two () {
    if [ $verbose = 'y' ]
    then
	title
	echo $1 '(' $2 ';' $3 ')'
	echo $1 '(' $2 ';' $3 ')' >> logs/logs.txt
	echo $1 '(' $2 ';' $3 ')' >> logs/logs_mysh
	echo $1 '(' $2 ';' $3 ')' >> logs/logs_tcsh
	title
    fi
    (echo $2 ; echo $3) | ./mysh > logs/tmp1 2>&1
    ret1=$?
    (echo $2 ; echo $3) | tcsh > logs/tmp2 2>&1
    ret2=$?
    log_diff
}

three() {
    if [ $verbose = 'y' ]
    then
	title
	echo $1 '(' $2 ';' $3 ';' $4 ')'
	echo $1 '(' $2 ';' $3 ';' $4 ')' >> logs/logs.txt
	echo $1 '(' $2 ';' $3 ';' $4 ')' >> logs/logs_mysh
	echo $1 '(' $2 ';' $3 ';' $4 ')' >> logs/logs_tcsh
	title
    fi
    (echo $2 ; echo $3 ; echo $4) | ./mysh > logs/tmp1 2>&1
    ret1=$?
    (echo $2 ; echo $3 ; echo $4) | tcsh > logs/tmp2 2>&1
    ret2=$?
    log_diff
}

foor() {
    if [ $verbose = 'y' ]
    then
	title
	echo $1 '(' $2 ';' $3 ';' $4 ';' $5 ')'
	echo $1 '(' $2 ';' $3 ';' $4 ';' $5 ')' >> logs/logs.txt
	echo $1 '(' $2 ';' $3 ';' $4 ';' $5 ')' >> logs/logs_mysh
	echo $1 '(' $2 ';' $3 ';' $4 ';' $5 ')' >> logs/logs_tcsh
	title
    fi
    (echo $2 ; echo $3 ; echo $4 ; echo $5) | ./mysh > logs/tmp1 2>&1
    ret1=$?
    (echo $2 ; echo $3 ; echo $4 ; echo $5) | tcsh > logs/tmp2 2>&1
    ret2=$?
    log_diff
}

if [ $# -eq 1 ]
then
    if [ $1 = 'h' ] || [ $1 = 'help' ] || [ $1 = '-h' ] || [ $1 = '-help' ]
    then
	echo 'Cette mini moulinette n est pas parfaite et risque de ne pas vous envoyer exactement les bons resultats!'
	echo 'Elle compare des commandes envoyee sur votre ./mysh puis au tcsh lui meme.'
	echo 'Je vous conseille de l utiliser sur votre Blinux ainsi qu en la lancant depuis le tcsh lui meme (pour l environnement)'
	echo ''
	echo 'Jetez un oeil au dossier logs qui sera cree pour l occasion avec 3 fichiers logs importants:'
	echo '- logs.txt -> recapitule tout ce que vous devez savoir sur ce qu il s est passe'
	echo '- logs.mysh -> seulement le mysh'
	echo '- logs.tcsh -> seulement le tcsh'
	echo ''
	echo 'De plus, la mouli cree des fichiers .c qui sont au prealable compiles.'
	echo 'Ils effectuent des programmes pas tres gentils qui crashent ou return une valeur precise.'
	echo ''
	echo 'Je ne suis pas responsable si vous pushez le dossier logs avec des fichiers .c qui ne sont pas a la norme ;)'
	echo 'Cree par Fouchter Thery (thery.fouchter@epitech.eu)'
	exit
    fi
fi
init
title '---------------- start ----------------'
one '---_empty_---' ''
echo '---_filled_spaces_---'
title
echo '---_filled_spaces_---' >> logs/logs.txt
echo '---_filled_spaces_---' >> logs/logs_mysh
echo '---_filled_spaces_---' >> logs/logs_tcsh
title
echo '                ' | ./mysh > logs/tmp1 2>&1
ret1=$?
echo '                ' | tcsh > logs/tmp2 2>&1
ret2=$?
log_diff
echo '---_filled_tabs_---'
title
echo '---_filled_tabs_---' >> logs/logs.txt
echo '---_filled_tabs_---' >> logs/logs_mysh
echo '---_filled_tabs_---' >> logs/logs_tcsh
title
echo '			' | ./mysh > logs/tmp1 2>&1
ret1=$?
echo '			' | tcsh > logs/tmp2 2>&1
ret2=$?
log_diff
one '---_simple_command_---' 'pwd'
one '---_multiple_args_---' 'ls -la'
one '---_multiple_args_---' 'ls -l -a'
one '---_invalid_arg_---' 'ls -w'
one '---_invalid_command_---' 'hello'
echo '---_simple_command_with_spaces---' '    pwd     '
title
echo '---_simple_command_with_spaces---' '    pwd     ' >> logs/logs.txt
echo '---_simple_command_with_spaces---' '    pwd     ' >> logs/logs_mysh
echo '---_simple_command_with_spaces---' '    pwd     ' >> logs/logs_tcsh
title
echo '    pwd     ' | ./mysh > logs/tmp1 2>&1
ret1=$?
echo '    pwd     ' | tcsh > logs/tmp2 2>&1
ret2=$?
log_diff
echo '---_multiple_args_with_spaces---' '  ls    -l       -a     '
title
echo '---_multiple_args_with_spaces---' '  ls    -l       -a     ' >> logs/logs.txt
echo '---_multiple_args_with_spaces---' '  ls    -l       -a     ' >> logs/logs_mysh
echo '---_multiple_args_with_spaces---' '  ls    -l       -a     ' >> logs/logs_tcsh
title
echo '  ls    -l       -a     ' | ./mysh > logs/tmp1 2>&1
ret1=$?
echo '  ls    -l       -a     ' | tcsh > logs/tmp2 2>&1
ret2=$?
log_diff
echo '---_multiple_args_with_tabs---' '	ls		-l	-a	'
title
echo '---_multiple_args_with_tabs---' '	ls		-l	-a	' >> logs/logs.txt
echo '---_multiple_args_with_tabs---' '	ls		-l	-a	' >> logs/logs_mysh
echo '---_multiple_args_with_tabs---' '	ls		-l	-a	' >> logs/logs_tcsh
title
echo '	ls		-l	-a	' | ./mysh > logs/tmp1 2>&1
ret1=$?
echo '	ls		-l	-a	' | tcsh > logs/tmp2 2>&1
ret2=$?
log_diff
echo '---_multiple_args_with_tabs_and_spaces---' '  	ls	  	  -l	 -a  	 '
title
echo '---_multiple_args_with_tabs_and_spaces---' '  	ls	  	  -l	 -a  	 ' >> logs/logs.txt
echo '---_multiple_args_with_tabs_and_spaces---' '  	ls	  	  -l	 -a  	 ' >> logs/logs_mysh
echo '---_multiple_args_with_tabs_and_spaces---' '  	ls	  	  -l	 -a  	 ' >> logs/logs_tcsh
title
echo '  	ls	  	  -l	 -a  	 ' | ./mysh > logs/tmp1 2>&1
ret1=$?
echo '  	ls	  	  -l	 -a  	 ' | tcsh > logs/tmp2 2>&1
ret2=$?
log
one '---_basic_exec_---' 'logs/hello'
one '---_spe_basic_exec_---' './logs/hello'
one '---_spe_basic_exec_---' 'logs/../logs/hello'
one '---_spe_basic_exec_---' './logs/../logs/hello'
one '---_error_path_exec_---' '/ls'
one '---_error_folder_exec_---' 'bin/ls'
one '---_path_exec_---' '/bin/ls'
one '---_segfault_exec_---' 'logs/segfault'
one '---_no_rights_exec_---' 'logs/hello_nw'
one '---_floating_exec_---' 'logs/float'
one '---_error_exec_---' './hello'
one '---_basic_return_---' 'logs/42'
two '---_basic_cd_---' 'cd logs' 'pwd'
two '---_basic_spe_cd_---' 'cd .' 'pwd'
two '---_basic_spe_cd_---' 'cd ..' 'pwd'
two '---_empty_cd_---' 'cd' 'pwd'
two '---_path_cd_---' 'cd /' 'pwd'
two '---_path_cd_---' 'cd /bin' 'pwd'
foor '---_old_cd_---' 'cd logs' 'pwd' 'cd -' 'pwd'
foor '---_old_cd_---' 'cd' 'pwd' 'cd -' 'pwd'
two '---_cd_error---' 'cd a b' 'pwd'
two '---_cd_error---' 'cd /root' 'pwd'
foor '---_advanced_cd_---' 'cd -- logs' 'pwd' 'cd -- -' 'pwd'
foor '---_advanced_cd_---' 'cd --' 'pwd' 'cd - --' 'pwd'
two '---_advanced_error_cd_---' 'cd - logs' 'pwd'
two '---_advanced_error_cd_---' 'cd -- -' 'pwd'
two '---_advanced_error_cd_---' 'cd -- logs -' 'pwd'
two '---_advanced_error_cd_---' 'cd /bin/ls' 'pwd'
one '---_basic_env_---' 'env'
one '---_basic_setenv_---' 'setenv'
echo '---_basic_setenv_--- ( setenv one ; env )'
title
echo '---_basic_setenv_--- ( setenv one ; env )' >> logs/logs.txt
echo '---_basic_setenv_--- ( setenv one ; env )' >> logs/logs_mysh
echo '---_basic_setenv_--- ( setenv one ; env )' >> logs/logs_tcsh
title
(echo 'setenv one' ; echo 'env') | ./mysh > logs/tmp1 2>&1
ret1=$?
(echo 'setenv one' ; echo 'env') | tcsh > logs/tmp2 2>&1
ret2=$?
log_grep 'one'
echo '---_basic_setenv_--- ( setenv one two ; env )'
title
echo '---_basic_setenv_--- ( setenv one two ; env )' >> logs/logs.txt
echo '---_basic_setenv_--- ( setenv one two ; env )' >> logs/logs_mysh
echo '---_basic_setenv_--- ( setenv one two ; env )' >> logs/logs_tcsh
title
(echo 'setenv one two' ; echo 'env') | ./mysh > logs/tmp1 2>&1
ret1=$?
(echo 'setenv one two' ; echo 'env') | tcsh > logs/tmp2 2>&1
ret2=$?
log_grep 'one'
two '---_error_setenv_---' 'setenv one two three' 'env'
two '---_error_setenv_---' 'setenv one=two three' 'env'
echo '---_check_setenv_--- ( setenv one_two three ; env )'
title
echo '---_check_setenv_--- ( setenv one_two three ; env )' >> logs/logs.txt
echo '---_check_setenv_--- ( setenv one_two three ; env )' >> logs/logs_mysh
echo '---_check_setenv_--- ( setenv one_two three ; env )' >> logs/logs_tcsh
title
(echo 'setenv one_two three' ; echo 'env') | ./mysh > logs/tmp1 2>&1
ret1=$?
(echo 'setenv one_two three' ; echo 'env') | tcsh > logs/tmp2 2>&1
ret2=$?
log_grep 'one_two'
two '---_error_setenv_---' 'setenv 42onetwo three' 'env'
echo '---_check_setenv_--- ( setenv one42two three ; env )'
title
echo '---_check_setenv_--- ( setenv one42two three ; env )' >> logs/logs.txt
echo '---_check_setenv_--- ( setenv one42two three ; env )' >> logs/logs_mysh
echo '---_check_setenv_--- ( setenv one42two three ; env )' >> logs/logs_tcsh
title
(echo 'setenv one42two three' ; echo 'env') | ./mysh > logs/tmp1 2>&1
ret1=$?
(echo 'setenv one42two three' ; echo 'env') | tcsh > logs/tmp2 2>&1
ret2=$?
log_grep 'one42two'
three '---_basic_unsetenv_---' 'setenv hello' 'unsetenv hello' 'env'
three '---_basic_unsetenv_---' 'setenv hello' 'unsetenv hello' 'env'
foor '---_multiple_unsetenv_---' 'setenv hello' 'setenv world' 'unsetenv hello world' 'env'
two '---_error_unsetenv_---' 'unsetenv' 'env'
echo '---_check_no_env_--- ( env -i ./mysh ( pwd ) )'
title
echo '---_check_no_env_--- ( env -i ./mysh ( pwd ) )' >> logs/logs.txt
echo '---_check_no_env_--- ( env -i ./mysh ( pwd ) )' >> logs/logs_mysh
echo '---_check_no_env_--- ( env -i ./mysh ( pwd ) )' >> logs/logs_tcsh
title
(echo 'pwd') | env -i ./mysh > logs/tmp1 2>&1
ret1=$?
(echo 'pwd') | env -i tcsh > logs/tmp2 2>&1
ret2=$?
log_diff
two '---_error_arg_---' '/usr/bin' 'pwd'
title '---------------- done ! ---------------'
