#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

// Q7: Kiểm tra đầu vào (chỉ chấp nhận chữ cái và dấu cách)
bool isValidInput(const string& text) {
    for (char c : text) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Hàm mã hóa Rail Fence
string railFenceEncrypt(const string& text, int rails) {
    if (rails <= 1) return text;
    vector<string> fence(rails, "");
    int row = 0;
    bool down = false;

    for (char c : text) {
        fence[row] += c; // Q6: Dấu cách vẫn được append bình thường
        if (row == 0 || row == rails - 1) {
            down = !down;
        }
        row += down ? 1 : -1;
    }

    string result = "";
    for (const string& r : fence) result += r;
    return result;
}

// Q5: Hàm giải mã Rail Fence
string railFenceDecrypt(const string& cipher, int rails) {
    if (rails <= 1) return cipher;
    int len = cipher.length();
    vector<int> railLens(rails, 0);
    int row = 0;
    bool down = false;

    // Bước 1: Tính số lượng ký tự rơi vào mỗi hàng (rail)
    for (int i = 0; i < len; ++i) {
        railLens[row]++;
        if (row == 0 || row == rails - 1) down = !down;
        row += down ? 1 : -1;
    }

    // Bước 2: Tái tạo các hàng từ chuỗi cipher
    vector<string> fence(rails, "");
    int idx = 0;
    for (int r = 0; r < rails; ++r) {
        fence[r] = cipher.substr(idx, railLens[r]);
        idx += railLens[r];
    }

    // Bước 3: Đọc zigzag để lấy lại thông điệp gốc
    string result = "";
    row = 0;
    down = false;
    vector<int> pointers(rails, 0);

    for (int i = 0; i < len; ++i) {
        result += fence[row][pointers[row]++];
        if (row == 0 || row == rails - 1) down = !down;
        row += down ? 1 : -1;
    }
    return result;
}

int main() {
    int choice, rails, source;
    string text = "";

    cout << "--- RAIL FENCE CIPHER ---\n";
    cout << "1. Encrypt\n2. Decrypt\nChoose (1/2): ";
    cin >> choice;

    cout << "Read text from:\n1. Keyboard\n2. File (data/input.txt)\nChoose (1/2): ";
    cin >> source;
    cin.ignore();

    if (source == 1) {
        cout << "Enter text: ";
        getline(cin, text);
    } else if (source == 2) {
        // Q8: Đọc thông điệp từ file
        ifstream infile("data/input.txt");
        if (!infile) {
            cerr << "Error: Cannot open data/input.txt. Please check the file path." << endl;
            return 1;
        }
        getline(infile, text);
        infile.close();
        cout << "[Info] Text read from file: " << text << endl;
    } else {
        cout << "Invalid source choice!" << endl;
        return 1;
    }

    // Kiểm tra đầu vào hợp lệ
    if (!isValidInput(text)) {
        cerr << "Error: Input contains invalid characters! Only letters and spaces are allowed." << endl;
        return 1;
    }

    cout << "Enter number of rails: ";
    cin >> rails;

    if (choice == 1) {
        cout << "Ciphertext: '" << railFenceEncrypt(text, rails) << "'" << endl;
    } else if (choice == 2) {
        cout << "Plaintext: '" << railFenceDecrypt(text, rails) << "'" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
