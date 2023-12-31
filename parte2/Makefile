bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSNode.h ../TableEntry.h ../Dict.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp


clean:
	rm -rf *.o *.gch bin
