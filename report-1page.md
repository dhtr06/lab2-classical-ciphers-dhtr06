# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Bài lab nhằm mục đích triển khai bằng code C++ và hiểu sâu về nguyên lý hoạt động của hai hệ mật mã cổ điển: Caesar Cipher (mã hóa thay thế) và Rail Fence Cipher (mã hóa hoán vị). Đồng thời, sinh viên làm quen với quy trình quản lý mã nguồn, viết file logs, test cases và nộp bài tự động qua GitHub Classroom.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, dấu cách và giải mã.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Xử lý dấu cách đúng. Ký tự Y, Z lùi về đầu mảng chuẩn xác |
| hello world | 5 | mjqqt btwqi | Chữ cái viết thường (Q1) hoạt động tốt |
| LORYH BRX | 3 | I LOVE YOU | Giải mã thành công không bị lệch ký tự. |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Thuật toán bóc tách chính xác các khoảng trắng thành 1 ký tự độc lập |
| I LOVE YOU | 4 | I  EYLVOOU | Quan sát sự thay đổi chu kỳ zigzag khi số ray mở rộng lên 4 |
| IOEOLVYU | 2 | ILOVEYOU | Thuật toán giải mã ghép nối đúng các đoạn từ mảng vector |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ: Phát hiện chính xác chữ số hoặc ký tự đặc biệt
- Kết quả đọc từ `data/input.txt`:Trích xuất mượt mà bằng phương thức `getline`

## 4. Kết luận
Thông qua bài lab, em nắm được tính chất thay thế tuyến tính của Caesar và tính hoán vị không gian của Rail Fence. Khó khăn lớn nhất nằm ở phần giải mã Rail Fence (Q5) do cần phải toán học hóa sơ đồ zigzag thành việc tính chiều dài từng hàng (rail) trước khi ghép chuỗi.
