graph4.png : Clase_29.dat Grafica.py
	python Grafica.py

graph3.png : Clase_29.dat Grafica.py
	python Grafica.py

graph2.png : Clase_29.dat Grafica.py
	python Grafica.py

graph1.png : Clase_29.dat Grafica.py
	python Grafica.py
	

Clase_29.dat : Clase_29.x
	./Clase_29.x 

Clase_29.x : Clase_29.cpp
	c++ Clase_29.cpp -o Clase_29.x
	
clean : 
	rm Clase_29.x Clase_29.dat Clase_29_2.dat graph1.png graph2.png