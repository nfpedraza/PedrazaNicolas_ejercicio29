graph.png : Clase_29.dat Grafica.py
	python Grafica.py

Clase_29.dat : Clase_29.x
	./Clase_29.x 

Clase_29.x : Clase_29.cpp
	c++ Clase_29.cpp -o Clase_29.x
	
clean : 
	rm Clase_29.x Clase_29.dat graph.png