#include <iostream>
#include <vector>

using namespace std;

const int HASH_SIZE = 10;
const int EMPTY_SLOT  = -1;
vector<int> hashTable(HASH_SIZE, EMPTY_SLOT);

int hashFunction(int key)
{
    return key % HASH_SIZE;
}

void insert(vector<int>& hashTable, int key)
{
    int index = hashFunction(key);
    int h = 1;
    while (hashTable[index] != EMPTY_SLOT)
    {
        index = (index + h * h) % HASH_SIZE;
    }
    hashTable[index] = key;
}

int search(vector<int>& hashTable, int key)
{
    int index = hashFunction(key);
    int h = 1;
    while (hashTable[index] != EMPTY_SLOT)
    {
        if (hashTable[index] == key)
        {
            return index;
        }
        index = (index + h * h) % HASH_SIZE;
    }
    return -1;
}

void deleteKey(vector<int>& hashTable, int key)
{
    int index = search(hashTable, key);
    if (index == -1)
    {
        return;
    }
    else 
    {
        hashTable[index] = EMPTY_SLOT;
    }
}

void printHashTable() 
{
    for (int i = 0; i < HASH_SIZE; ++i) 
    {
        cout << hashTable[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Insert some keys
    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 40);
    insert(hashTable, 50);
    insert(hashTable, 60);

    printHashTable();

    // Search for some keys
    for (int key = 10; key <= 60; key += 10) {
        if (search(hashTable, key) != -1) {
            cout << "Key " << key << " found." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    // Delete some keys
    deleteKey(hashTable, 20);
    deleteKey(hashTable, 40);
    deleteKey(hashTable, 60);

    printHashTable();

    // Search for the keys again
    for (int key = 10; key <= 60; key += 10) {
        if (search(hashTable, key) != -1) {
            cout << "Key " << key << " found." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    return 0;
}