#
# perf.sh for perf.sh in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/
#
# Made by Hugo Bleuzen
# Login   <hugo.bleuzen@epitech.eu>
#
# Started on  Thu Apr 20 15:25:33 2017 Hugo Bleuzen
# Last update Thu Apr 20 15:36:24 2017 Hugo Bleuzen
#

make -s -C profondeur/
make -s -C astar/
make -s -C generateur/
make -s -C tournoi/
make -s -C largeur/

echo "Generating maze parfait 3000 x 3000..."
./generator/generator 3000 3000 parfait > mazes/tmp.txt
echo "We will test this map with all the algorithms"
time ./breadth/solver mazes/tmp.txt > /dev/null
echo "Algorithm largeur done"
time ./depth/solver mazes/tmp.txt > /dev/null
echo "Algorithm profondeur done"
time ./astar/solver mazes/tmp.txt > /dev/null
echo "Algorithm astar done"
time ./tournoi/solver mazes/tmp.txt > /dev/null
echo "Algorithm tournoi done"

echo "
"
echo "Generating maze imparfait 3000 x 3000..."
./generateur/generateur 3000 3000 imparfait > mazes/tmp.txt
echo "We will test this map with all the algorithms"
time ./largeur/solver mazes/tmp.txt > /dev/null
echo "Algorithm largeur done"
time ./profondeur/solver mazes/tmp.txt > /dev/null
echo "Algorithm profondeur done"
time ./astar/solver mazes/tmp.txt > /dev/null
echo "Algorithm astar done"
time ./tournoi/solver mazes/tmp.txt > /dev/null
echo "Algorithm tournoi done"
rm mazes/tmp.txt
