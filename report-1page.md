# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
- Hoàn thiện mã hóa và giải mã Caesar Cipher.
- Hoàn thiện mã hóa, giải mã và đọc file với Rail Fence Cipher.
- Ghi lại kết quả chạy thử bằng tests, logs và báo cáo.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, giữ dấu cách và giải mã đúng.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Kiểm tra các trường hợp mẫu và ghi log kết quả.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Giữ lại dấu cách trong mã hóa.
| hello world | 5 | mjqqt btwqi | Xử lý chữ thường và dấu cách.
| L ORYH BRX | 3 | I LOVE YOU | Giải mã đúng về plaintext gốc.

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Giữ dấu cách làm ký tự bình thường.
| I LOVE YOU | 4 | I  EYLVOOU | Kết quả mã hóa với 4 rail.
| ILV O OEYU | 2 | I LOVE YOU | Giải mã phục hồi thông điệp.

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ: `HELLO123` -> chương trình báo lỗi chỉ nhận chữ và dấu cách.
- Kết quả đọc từ `data/input.txt`: `I LOVE YOU` -> mã hóa Rail Fence 2 rails = `ILV O OEYU`.

## 4. Kết luận
Qua bài lab, em đã hiểu rõ hơn cách hoạt động của Caesar và Rail Fence Cipher, đặc biệt khi giữ dấu cách và xây dựng hàm giải mã. Khó khăn lớn nhất là thiết kế lại thuật toán giải mã Rail Fence để khôi phục đúng thứ tự ký tự, và việc mô phỏng lại đường đi zigzag giúp em nắm chắc hơn cấu trúc của mã.
