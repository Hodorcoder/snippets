# for use with gnuplot to generate histogram

set title "A153330\n1 < n <= 10^8"
set xlabel "n"
set ylabel "Delta"

set key off
set border 4095
set auto
 
set terminal png enhanced font "Times-New-Roman,14" size 1600, 1200
set output "graph_deltas.png"

plot 'data.txt' u 0:1 with lines linecolor rgb "#00008F"
