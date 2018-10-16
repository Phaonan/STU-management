myapp:
	make -C ./MouduleA
	make -C ./MouduleB
	make -C ./IO
	gcc main.c -o myapp -L ./RELEASE -lio -lcou_menu -lstu_menu -I ./Include

clean:
	rm RELEASE/*
