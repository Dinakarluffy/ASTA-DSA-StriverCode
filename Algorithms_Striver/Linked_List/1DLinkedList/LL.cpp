#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;        // Data stored in the node
    Node<T> *next; // Pointer to the next node in the linked list

    // Constructor
    Node(T data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor for initializing only the data
    Node(T data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
Node<int> *convertArr(vector<int> &arr)
{
    Node<int> *head = new Node<int>(arr[0]);
    Node<int> *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node<int> *temp = new Node<int>(arr[i]);
        mover->next = temp;
        mover = temp; // Move the pointer to the new node
    }
    return head;
}

// Function to calculate the length of a linked list
int lengthOfLL(Node<int> *head)
{
    int cnt = 0;
    Node<int> *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Function to search a value in the linked list
bool SearchLL(Node<int> *head, int val)
{
    Node<int> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
Node<int> *deleteNodeHead(Node<int> *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node<int> *temp = head;
    head = head->next;

    delete temp; // or free(temp);
    return head;
}
Node<int> *deleteNodeTail(Node<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node<int> *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}
Node<int> *deleteKthElement(Node<int> *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node<int> *prev = NULL;
    Node<int> *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;

        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node<int> *deleteElementByValue(Node<int> *head, int el)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == el)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node<int> *prev = NULL;
    Node<int> *temp = head;

    while (temp != NULL)
    {

        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
Node<int> *insertHead(Node<int> *head, int val)
{
    Node<int> *temp = new Node<int>(val, head);

    return temp;
}
Node<int> *insertTail(Node<int> *head, int val)
{
    if (head == NULL)
    {
        return new Node<int>(val);
    }
    Node<int> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node<int> *newNode = new Node<int>(val);
    temp->next = newNode;
    return head;
}
Node<int> *insertKThElement(Node<int> *head, int k, int el)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node<int>(el);
        }
        else
        {
            head;
        }
    }
    if (k == 1)
    {
        Node<int> *newNode = new Node<int>(el);
        newNode->next = head;
        return newNode;
    }
    int cnt = 0;
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node<int> *newNode = new Node<int>(el, temp->next); // or newNode->next = temp->next;

            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node<int> *insertBeforeValue(Node<int> *head, int value, int el)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == value)
    {
        return new Node<int>(el, head);
    }
    
    Node<int> *temp = head;
    while (temp->next != NULL)
    {
        
        if (temp->next->data==value)
        {
            Node<int> *newNode = new Node<int>(el, temp->next); // or newNode->next = temp->next;

            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    // Create a Node 'x' with the first element of the vector and a null next reference
    Node<int> x = Node<int>(arr[0], nullptr);
    Node<int> *y = &x;
    cout << "Memory address of Node x: " << y << '\n'; // Print address of node

    // Convert vector to linked list
    Node<int> *head = convertArr(arr);

    // Print the first data in the linked list
    cout << "First data in the list: " << head->data << endl;

    // Print all data in the linked list
    Node<int> *temp = head;
    cout << "Linked list contents: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Print the length of the linked list
    int cnt = lengthOfLL(head);
    cout << "Length of linked list: " << cnt << endl;

    // Search for a value in the linked list
    int searchVal = 1;
    bool found = SearchLL(head, searchVal);
    cout << "Is value " << searchVal << " present in the list? " << (found ? "Yes" : "No") << endl;
    Node<int> *h = convertArr(arr);
    h = deleteElementByValue(h, 7);
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
    Node<int> *h1 = convertArr(arr);
    h1 = insertHead(h1, 7);
    while (h1 != NULL)
    {
        cout << h1->data << " ";
        h1 = h1->next;
    }
    cout << endl;
    Node<int> *h3 = convertArr(arr);

    h3 = insertTail(h3, 7);

    while (h3 != NULL)
    {
        cout << h3->data << " ";
        h3 = h3->next;
    }
    cout << endl;
    cout << "Inset at Kth element" << endl;
    Node<int> *h4 = convertArr(arr);

    h4 = insertKThElement(h4, 5, 7);
    //{2, 5, 8, 7}
    while (h4 != NULL)
    {
        cout << h4->data << " ";
        h4 = h4->next;
    }
    cout << endl;
    cout << "Inset at before element" << endl;
    Node<int> *h5 = convertArr(arr);

    h5 = insertBeforeValue(h5, 7,100);
    //{2, 5, 8, 7}
    while (h5 != NULL)
    {
        cout << h5->data << " ";
        h5 = h5->next;
    }

    return 0;
}
