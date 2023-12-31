#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "BSTree.h"
#include "../Dict.h"
#include "../TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

	    private:
		    //atributo
	            BSTree<TableEntry<V>>* tree;
			    
	    public:
		    //metodos
		    BSTreeDict(){
		    	tree = new BSTree<TableEntry<V>>();
		    }

		    ~BSTreeDict(){
		    	delete tree;
		    }

		    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
			    if(bs.tree->size() > 0){
			    	out << bs.tree[0] << std::endl;
			    }
			    return out;
		    }

		    V operator[](std::string key){
		    	return tree->search(TableEntry<V>(key)).value;
		    }

		    void insert(std::string key, V value){
		    	tree->insert(TableEntry<V>(key, value));
		    }

		    V search(std::string key){
		    	return tree->search(TableEntry<V>(key)).value;	
		    }

		    V remove(std::string key){
		    	V res = tree->search(TableEntry<V>(key)).value;
			tree->remove(TableEntry<V>(key));
			return res;
		    }

		    int entries(){
		    	return tree->size();	
		    }	  			    
};		    
#endif
