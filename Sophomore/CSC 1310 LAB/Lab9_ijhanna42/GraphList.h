#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

class GraphList {
    private:
        ListNode ** headArray;
        int numVertices;
        int numEdges;
    public:

        // constructor
        GraphList(int vertices) {
            numVertices = vertices;
            headArray = new ListNode*[numVertices];
            for (int i = 0; i < numVertices; i++) {
                headArray[i] = nullptr;
            }
        }

        // destructor
        ~GraphList() {
            for (int i = 0; i < numVertices; i++) {
                ListNode* current = headArray[i];
                while (current != nullptr) {
                    ListNode* next = current->next;
                    delete current;
                    current = next;
                }
            }
            delete[] headArray;
        }

        // addEdge function
        void addEdge(int vertex1, int vertex2) {
            ListNode* newNode = new ListNode;
            newNode->value = vertex2;
            newNode->next = headArray[vertex1];
            headArray[vertex1] = newNode;
        }

        // printGraph function
        void printGraph() {
            cout << endl << "Adjacency List..." << endl;
            for (int i = 0; i < numVertices; i++) {
                ListNode* current = headArray[i];
                cout << i << "--->";
                while (current != nullptr) {
                    cout << current->value << "--->";
                    current = current->next;
                }
                cout << "NULL" << endl;
            }
        }
};