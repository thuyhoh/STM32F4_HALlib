# RTC
## I. Giới thiệu chung
### 1. Khái niệm
- Real-Time Clock(RTC) là thiết bị ngoại vi của MCU theo dõi thông tin ngày giờ hiện tại
- Miễn là điện áp cung cấp vẫn nằm trong phạm vi hoạt động,RTC không bao giờ dừng bất kể trạng thái thiết bị (Run mode, Low power mode, hoặc là reset).
### 2. đặc điểm chính RTC của STM32F4  
- lập lịch với giây phụ (sub-seconds), giây (seconds), phút (minutes), giờ (hours) (định dạng 12h hoặc 24h), ngày trong tuần (day), ngày trong tháng (day of month), tháng (month), năm(year) 
- Hai báo thức có thể lập trình với chức năng ngắt. Báo thức có thể được kích hoạt bằng bất kỳ tổ hợp nào của các trường lịch.
- Đơn vị đánh thức tự động tạo ra một cờ định kỳ kích hoạt một ngắt đánh thức tự động.
- 20 thanh ghi sao lưu(backup registers) (80 byte). Các thanh ghi sao lưu được đặt lại khi xảy ra sự kiện phát hiện giả mạo(a tamper detection event)
- Lịch STM32 RTC được cung cấp ở định dạng BCD(Binary code decimal) và nhị phân(Binary)
- RTC Quản lý tự động các tháng 28, 29 (năm nhuận), 30 và 31 ngày
### 3. RTC Block Diagram
![image](RTC_Block_Diagram.png)
### 4. RTC Clock Sources
![image](RTC_Clock_Sources.png)
- RTC cần được cung cấp 1Hz để cung cấp cho đơn vị lịch(calendar unit)
- RTC có một số bộ chia tần số trước(prescalers) cho phép cung cấp xung nhịp 1 Hz cho đơn vị lịch(calendar_unit), bất kể nguồn xung nhịp(HSE/LSE/LSI)
`` ví dụ `` : tạo ra 1hz từ các nguồn khác nhau từ các nguồn khác nhau
![image](gen1hz_ex.png)
### 5. RTC Calendar Unit
- Các trường lập lịch RTC (RTC calendar fields)
![image](RTC_calendar_fields.png)
### 6. BCD và Binary
- BCD(Binary code decimal) : dùng mã nhị phân mã hóa cho thập phân
- Binary : mã nhị phân 
![image](BCD_Binary.png)
## II. Thao tác với RTC
### 1. RTC Clock Selection
1. RTC Clock Selection Procedure
- Turn on the Required Clock (HSE/LSI/LSE)
``` C
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);

struct 
{

}RCC_OscInitTypeDef;
```
- Select the RTCCLK source as HSE/LSI/LSE in RCC_BDCR Register
``` C
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef *PeriphClkInit)
struct 
{

}RCC_PeriphCLKInitTypeDef;
``` 
### 2. RTC Init
``` C
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc);

struct 
{

}RTC_HandleTypeDef;
```
### 3. RTC Set Time and Date
``` C
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format)
```
### 4. RTC Get Time and Date
``` C
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format);
```
### 5. RTC Set/Get Alarm
### 6. RTC Deactivate Alarm
### 7. RTC Set/Deactivate Wakeup Timer
