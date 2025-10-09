#include <stdio.h>

int main() {
    FILE* fp;
    
    // 原始陣列：這些是要寫入檔案的資料
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1f, 1.2f, 1.3f};

    // 接收讀取資料的新陣列：這些是用來存放從檔案讀出來的資料
    int read_a[3];
    char read_b[3];
    float read_c[3];
    
    // --- 寫入檔案 ---

    // 以二進位寫入模式 ("wb") 開啟檔案
    fp = fopen("a.bin", "wb+");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入！\n");
        return 1;
    }

    // 使用 fwrite() 將三個陣列寫入檔案
    // fwrite(資料的指標, 每個元素的位元組大小, 元素個數, 檔案指標)
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);

    // 寫入完成後，關閉檔案
    fclose(fp);
    
    // --- 讀取檔案 ---

    // 以二進位讀取模式 ("rb") 重新開啟檔案
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案進行讀取！\n");
        return 1;
    }

    // 使用 fread() 從檔案讀取資料到新的陣列中
    // fread(要存放資料的指標, 每個元素的位元組大小, 元素個數, 檔案指標)
    fread(read_a, sizeof(int), 3, fp);
    fread(read_b, sizeof(char), 3, fp);
    fread(read_c, sizeof(float), 3, fp);
    
    // 讀取完成後，關閉檔案
    fclose(fp);

    // --- 輸出驗證結果 ---
    
    // 輸出讀取到的整數陣列
    for (int i = 0; i < 3; i++) {
        printf("%d ", read_a[i]);
    }
    printf("\n");

    // 輸出讀取到的字元陣列
    for (int i = 0; i < 3; i++) {
        printf("%c ", read_b[i]);
    }
    printf("\n");
    
    // 輸出讀取到的浮點數陣列
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", read_c[i]);
    }

    return 0;
}
