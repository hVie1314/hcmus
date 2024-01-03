#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int HASH_SIZE = 10;
vector<int> hashTable[HASH_SIZE]; 

int hashFunction(int key)
{
    return key % HASH_SIZE;
}

void insert(vector<int> hashTable[HASH_SIZE], int key)
{
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}

bool search(vector<int> hashTable[HASH_SIZE], int key)
{
    int index = hashFunction(key);
    for (int i = 0; i < hashTable[index].size(); i++)
    {
        if (hashTable[index][i] == key)
        {
            return true;
        }
    }
    return false;
}

void deleteKey(vector<int> hashTable[HASH_SIZE], int key)
{
    if (!search(hashTable, key))
    {
        return;
    }
    int index = hashFunction(key);
    for (std::vector<int>::iterator it = hashTable[index].begin(); it != hashTable[index].end(); ++it)
    {
        if (*it == key)
        {
            hashTable[index].erase(it);
            break;  
        }
    }
}

int main()
{
    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 40);
    insert(hashTable, 50);
    insert(hashTable, 60);

    // Search for some keys
    for (int key = 10; key <= 60; key += 10) {
        if (search(hashTable, key)) {
            cout << "Key " << key << " found." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    // Delete some keys
    deleteKey(hashTable, 20);
    deleteKey(hashTable, 40);
    deleteKey(hashTable, 60);

    // Search for the keys again
    for (int key = 10; key <= 60; key += 10) {
        if (search(hashTable, key)) {
            cout << "Key " << key << " found." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    return 0;
}