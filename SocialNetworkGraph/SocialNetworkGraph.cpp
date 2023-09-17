#include <iostream>
#include <string>
using namespace std;

class userProfile {
public:
    int id;
    string name;
    int age;
    string location;
    string institute;
    string password;
    userProfile() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your location: ";
        cin >> location;
        cout << "Enter your institute: ";
        cin >> institute;
        cout << "Enter your password: ";
        cin >> password;
    }

    userProfile(string name, int age, string location, string institute) {
        this->name = name;
        this->age = age;
        this->location = location;
        this->institute = institute;
    }

    void print() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Location: " << location << "\n";
        cout << "Institute: " << institute << "\n";
    }
};

class Node {
public:
    userProfile* user;
    Node* next;

    Node(userProfile* user) {
        this->user = user;
        this->next = NULL;
    }
};

class NodeD {
public:
    userProfile* user;
    NodeD* down;
    Node* side;

    NodeD() {
        this->down = NULL;
        this->side = NULL;
    }

    NodeD(userProfile* user) {
        this->user = user;
        this->down = NULL;
        this->side = NULL;
    }
};

class Queue
{
public:
    Node* front, * rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(userProfile* data)
    {
        Node* ptrN = new Node(data);
        if (front == NULL)
        {
            front = rear = ptrN;
        }
        else
        {
            rear->next = ptrN;
            rear = ptrN;
        }
    }
    userProfile* dequeue()
    {
        Node* t = front;
        front = front->next;
        userProfile* data = t->user;
        delete t;
        return data;
    }
    bool isEmpty()
    {
        bool isempty;
        if (front)
            isempty = false;
        else
            isempty = true;
        return isempty;
    }
    int size()
    {
        Node* t = front;
        int s = 0;
        while (t != NULL)
        {
            s++;
            t = t->next;
        }
        return s;
    }
    void display()
    {
        Node* temp = front;
        cout << "Displaying profiles" << "\n";
        while (temp != NULL)
        {
            temp->user->print();
            temp = temp->next;
        }
    }
    void destroy()
    {
        Node* t = front;
        while (t != NULL)
        {
            Node* temp = t->next;
            delete t;
            t = temp;
        }
        front = NULL;
        rear = NULL;
    }
    userProfile* Front()
    {
        return front->user;
    }
    userProfile* Rear()
    {
        return rear->user;
    }
};

class Stack
{
public:
    Node* top;
    Stack()
    {
        top = NULL;
    }
    void Push(userProfile* data)
    {
        Node* n = new Node(data);
        if (top == NULL)
            top = n;
        else
        {
            n->next = top;
            top = n;
        }
    }
    userProfile* Pop()
    {
        if (top == NULL) {
            cout << "Empty" << "\n";
            return NULL;
        }

        userProfile* p = top->user;
        Node* n = top;
        top = n->next;
        delete n;

        return p;
    }

    int Size()
    {
        Node* t = top;
        int s = 0;
        while (t != NULL)
        {
            s++;
            t = t->next;
        }
        return s;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    void destroy()
    {
        Node* t = top;
        while (t != NULL)
        {
            Node* temp = t->next;
            delete t;
            t = temp;
        }
        top = NULL;
        cout << "Stack is destroyed " << "\n";
    }
    userProfile* Top()
    {
        return top->user;
    }
    void display()
    {
        Node* temp = top;
        cout << "Displaying profiles" << "\n";
        while (temp != NULL)
        {
            temp->user->print();
            temp = temp->next;
        }
    }
};

class Graph {
public:
    NodeD* head;
    int totalUsers;
    int totalConnections;

    Graph() {
        head = NULL;
        totalUsers = 0;
        totalConnections = 0;
    }

    void CreateProfile() {
        userProfile* user = new userProfile();
        NodeD* block = new NodeD(user);
        if (head == NULL) {
            head = block;
            user->id = totalUsers;
            totalUsers++;
        }
        else {
            NodeD* current = head;
            while (current->down != NULL) {
                current = current->down;
            }
            current->down = block;
            user->id = totalUsers;
            totalUsers++;
        }
    }

