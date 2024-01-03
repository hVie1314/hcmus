#include <iostream>
#include<vector>

using namespace std;

const int HASH_SIZE = 10;
const int HASH_PRIME = 17;
const int EMPTY_SLOT = -1;
vector<int> hashTable(HASH_SIZE, EMPTY_SLOT);

int hashFunction1(int key) 
{
    return key % HASH_SIZE;
}

int hashFunction2(int key) 
{
    return HASH_PRIME - (key % HASH_PRIME);
}

void insert(int key) 
{
    int index = hashFunction1(key);
    int index2 = hashFunction2(key);
    int h = 0;
    while (hashTable[index] != EMPTY_SLOT) 
    {
        index = (index + h * index2) % HASH_SIZE;
        ++h;
    }
    hashTable[index] = key;
}

int search(int key) 
{
    int index = hashFunction1(key);
    int index2 = hashFunction2(key);
    int h = 0;
    while (hashTable[index] != key && hashTable[index] != EMPTY_SLOT) 
    {
        index = (index + h * index2) % HASH_SIZE;
        ++h;
    }
    if (hashTable[index] == key) 
    {
        return index;
    }
    return -1;
}

void deleteKey(int key) 
{
    int index = search(key);
    if (index != -1) 
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
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    // Print the hash table
    printHashTable();

    // Search for some keys
    for (int key = 10; key <= 80; key += 10) {
        if (search(key) != -1) {
            cout << "Key " << key << " found." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    // Delete some keys
    deleteKey(20);
    deleteKey(40);
    deleteKey(60);

    // Print the hash table again
    printHashTable();

    // Search for the keys again
    for (int key = 10; key <= 80; key += 10) {
        if (search(key) != -1) {
            cout << "Key " << key << " found." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    return 0;
}

