all: test usecase visualize

test: test_bst.cpp bst.cpp bst.h
	g++ test_bst.cpp bst.cpp -o test

usecase: main.cpp bst.cpp bst.h usecase.cpp
	g++ main.cpp usecase.cpp bst.cpp -o usecase

visualize: visualization.cpp bst.cpp bst.h
	g++ visualization.cpp -o visualize

clean:
	rm -f test usecase visualize