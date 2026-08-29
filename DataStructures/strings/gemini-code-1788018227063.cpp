#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// --- Trie para Strings con Conteo y Borrado ---
struct TrieNode {
    map<char, int> hijos;
    int cnt = 0; // Cantidad de palabras que pasan por este nodo
    bool term = false;
};

struct StringTrie {
    vector<TrieNode> trie;

    StringTrie() {
        trie.push_back(TrieNode()); // Raíz en índice 0
    }

    void insertar(const string& s) {
        int u = 0;
        trie[u].cnt++;
        for (char c : s) {
            if (!trie[u].hijos.count(c)) {
                trie[u].hijos[c] = trie.size();
                trie.push_back(TrieNode());
            }
            u = trie[u].hijos[c];
            trie[u].cnt++;
        }
        trie[u].term = true;
    }

    void borrar(const string& s) {
        int u = 0;
        trie[u].cnt--;
        for (char c : s) {
            u = trie[u].hijos[c];
            trie[u].cnt--;
        }
    }

    int contar_prefijo(const string& p) {
        int u = 0;
        for (char c : p) {
            if (!trie[u].hijos.count(c) || trie[trie[u].hijos[c]].cnt == 0) {
                return 0;
            }
            u = trie[u].hijos[c];
        }
        return trie[u].cnt;
    }
};

// --- Binary Trie para Max XOR (Problema Vasiliy's Multiset) ---
struct BinaryTrieNode {
    int hijos[2] = {-1, -1};
    int cnt = 0;
};

struct BinaryTrie {
    vector<BinaryTrieNode> trie;

    BinaryTrie() {
        trie.push_back(BinaryTrieNode());
    }

    void insertar(int x) {
        int u = 0;
        trie[u].cnt++;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (trie[u].hijos[bit] == -1) {
                trie[u].hijos[bit] = trie.size();
                trie.push_back(BinaryTrieNode());
            }
            u = trie[u].hijos[bit];
            trie[u].cnt++;
        }
    }

    void borrar(int x) {
        int u = 0;
        trie[u].cnt--;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            u = trie[u].hijos[bit];
            trie[u].cnt--;
        }
    }

    int max_xor(int x) {
        int u = 0;
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            int opuesto = 1 - bit;
            if (trie[u].hijos[opuesto] != -1 && trie[trie[u].hijos[opuesto]].cnt > 0) {
                res |= (1 << i);
                u = trie[u].hijos[opuesto];
            } else {
                u = trie[u].hijos[bit];
            }
        }
        return res;
    }
};

int main() {
    // Ejemplo String Trie
    StringTrie st;
    st.insertar("cama");
    st.insertar("coma");
    st.insertar("marco");
    st.insertar("marcha");
    cout << "Palabras con prefijo 'mar': " << st.contar_prefijo("mar") << "\n"; // 2

    // Ejemplo Binary Trie
    BinaryTrie bt;
    bt.insertar(0);
    bt.insertar(8);
    bt.insertar(9);
    bt.insertar(11);
    cout << "Max XOR con 3: " << bt.max_xor(3) << "\n"; // 3 ^ 8 = 11

    return 0;
}