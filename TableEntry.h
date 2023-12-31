#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
	class TableEntry {
		public:
			//atributos
    			std::string key;
    			V value;

			//metodos
    			TableEntry(std::string key, V value) : key(key), value(value) {}

                        TableEntry(std::string key) : key(key), value() {}

                        TableEntry() : key(""), value() {}

    			//operador == 
    			friend bool operator==(const TableEntry<V> &TE1, const TableEntry<V> &TE2) {
        			return TE1.key == TE2.key;
    			}

    			//operador != 
    			friend bool operator!=(const TableEntry<V> &TE1, const TableEntry<V> &TE2) {
        			return TE1.key != TE2.key;
    			}

    			//operador <<
    			friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &TE) {
        			out << "(" << TE.key << ", " << TE.value << ")";
        			return out;
    			}

			//operador < (parte2)
			friend bool operator < (const TableEntry<V> &TE1, const TableEntry<V> &TE2) {
				return TE1.key < TE2.key;
			}	

			//operador > (parte2)
			friend bool operator > (const TableEntry<V> &TE1, const TableEntry<V> &TE2) {
				return TE1.key > TE2.key;
			}
	};

#endif