    void addFriend(string userName, string friendName) {
        NodeD* currentV = SearchNewFriend(userName);
        Node* current = currentV->side;

        if (SearchFriend(friendName, current)) {
            cout << "You have added the user as a friend" << "\n";
            return;
        }
        else {
            Node* newNode = new Node(SearchNewFriend(friendName)->user);

            if (current == NULL) {
                currentV->side = newNode;
            }
            else {
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        NodeD* currentVNext = SearchNewFriend(friendName);
        Node* currentNext = currentVNext->side;

        if (SearchFriend(userName, currentNext)) {
            cout << "You have added the user as a friend" << "\n";
            return;
        }
        else {
            Node* newNodeNext = new Node(SearchNewFriend(userName)->user);

            if (currentNext == NULL) {
                currentVNext->side = newNodeNext;
            }
            else {
                while (currentNext->next != NULL) {
                    currentNext = currentNext->next;
                }
                currentNext->next = newNodeNext;
            }
        }
    }

    NodeD* SearchNewFriend(string name) {
        NodeD* current = head;
        while (current != NULL) {
            if (current->user->name == name) {
                return current;
            }
            else
                current = current->down;
        }
        return NULL;
    }

    Node* SearchFriend(string name, Node* a) {
        Node* current = a;
        while (current != NULL) {
            if (current->user->name == name) {
                return current;
            }
            else
                current = current->next;
        }
        return NULL;
    }
    void displayFriends(NodeD* user) {
        Node* id = user->side;
        while (id != NULL) {
            cout << "Friend Name: " << id->user->name << "\n";
            cout << "Mutual Friends: " << mutualFriend(id->user->name, user->user->name) << "\n";
            id = id->next;
            cout << "\n";
        }
    }

    int mutualFriend(string userName, string friendName) {
        NodeD* currentA = SearchNewFriend(userName);
        NodeD* currentB = SearchNewFriend(friendName);

        if (currentA == NULL || currentB == NULL) {
            cout << "One or both users not found." << endl;
            return 0;
        }
        else {
            Node* tempA = currentA->side;
            Node* tempB = currentB->side;

            int count = 0;
            cout << "Mutual friends names:" << endl;
            while (tempA != NULL) {
                while (tempB != NULL) {
                    if (tempA->user == tempB->user) {
                        cout << tempA->user->name << "\n";
                        count++;
                    }
                    tempB = tempB->next;
                }
                tempA = tempA->next;
                tempB = currentB->side;
            }

            return count;
        }
    }


    void removeFriend(string userName, string friendName) {
        NodeD* currentV = SearchNewFriend(userName);
        Node* current = currentV->side;
        Node* prev = NULL;
        while (current != NULL) {
            if (current->user->name == friendName) {
                if (prev == NULL) {
                    currentV->side = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Friend " << friendName << " not found for user " << userName << endl;
            return;
        }

        NodeD* currentVNext = SearchNewFriend(friendName);
        Node* currentNext = currentVNext->side;
        Node* prevNext = NULL;

        while (currentNext != NULL) {
            if (currentNext->user->name == userName) {
                if (prevNext == NULL) {
                    currentVNext->side = currentNext->next;
                }
                else {
                    prevNext->next = currentNext->next;
                }
                delete currentNext;
                cout << "Removed " << friendName << " from " << userName << "'s friend list." << endl;
                return;
            }
            prevNext = currentNext;
            currentNext = currentNext->next;
        }

        cout << "User " << friendName << " not found in the friend list of " << userName << endl;
    }

    void suggestion(NodeD* userNode) {
        userProfile* startVertex = userNode->user;

        if (!head || userNode == NULL)
            return;

        bool* visited = new bool[totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            visited[i] = false;
        }

        Queue* bfsQueue = new Queue();
        int startUserId = startVertex->id;
        visited[startUserId] = true;
        bfsQueue->enqueue(startVertex);

        while (!bfsQueue->isEmpty()) {
            userProfile* currentVertex = bfsQueue->dequeue();

            NodeD* currentNode = SearchNewFriend(currentVertex->name);
            Node* currentNeighbor = currentNode->side;

            bool isImmediateFriend = false;
            Node* userNodeFriends = userNode->side;
            while (userNodeFriends != NULL) {
                if (userNodeFriends->user == currentVertex) {
                    isImmediateFriend = true;
                    break;
                }
                userNodeFriends = userNodeFriends->next;
            }

            if (currentVertex != startVertex) {
                if (!isImmediateFriend) {
                    if (!SearchFriend(currentVertex->name, userNode->side)) {
                        currentVertex->print();
                        cout << "\n";
                    }
                }
            }

            while (currentNeighbor != NULL) {
                int neighbor = currentNeighbor->user->id;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue->enqueue(currentNeighbor->user);
                }
                currentNeighbor = currentNeighbor->next;
            }
        }

        delete[] visited;
        cout << endl;
    }


    void BFT(userProfile* startVertex) {
        if (!head)
            return;
        bool* visited = new bool[totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            visited[i] = false;
        }
        Queue* bfsQueue = new Queue();
        int startUserId = startVertex->id;
        visited[startUserId] = true;
        bfsQueue->enqueue(startVertex);

        while (!bfsQueue->isEmpty()) {
            userProfile* currentVertex = bfsQueue->dequeue();
            currentVertex->print();
            cout << "\n";
            NodeD* currentNode = SearchNewFriend(currentVertex->name);
            Node* currentNeighbor = currentNode->side;

            while (currentNeighbor != NULL) {
                int neighbor = currentNeighbor->user->id;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue->enqueue(currentNeighbor->user);
                }
                currentNeighbor = currentNeighbor->next;
            }
        }

        delete[] visited;
        cout << endl;
    }

    void BFS(userProfile* startVertex, string friendName) {
        if (!head)
            return;

        userProfile* endVertex = SearchNewFriend(friendName)->user;
        bool* visited = new bool[totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            visited[i] = false;
        }

        Queue* bfsQueue = new Queue();
        int startUserId = startVertex->id;
        visited[startUserId] = true;
        bfsQueue->enqueue(startVertex);

        while (!bfsQueue->isEmpty()) {
            userProfile* currentVertex = bfsQueue->dequeue();
            if (currentVertex == endVertex) {
                break;
            }
            else  cout << currentVertex->name << endl;

            NodeD* currentNode = SearchNewFriend(currentVertex->name);
            Node* currentNeighbor = currentNode->side;

            while (currentNeighbor != NULL) {
                int neighbor = currentNeighbor->user->id;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue->enqueue(currentNeighbor->user);
                }
                currentNeighbor = currentNeighbor->next;
            }
        }
        delete[] visited;
        cout << endl;
    }

    void DFS(userProfile* startVertex, string friendName) {
        if (!head)
            return;
        userProfile* endVertex = SearchNewFriend(friendName)->user;
        bool* visited = new bool[totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            visited[i] = false;
        }
        Stack* dfsStack = new Stack();
        visited[startVertex->id] = true;
        dfsStack->Push(startVertex);
        while (!dfsStack->isEmpty()) {
            userProfile* currentVertex = dfsStack->Top();
            dfsStack->Pop();
            if (currentVertex == endVertex) {
                break;
            }
            else  cout << currentVertex->name << endl;
            NodeD* currentNode = SearchNewFriend(currentVertex->name);
            Node* currentNeighbor = currentNode->side;

            while (currentNeighbor != NULL) {
                int neighbor = currentNeighbor->user->id;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dfsStack->Push(currentNeighbor->user);
                }
                currentNeighbor = currentNeighbor->next;
            }
        }

        delete[] visited;

    }
    void suggestion(userProfile* startVertex, string friendName) {
        if (!head)
            return;
        userProfile* endVertex = SearchNewFriend(friendName)->user;
        bool* visited = new bool[totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            visited[i] = false;
        }
        Stack* dfsStack = new Stack();
        visited[startVertex->id] = true;
        dfsStack->Push(startVertex);
        while (!dfsStack->isEmpty()) {
            userProfile* currentVertex = dfsStack->Top();
            dfsStack->Pop();
            if (currentVertex == endVertex) {
                break;
            }
            else  cout << currentVertex->name << endl;
            NodeD* currentNode = SearchNewFriend(currentVertex->name);
            Node* currentNeighbor = currentNode->side;

            while (currentNeighbor != NULL) {
                int neighbor = currentNeighbor->user->id;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dfsStack->Push(currentNeighbor->user);
                }
                currentNeighbor = currentNeighbor->next;
            }
        }

