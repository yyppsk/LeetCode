#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
};

// Function to add a node to the linked list
void addNode(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Function to find the length of the linked list
int length(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Function to perform binary search on a linked list
int binarySearch(Node *head, int value)
{
    int len = length(head);
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        Node *current = head;
        for (int i = 0; i < mid; i++)
        {
            current = current->next;
        }
        if (current->data == value)
        {
            return mid;
        }
        else if (current->data < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

// Main function
int main()
{
    Node *head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    int value = 30;
    int index = binarySearch(head, value);
    if (index == -1)
    {
        cout << "Value not found in the linked list" << endl;
    }
    else
    {
        cout << "Value found at index " << index << endl;
    }
    return 0;
}
