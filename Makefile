
default:
	g++ 

build-solve:
	g++ Solve/_solve.cpp -o Solve/solve.exe

build-rolls:
	g++ Rolls/_rolls.cpp -o roll.exe

run-rolls:
	./roll.exe > Solve/rolls.txt

build-dict:
	g++ Words/_generate_dict.cpp -o generate.exe

run-dict:
	./generate.exe > Solve/dictionary_values.txt

clean:
	rm **/*.exe