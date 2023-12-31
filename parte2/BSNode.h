#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
	    public:
		    //atributos
		    T elem;
		    BSNode<T>* left;
		    BSNode<T>* right;


		    //metodos
		    BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr): elem{elem} {}
		    
		    friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
			    out << bsn.elem;
			    return out;
		    }
};

			    
#endif
