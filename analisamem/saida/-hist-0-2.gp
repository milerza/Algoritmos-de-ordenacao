set term postscript eps color 14
set output "./saida/-hist-0-2.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 37 - Fase  0 - ID 2"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:3] "./saida/-hist-0-2.gpdat" u 3:4 w boxes t ""
