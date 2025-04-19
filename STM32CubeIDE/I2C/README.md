# I2C

## I. Giới thiệu chung
### 1. Khái niệm 
- I2C viết tắt của Inter- Integrated Circuit  là một phương thức giao tiếp được phát triển bởi hãng Philips Semiconductors. Dùng để truyền tín hiệu giữa vi xử lý và các IC trên các bus nối tiếp.
### 2. Đặc điểm Đặc điểm:
- Tốc độ không cao
- Thường sử dụng onboard với đường truyền ngắn
- Nối được nhiều thiết bị trên cùng một bus
- Giao tiếp đồng bộ, sử dụng Clock từ master
- Sử dụng 7 bit hoặc 10 bit địa chỉ
- Chỉ sử dụng 2 chân tín hiệu SDA, SCL
- Có 2 tốc độ tiêu chuẩn là Standard mode (100 kb/s)và Low mode (10 kbit/s)
### 3. Kết nối I2C
#### a. Kết nối vật lý
![image](i2c_connect.jpg)
#### b. Chế đô kết nối
- có 3 chế độ kết nối chính
  - Một master nhiều slave
  - nhiều master nhiều slave
  - một master một slave
### 5. Truyền dữ liệu trong giao thức
#### a. Cấu trúc khung dữ liệu
![image](i2c_dataframe.jpg)
##### start Condition
- khi thiết bị master bắt đầu một phiên truyền 
  - SDA chuyển từ mức cao xuống mức thấp, sau đó SCL thức hiện tương tự
  - Tất cả các thiết bị Slave hoạt động ngay cả chung ở chế độ ngủ và đợi khớp địa chỉ
![image](i2c_StartCondition.jpg)
##### 7 Address bits 
- chứa 7 bits địa chỉ của slave 
##### R/W bit
- xác định đượng truyền dữ liệu 
  - Nếu Master muốn nhận dữ liệu của slave thì bit này được set lên 1
  - Nếu Master muốn gửi dữ liệu đến slave thì bit này được đặt về 0
##### ACK/NACK bit
- Nếu dữ liệu truyền thất bại(không khớp với 7 bits địa chỉ) ACK/NACK bit được đặt về 0 
- Nếu dữ liệu truyền thành công(khớp với 7 bits địa chỉ) ACK/NACK bit được set lên 1 
##### stop Condition
- Sau khi các khung dữ liệu cần thiết được truyền qua SDA, thiết bị chuyển SDA từ mức thấp lên mức cao sau đó SCL chuyển từ mức cao xuông thấp
## II. Thiết lập I2C ở mức độ thanh ghi 

## III. API 
``` C
/**
 * @brief: thực hiện truyền dữ liệu pData I2C cho thiết bị có địa chỉ Devaddress từ địa chỉ MemAddress
 * @param:
*/
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```

