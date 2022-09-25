#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class HashTable{
    public:
        virtual void insert(string key, string value) = 0; // Virtual se utiliza para polimorfismo, y el =0 identifica una función pura.
        virtual bool exist(string key) = 0;
        virtual string get(string key) = 0;
        virtual void remove (string key) = 0;

}

struct HashTableNode {
    string key;
    string value;
    HashTableNode *next;
    /* 
    CONSTRUCTOR:
                HashTableNode(string _key, string _value){
                    key = _key;
                    value = _value;
                    next = NULL;
                }
    */
   HashTableNode(string _key, string _value) : key(_key), value(_value), next(NULL){}
};

class HashTableImp : public HashTable {
    private:
        // Atributos y funciones auxiliares
        HashTableNode ** arr;
        int size;

        int hash(string key){
            int h = 0;
            for (int i = 0; i < key.length(); i++){
                h = 31 * h + int(key[i]);
            }
            return h;
        }

        void insertNode(string key, string value, HashTableNode *& ptrNode){
            if (ptrNode == NULL){
                ptrNode = new HashTableNode(key, value);
            } else {
                // Key already exists
                if (ptrNode->key == key){
                    ptrNode->value = value;
                } else{
                    insertNode(key, value, ptrNode->next);
                }
            }
        }

        bool existeRec (string key, HashTableNode *ptrNode){
            if (ptrNode == NULL){
                return false;
            } else if (ptrNode->key == key){
                return true;
            } else {
                return existeRec(key, ptrNode->next);
            }
        }

        string getRec(string key, HashTableNode *ptrNode){
            assert(ptrNode != NULL);
            if(ptrNode->key == key){
                return ptrNode->value;
            }
            return getRec(key, ptrNode->next);
        }

    public:
        // Constructor 
        HashTableImp(int _size){
            size = _size
            arr = new HashTableNode*[size];
            for (int i = 0; i < size; i++){
                arr[i] = NULL; 
            }
        }
        void insert(string key, string value){
            int hashValue = this->hash(key);
            // Normalize 
            int index = abs(hashValue) % size;
            insertNode (key, value, arr[index]);

        }
        bool exist(string key){
            int hashValue = this->hash(key);
            int index = abs(hashValue) % size;
            return existRec(key, arr[index]);
        }
        string get(string key){
            assert(exist(key));
            int hashValue = this->hash(key);
            int index = abs(hashValue) % size;
            return getRec(key, arr[index]);
        }
        void remove(string key){
            // No implementado.
        }
};


int main()
{
    HashTable *ht = new HashTableImp(10);
    ht->insert("123456789", "Juan");
    ht->insert("987654321", "Pepe");
    ht->insert("543217892", "Florencia");
    ht->insert("234128882", "Joaquin");
    ht->insert("232142455", "Ana");

    return 0;
}
/*
OPCIÓN ITERATIVA DE INSERTAR:

        void insert(string key, string value){
            int hashValue = this->hash(key);
            // Normalize 
            int index = abs(hashValue) % size;
            if (arr[index] == NULL){
                arr[index] = new HashTableNode(key, value);
            } else {
                HashTableNode *ptrAux = arr[index];
                bool inserted = false;
                while(!inserted){
                    if (ptrAux->key == key){
                        ptrAux->value = value;
                        inserted = true;
                    } else if(ptrAux->next == NULL){
                        ptr->next = new HashTableNode(key, value);
                        inserted = true;
                    }
                    ptrAux = ptrAux->next;
                }
            }

        }
*/ 