        delete[] visited;

    }
    void DFT(userProfile* startVertex) {
        if (!head)
            return;
        bool* visited = new bool[totalUsers];
        for (int i = 0; i < totalUsers; i++) {
            visited[i] = false;
        }
        Stack* dfsStack = new Stack();
        visited[startVertex->id] = true;
        dfsStack->Push(startVertex);
        while (!dfsStack->isEmpty()) {
            userProfile* currentVertex = dfsStack->Top();
            dfsStack->Pop();
            currentVertex->print();
            cout << endl;
            NodeD* currentNode = SearchNewFriend(currentVertex->name);
            Node* currentNeighbor = currentNode->side;

            while (currentNeighbor != NULL) {
                int neighbor = currentNeighbor->user->id;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dfsStack->Push(currentNeighbor->user);
                }
                currentNeighbor = currentNeighbor->next;
            }
        }

        delete[] visited;

    }

    int size() {
        int size = 0;
        NodeD* temp = head;
        while (temp != NULL)
        {
            size++;
            temp = temp->down;
        }
        return size;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        NodeD* current = head;
        cout << "Printing data" << "\n";
        while (current != NULL) {
            cout << "Connection with " << current->user->name << " is" << "\n";
            Node* temp = current->side;
            while (temp != NULL) {
                cout << temp->user->name << "\n";
                temp = temp->next;
            }
            current = current->down;
        }
        cout << "\n";
    }
};

