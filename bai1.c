#include <stdio.h>
#include <string.h>

#define MAX_VE 100
#define MAX_VE_PER_ORDER 4

struct VeBan {
    int maVe;
    char tenKhuVuc[20];
    float giaGoc;
    int isEarlyBird;
};

void datVeConcert(struct VeBan dsVe[], int *soLuong, struct VeBan veMoi);
void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong);

int main() {
    struct VeBan dsVe[MAX_VE];
    int soLuong = 0;

    printf("=== HỆ THỐNG ĐẶT VÉ CONCERT TICKETBOX ===\n\n");

    struct VeBan ve1 = {101, "VIP", 2000000.0f, 1};
    struct VeBan ve2 = {102, "Zone A", 1200000.0f, 0};
    struct VeBan ve3 = {103, "GA", 800000.0f, 1};
    struct VeBan ve4 = {104, "GA", 800000.0f, 0};
    struct VeBan ve5 = {105, "VIP", 2000000.0f, 0};

    datVeConcert(dsVe, &soLuong, ve1);
    datVeConcert(dsVe, &soLuong, ve2);
    datVeConcert(dsVe, &soLuong, ve3);
    datVeConcert(dsVe, &soLuong, ve4);
    datVeConcert(dsVe, &soLuong, ve5);

    printf("\n>>> KẾT QUẢ KIỂM TRA GIỎ HÀNG TRONG MAIN <<<\n");
    hienThiDanhSachVe(dsVe, soLuong);

    return 0;
}

void datVeConcert(struct VeBan dsVe[], int *soLuong, struct VeBan veMoi) {
    if (*soLuong >= MAX_VE) {
        printf("[LỖI]: Mảng lưu trữ vé của hệ thống đã đầy!\n");
        return;
    }

    if (*soLuong >= MAX_VE_PER_ORDER) {
        printf("[LỖI]: Mỗi giao dịch chỉ được phép đặt tối đa %d vé!\n", MAX_VE_PER_ORDER);
        return;
    }

    if (veMoi.isEarlyBird == 1) {
        veMoi.giaGoc = veMoi.giaGoc * 0.85f;
    }

    dsVe[*soLuong] = veMoi;
    (*soLuong)++;
    printf("[THÀNH CÔNG]: Đã thêm vé %d (%s) vào đơn hàng.\n", veMoi.maVe, veMoi.tenKhuVuc);
}

void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong) {
    if (soLuong == 0) {
        printf("[THÔNG BÁO]: Hiện chưa có vé nào được đặt thành công trong hệ thống!\n");
        return;
    }

    printf("--- DANH SÁCH VÉ ĐÃ ĐẶT (%d vé) ---\n", soLuong);
    for (int i = 0; i < soLuong; i++) {
        printf("STT: %d | Mã vé: %d | Khu vực: %s | Giá thanh toán: %.0f VND\n",
               i + 1, dsVe[i].maVe, dsVe[i].tenKhuVuc, dsVe[i].giaGoc);
    }
}