#include<iostream>
#include<string>
using namespace std;

template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;
    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;
    }
};

template <typename V>
class ourmap{
    MapNode<V>** bucket;
    int count;               //count shows the number of elements in bucket
    int numBucket;          //numBucket shows the current size of bucket
    ourmap(){
        count = 0;
        numBucket = 5;
        bucket = new MapNode<V>*[numBucket];
        for(int i = 0; i < numBucket; i++){
            bucket[i] = NULL;
        }
    }
    private:
    int getBucketIndex(string key){
        int hashCode = 0;
        int currentCoeff = 1;
        for(int i = key.length()-1; i >= 0; i--){
            hashCode += key[i]*currentCoeff;
            hashCode = hashCode % numBucket;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBucket;
        }
        return hashCode % numBucket;
    }
    public:
    int size(){
        return count;
    }
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        while(head != NULL){
            if(head->key = key){
                head->value = value;
                return;
            }
            head->next = NULL;
        }
        head = bucket[bucketIndex];
        MapNode<V>* node = MapNode<V>(key, value);
        node->next = head;
        bucket[bucketIndex] = node;
        count++;    
    }
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    bucket[bucketIndex] = head->next;
                }
                else{
                prev->next = head->next;
                }
                int val = head->value;
                head->next = NULL;
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    ~ourmap(){
        for(int i = 0; i < numBucket; i++){
            delete bucket[i];
        }
        delete [] bucket;
    }

};