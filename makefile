all: clean binary_tree


binary_tree: 
	cl /c binary_tree.cpp
	cl /c test.cpp
	lib binary_tree.obj
	link binary_tree.lib test.obj


clean: 
	del *.obj
	del *.exe
	del *.asm
	del *.lib