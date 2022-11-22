set term postscript eps color 14
set output "./saida/-hist-0-1.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 57 - Fase  0 - ID 1"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:3] "./saida/-hist-0-1.gpdat" u 3:4 w boxes t ""
