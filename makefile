adveccion.png: CL_graph.py advection.txt
	python CL_graph.py
advection.txt:
	./adv > advection.txt
adv: CL_advection.cpp
	c++ CL_advection.cpp -o adv



