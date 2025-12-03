#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using namespace std;

// 1. Клас Node (Вузол Дерева)
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}

    Node(const Node& other) : data(other.data) {
        left = other.left ? new Node(*other.left) : nullptr;
        right = other.right ? new Node(*other.right) : nullptr;
    }

    ~Node() {
    }
};

// 2. Клас BinaryTree (Дерево)
class BinaryTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }
        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }
        return current;
    }

    void displayInOrder(Node* node) const {
        if (node != nullptr) {
            displayInOrder(node->left);
            cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    void clearRecursive(Node* node) {
        if (node != nullptr) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

    int getHeightRecursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeightRecursive(node->left);
        int rightHeight = getHeightRecursive(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

    int countNodesRecursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodesRecursive(node->left) + countNodesRecursive(node->right);
    }

public:
    // Конструктор за замовчуванням
    BinaryTree() : root(nullptr) {}

    // Конструктор з параметрами
    BinaryTree(int rootValue) {
        root = new Node(rootValue);
    }

    // Конструктор копіювання
    BinaryTree(const BinaryTree& other) : root(nullptr) {
        if (other.root != nullptr) {
            root = new Node(*other.root);
        }
    }

    // Деструктор
    ~BinaryTree() {
        clear();
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // ВИПРАВЛЕННЯ: Додано 'void' перед display()
    void display() const {
        if (root == nullptr) {
            cout << "Дерево порожнє." << endl;
            return;
        }
        cout << "Елементи дерева (In-order): ";
        displayInOrder(root);
        cout << endl;
    }

    void clear() {
        clearRecursive(root);
        root = nullptr;
    }

    void printStructureInfo() const {
        cout << "\n--- Інформація про структуру дерева ---" << endl;
        if (root == nullptr) {
            cout << "Статус: Дерево порожнє." << endl;
            return;
        }
        cout << "Кореневий вузол: " << root->data << endl;
        cout << "Загальна кількість вузлів: " << countNodesRecursive(root) << endl;
        cout << "Висота (глибина) дерева: " << getHeightRecursive(root) << endl;
        cout << "Статус: " << (isBalanced() ? "Збалансоване" : "Незбалансоване") << " (приблизно)." << endl;
    }

    bool isBalanced() const {
        if (root == nullptr) return true;

        int leftHeight = getHeightRecursive(root->left);
        int rightHeight = getHeightRecursive(root->right);

        return abs(leftHeight - rightHeight) <= 1;
    }
};

// Головна функція для демонстрації
void Lab_13() {
    BinaryTree tree1;

    cout << "=== 1. Демонстрація Tree 1 (Конструктор за замовчуванням) ===" << endl;

    tree1.insert(50);
    tree1.insert(30);
    tree1.insert(70);
    tree1.insert(20);
    tree1.insert(40);
    tree1.insert(60);
    tree1.insert(80);

    tree1.display();
    tree1.printStructureInfo();

    // 2. Конструктор копіювання
    cout << "\n=== 2. Демонстрація Tree 2 (Конструктор копіювання) ===" << endl;
    BinaryTree tree2 = tree1;

    // Перевірка незалежності
    tree2.insert(10);

    cout << "Tree 1 (Оригінал): ";
    tree1.display();

    cout << "Tree 2 (Копія):   ";
    tree2.display();
    tree2.printStructureInfo();

    cout << "\n=== 3. Демонстрація Очищення ===" << endl;
    tree1.clear();
    cout << "Tree 1 після очищення: ";
    tree1.display();

    cout << "\n=== 4. Демонстрація Tree 3 (Конструктор з параметром) ===" << endl;
    BinaryTree tree3(100);
    tree3.insert(50);
    tree3.display();

    return;
}