#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable : public Dict<V> {
private:
    int n;
    int max;
    ListLinked<TableEntry<V>>* table;

    int h(std::string key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % max;
    }

public:
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max];
    }

    ~HashTable() {
        delete[] table;
    }

    int capacity() const {
        return max;
    }

    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& th) {
        for (int i = 0; i < th.max; ++i) {
            out << "Cubeta " << i << ": ";
            for (auto it = th.table[i].begin(); it != th.table[i].end(); ++it) {
                out << "[" << it->key << ", " << it->value << "] ";
            }
            out << std::endl;
        }
        return out;
    }

    V operator[](std::string key) {
        int index = h(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                return it->value;
            }
        }
        throw std::runtime_error("Clave no encontrada");
    }
};

#endif

