#
# my_champion.s for corewar
#
# Monty Criel
# Sun Feb 26 22:05:30 2017
#

.name "my_champion"
.comment "best wall ever"

l1:	sti r1,%:lab,%1
	and r1,%0,r1
	fork %200
	sti r5,%:l1,%0

lab:	live %420
	zjmp %:lab

zeus:	ld %42,r2
	ld %3,r7
	ld %4,r8
	ld %5,r9

trump:	live %42
	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
    	st r8,-420
	zjmp %:trump
