# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Bài lab nhằm mục đích triển khai bằng code C++ và hiểu sâu về nguyên lý hoạt động của hai hệ mật mã cổ điển: Caesar Cipher (mã hóa thay thế) và Rail Fence Cipher (mã hóa hoán vị). Đồng thời, sinh viên làm quen với quy trình quản lý mã nguồn, viết file logs, test cases và nộp bài tự động qua GitHub Classroom.

## 2. Cách làm
- **Caesar Cipher:** Dùng hàm `isalpha()`, `isupper()`, `islower()` để kiểm tra phân loại ký tự. Chừa lại khoảng trắng `c == ' '`. Áp dụng công thức `(c - base + key) % 26 + base` để mã hóa và trừ đi `key` khi giải mã.
- **Rail Fence Cipher:** Sử dụng một cấu trúc mảng động `vector<string> fence` có kích thước bằng số rails. Dùng biến boolean `down` để thay đổi hướng đọc chuỗi theo cấu trúc zigzag.
- **Kiểm soát luồng:** Cấu hình thư viện `<fstream>` để đọc văn bản từ `data/input.txt` và quét chuỗi nhập vào để từ chối các ký tự không phải là chữ cái hoặc khoảng trắng.
- **Kiểm thử:** Biên dịch và chạy thử các test case để đối chiếu đầu ra.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Xử lý dấu cách đúng. Ký tự Y, Z lùi về đầu mảng chuẩn xác. |
| hello world | 5 | mjqqt btwqi | Chữ cái viết thường (Q1) hoạt động tốt. |
| LORYH BRX | 3 | I LOVE YOU | Giải mã thành công không bị lệch ký tự |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Thuật toán bóc tách chính xác các khoảng trắng thành 1 ký tự độc lập |
| I LOVE YOU | 4 | I  EYLVOOU | Quan sát sự thay đổi chu kỳ zigzag khi số ray mở rộng lên 4 (Q4) |
| IOEOLVYU | 2 | ILOVEYOU | Thuật toán giải mã ghép nối đúng các đoạn từ mảng vector |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:Phát hiện chính xác chữ số hoặc ký tự đặc biệt 
- Kết quả đọc từ `data/input.txt`: Trích xuất mượt mà bằng phương thức `getline`, không bị kẹt bộ nhớ đệm (buffer) của `cin`

## 4. Kết luận
Thông qua bài lab, em nắm được tính chất thay thế tuyến tính của Caesar và tính hoán vị không gian của Rail Fence. Khó khăn lớn nhất nằm ở phần giải mã Rail Fence (Q5) do cần phải toán học hóa sơ đồ zigzag thành việc tính chiều dài từng hàng (rail) trước khi ghép chuỗi. Nhờ việc gỡ rối (debug) từng bước trên giấy, em đã hiểu rõ hơn cách máy tính truy xuất bộ nhớ và xử lý string array trong C++.
