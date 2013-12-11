#
# Makefile for yuv to gpl
#

ENCODER = ../h265/bin/vc10/Win32/Release/TAppencoder.exe
PLOT = "c:/Program Files (x86)/gnuplot/bin/wgnuplot.exe" 
CONFIG = C:/Users/jiro_iwai/Documents/H265/h265/cfg/encoder_randomaccess_main.mod.cfg


FRAME = 150
QP = 30
FRAMERATE = 30
WIDTH = 352
HIGHT = 288

TMP = tmp.bin

YUVDIR = C:/Users/jiro_iwai/Documents/H265/Video/cif

YUVS = \
	BigBuckBunny_CIF_24fps.yuv
#	ElephantsDream_CIF_24fps.yuv\
	bus_cif.yuv\
	bridge-close_cif.yuv\
	bridge-far_cif.yuv\
	flower_cif.yuv\
	foreman_cif.yuv\
	hall_cif.yuv\
	highway_cif.yuv\
	mobile_cif.yuv\
	mother-daughter_cif.yuv\
	news_cif.yuv\
	paris_cif.yuv\
	silent_cif.yuv\
	stefan_cif.yuv\
	tempete_cif.yuv\
	waterfall_cif.yuv

GPLS = $(YUVS:.yuv=.gpl)

GGS = $(GPLS:.gpl=.gg)

all: $(GPLS)

bit: $(GGS)

clean: 
	rm -f $(GPLS)
	rm -f *.bin
	rm -f tmp*.txt

%.gpl : %.yuv
	echo "#POC TId SLICE nQP QP  bits     level stbits   alpha   bata    Lambada Y      U      V      avgQ     vgLmbd   pdLmbd   pdAlpha  pdBeta  cpb" > tmp1.txt 
	echo "#1   2   3     4   5   6        7     8        9       10      11      12     13     14     15       16       17       18       19      20" >> tmp1.txt
	$(ENCODER) -c $(CONFIG) -i $(YUVDIR)/$< -b $(TMP) -wdt $(WIDTH) -hgt $(HIGHT) -fr $(FRAMERATE) -f $(FRAME) -q $(QP) | tee tmp2.txt 
	grep "^ [0-9]" tmp2.txt > tmp3.txt
	cat tmp1.txt tmp3.txt > $@
	rm -fr tmp?.txt

%.gg : %.gpl
	$(PLOT) -e "set terminal png; set output \"$*-bit.png\"; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\""
	$(PLOT) -e "set terminal png; set output \"$*-bit-lambda.png\"; set y2tics; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; set y2label \"lambda\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\", \"$<\" using 11 w l axes x1y2 title \"$* lambda\""
	$(PLOT) -e "set terminal png; set output \"$*-bit-alpha.png\"; set y2tics; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; set y2label \"alpha\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\", \"$<\" using 9 w l axes x1y2 title \"$* alpha\""
	$(PLOT) -e "set terminal png; set output \"$*-bit-beta.png\"; set y2tics; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; set y2label \"beta\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\", \"$<\" using 10 w l axes x1y2 title \"$* beta\""
	$(PLOT) -e "set terminal png; set output \"$*-lambda-Q.png\"; set xlabel \"lambda\"; set ylabel \"Q\"; plot \"$<\" using 11:5 title \"$* lamda-Q\""
	$(PLOT) -e "set terminal png; set output \"$*-Q-YPSN.png\"; set xlabel \"Q\"; set ylabel \"YPSN\"; plot \"$<\" using 5:12 title \"$* Q-YPSN\""
	$(PLOT) -e "set terminal png; set output \"$*-bit-cpb.png\"; set y2tics; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; set y2label \"cpb bit\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\", \"$<\" using 20 w l axes x1y2 title \"$* cpb bit\""
	$(PLOT) -e "set terminal png; set output \"$*-bit-YPSN.png\"; set y2tics; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; set y2label \"YPSN\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\", \"$<\" using 12 w l axes x1y2 title \"$* YPSN\""
	$(PLOT) -e "set terminal png; set output \"$*-bit-Q.png\"; set y2tics; set xlabel \"frame\"; set ylabel \"bit [bpp]\"; set y2label \"Q\"; plot \"$<\" using 6 w l title \"$* bit\", \"$<\" using 8 w l title \"$* est bit\", \"$<\" using 5 w l axes x1y2 title \"$* Q\""
	touch $@