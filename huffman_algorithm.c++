#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return (left->freq > right->freq);
    }
};

void encode(Node* root, string str, string huffmanCode[]) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text) {
    int freq[256] = {0}; // Assuming ASCII characters
    for (char c : text) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            pq.push(new Node(i, freq[i]));
        }
    }

    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        int sumFreq = left->freq + right->freq;
        pq.push(new Node('\0', sumFreq));
    }

    Node* root = pq.top();

    string huffmanCode[256];
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are: " << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            cout << (char)i << " : " << huffmanCode[i] << endl;
        }
    }
}

int main() {
    string text = "Huffman coding is a data compression algorithm.";
    buildHuffmanTree(text);
    return 0;
}
