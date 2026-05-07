#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Hàm mã hóa Caesar
string caesarEncrypt(const string& text, int key) {
    string result = "";
    key = key % 26; // Đảm bảo key nằm trong khoảng 0-25
    for (char c : text) {
        if (isalpha(c)) {
            // Q1: Hỗ trợ cả chữ thường và chữ hoa
            char base = isupper(c) ? 'A' : 'a';
            result += char((c - base + key) % 26 + base);
        } else if (c == ' ') {
            // Q2: Giữ nguyên dấu cách
            result += c;
        } else {
            result += c; // Giữ nguyên các ký tự đặc biệt nếu có
        }
    }
    return result;
}

// Hàm giải mã Caesar (Q3)
string caesarDecrypt(const string& text, int key) {
    string result = "";
    key = key % 26;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // Cộng thêm 26 trước khi modulo để tránh số âm trong C++
            result += char((c - base - key + 26) % 26 + base);
        } else if (c == ' ') {
            result += c; // Giữ nguyên dấu cách
        } else {
            result += c; 
        }
    }
    return result;
}

int main() {
    int choice, key;
    string text;

    cout << "--- CAESAR CIPHER ---\n";
    cout << "1. Encrypt\n2. Decrypt\nChoose (1/2): ";
    cin >> choice;
    cin.ignore(); // Xóa ký tự newline trong buffer

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key: ";
    cin >> key;

    if (choice == 1) {
        cout << "Ciphertext: " << caesarEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Plaintext: " << caesarDecrypt(text, key) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
