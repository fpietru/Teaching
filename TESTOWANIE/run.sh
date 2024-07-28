make gen
make wzo
make brut
i=0
while true
do
	./gen $i > in1
	./brut < in1 > out1
	./wzo < in1 > out2
	if diff out1 out2 > res; then
		echo "OK $i"
	else
		echo "WA $i"
		echo "Wejscie:"
		cat in1
		echo "Brut:"
		cat out1
		echo "Wzo:"
		cat out2
		break
	fi
	((i++))
done
