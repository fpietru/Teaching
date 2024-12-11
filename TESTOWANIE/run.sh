i=0
while true
do
	./gen $i > in1
	./brut < in1 > out1
	./wzo < in1 > out2
	wynik='diff -w -q out1 out2'
	if [ "$wynik" == ""	]; then # diff zwraca 0 jeśli pliki są takie same
		echo "OK $i"                    # -w ignoruje białe znaki
	else                                # -q zwraca wart. iff różne pliki
		echo "WA $i"
		echo "Wejscie:"
		echo in1
		echo "Brut:"
		echo out1
		echo "Rozw:"
		echo out2
		break
	fi
	((i++))
done