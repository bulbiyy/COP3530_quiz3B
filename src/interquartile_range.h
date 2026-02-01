/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>
class Node {
public:
    int value;
    Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    //code here
    int n = 0;
    for (Node* c = head; c != nullptr; c = c->next) n++;

    int lowerStart = 0;
    int lowerLen   = n / 2;
    int upperStart = (n + 1) / 2;
    int upperLen   = n / 2;

    auto getAt = [&](int idx) -> int {
        Node* c = head;
        while (idx-- > 0) c = c->next;
        return c->value;
    };

    auto medianSeg = [&](int start, int len) -> double {
        int mid = start + len / 2;
        if (len % 2 == 1) {
            return static_cast<double>(getAt(mid));
        } else {
            long long a = getAt(mid - 1);
            long long b = getAt(mid);
            return (a + b) / 2.0;
        }
    };

    double Q1 = medianSeg(lowerStart, lowerLen);
    double Q3 = medianSeg(upperStart, upperLen);

    return static_cast<float>(Q3 - Q1);
}