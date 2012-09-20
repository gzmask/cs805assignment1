noweb -t as1.tex
cp as1.tex latex/as1.tex
cd latex
texi2pdf as1.tex
rm as1.aux as1.log as1.out as1.tex
exit 0