NodeD* userLogin(Graph* fr) {
    cout << "Enter name: " << "\n";
    string s, p;
    cin >> s;
    NodeD* temp = fr->SearchNewFriend(s);

    if (temp != NULL) {
        cout << "Enter password: " << "\n";
        cin >> p;

        if (temp->user->password == p) {
            cout << "Welcome " << s << "\n";
            cout<< "\n";
            return temp;
        }
        else {
            cout << "Wrong password" << "\n";
        }
    }
    else {
        cout << "Your account does not exist" << "\n";
        cout << "\n";
    }

    return NULL;
}


int main() {
    Graph* fr = new Graph();
    while (1) {
        cout << "Press 0 to exit" << endl;
        cout << "Press 1 to create profile" << endl;
        cout << "Press 2 to login profile" << endl;
        cout << "Press your option" << endl;
        int input;
        cin >> input;
        if (input == 0) {
            break;
        }
        else if (input == 1) {
            int n;
            cout << "Enter the number of profiles to create: ";
            cin >> n;
            while (n--) {
                fr->CreateProfile();
            }
        }
        else if (input == 2) {
            NodeD* myPro = userLogin(fr);
            while (1) {
                cout << "Press 0 to log out" << endl;
                cout << "Press 1 to add friend" << endl;
                cout << "Press 2 to remove friend" << endl;
                cout << "Press 3 to display friends with mutual friends" << endl;
                cout << "Press 4 to show BFT and DFT" << endl;
                cout << "Press 5 to show show shortest path" << endl;
                cout << "Press 6 to find friend suggestion" << endl;
                cout << "Press your option" << endl;
                int op;
                cin >> op;
                if (op == 0) {
                    break;
                }
                else if (op == 1) {
                    if (myPro != NULL) {
                        cout << "Enter friend name to add friend: ";
                        string name;
                        cin >> name;
                        fr->addFriend(myPro->user->name, name);
                    }
                }
                else if (op == 2) {
                    cout << "Enter a friend name to remove friend: ";
                    string name;
                    cin >> name;
                    fr->removeFriend(myPro->user->name, name);
                }
                else if (op == 3) {
                    fr->displayFriends(myPro);
                }
                else if (op == 4) {
                    cout << "Showing Breadth First Traversal" << "\n";
                    fr->BFT(myPro->user);
                    cout << "Showing Depth First Traversal" << "\n";
                    fr->DFT(myPro->user);
                }
                else if (op == 5) {
                    cout << "Enter your friend name" << endl;
                    string friendName;
                    cin >> friendName;
                    cout << "Friends between your and " << friendName << endl;
                    fr->BFS(myPro->user, friendName);
                }
                else if (op == 6) {
                    fr->suggestion(myPro);
                }
                else {
                    cout << "Wrong option" << "\n";
                }
            }
        }
        else {
            cout << "Wrong option" << "\n";
        }

    }
    delete fr;
    return 0;
}