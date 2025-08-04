#include <iostream>

class Node {
    public:
        int data;
        void* next;
        Node(int value) {
            data = value; 
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int size;
    public:
        LinkedList() {
            size = 0;
            head = nullptr;
        }
        Node* get_node(int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            if (index == 0) {
                return head;
            }
            Node* current_node = head;
            int i = 0;
            while (i < index) {
                current_node = (Node*)current_node->next;
                i++;
            }
            return current_node;
        }
        Node* find(int data) {
            Node* current_node = head;
            while (current_node != nullptr) {
                if (current_node->data == data) {
                    return current_node; // Found the data
                }
                current_node = (Node*)current_node->next;
            }
            return nullptr; // Data not found
        }
        int index(int data) {
            Node* current_node = head;
            int i = 0;
            while (current_node != nullptr) {
                if (current_node->data == data) {
                    break; // Found the data
                }
                i++;
                current_node = (Node*)current_node->next;
            }
            if (i >= size) {
                return -1; // Data not found
            }
            return i;
        }
        void push(int data) {
            if (size == 0) {
                head = new Node(data);
                size++;
                return;
            }
            Node* last_node = get_node(size-1);
            last_node->next = new Node(data);
            size++;
        }
        void push(int data, int index) {
            Node* previous_node = get_node(index-1);
            Node* next_node = (Node*)previous_node->next;
            previous_node->next = new Node(data);
            ((Node*)previous_node->next)->next = next_node;
            size++;
        }
        void remove(int data) {
            Node* target_node_parent = get_node(index(data) - 1);
            target_node_parent->next = ((Node*)target_node_parent->next)->next;
            size--;
        }
        Node* pop(int index) {
            Node* target_node_parent = get_node(index - 1);
            Node* target_node = (Node*)target_node_parent->next;
            target_node_parent->next = ((Node*)target_node_parent->next)->next;
            size--;
            return target_node;
        }
        void print() {
            Node* current_node = head;
            while (current_node != nullptr) {
                std::cout << current_node->data << " -> ";
                current_node = (Node*)current_node->next;
            }
            std::cout << "nullptr" << std::endl;
        }
};

int main() {
    std::cout << "Linked List Example" << std::endl;
    LinkedList list = LinkedList();
    std::cout << "List initialized.\nAdding elements to list." << std::endl;
    list.push(1);
    list.print();
    list.push(2);
    list.print();
    list.push(3);
    list.print();
    list.push(4);
    list.print();
    list.push(5);
    list.print();
    list.remove(3);
    list.print();
    list.push(6, 2);
    list.print();
    return 0;
}