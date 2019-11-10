# for use with gnuplot to generate histogram

set title "Collatz Sequence Lengths\nRange: 1 to 10^8"
set xlabel "Sequence length"
set ylabel "Frequency"

set key off
set border 4095
set auto
 
# for 1 to 10^8 the longest sequence length is 949 steps (for the number 63728127)
set xrange[0:1000]
set xtics 50
 
set terminal png enhanced font "Times-New-Roman,14" size 1600, 1200
set output "histogram_seqlen.png"
 
set style histogram clustered gap 0
set style fill solid 
 
binwidth=1
set boxwidth binwidth
bin(x,width)=width*floor(x/width) + width/2.0
 
plot 'data.txt' using (bin($1, 1)):(1.0) smooth freq with boxes linecolor rgb "#00008F"
