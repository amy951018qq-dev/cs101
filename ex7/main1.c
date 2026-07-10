#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n;
    srand(1);

    FILE *fp = fopen("lotto.txt", "w"); 
    
    fprintf(fp, "========= lotto649 =========\n");
    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int num[7];
            for (int j = 0; j < 7; j++) {
                int tmp;
                int repeat;
                do {
                    repeat = 0;
                    tmp = rand() % 69 + 1;
                    for (int k = 0; k < j; k++) {
                        if (num[k] == tmp) {
                            repeat = 1;
                            break;
                        }
                    }
                } while (repeat);
                num[j] = tmp;
            }

            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d", num[j]);
                if (j < 6) fprintf(fp, " ");
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "__ __ __ __ __ __ __\n");
        }
    }
    fprintf(fp, "========= csie@CGU =========\n");
    
    fclose(fp);
    
    int winning_nums[3];
    printf("請輸入中獎號碼三個: ");
    scanf("%d %d %d", &winning_nums[0], &winning_nums[1], &winning_nums[2]);

    printf("輸入中獎號碼為: %02d %02d %02d\n", winning_nums[0], winning_nums[1], winning_nums[2]);
    printf("以下為中獎彩卷:\n");

    fp = fopen("lotto.txt", "r");
    if (fp == NULL) {
        printf("錯誤: 無法開啟 lotto.txt 檔案。\n");
        return 1;
    }

    char line[256];
    
    fgets(line, sizeof(line), fp); 

    for (int i = 0; i < 5; i++) {
        char set_line[256]; 
        int ticket_nums[7];
        int set_num;
        int is_winner = 0;

        if (fgets(set_line, sizeof(set_line), fp) == NULL) {
            break; 
        }

        if (strstr(set_line, "__") != NULL) {
            continue; 
        }


        int read_count = sscanf(set_line, "[%d]: %d %d %d %d %d %d %d",
                                &set_num, &ticket_nums[0], &ticket_nums[1], 
                                &ticket_nums[2], &ticket_nums[3], &ticket_nums[4], 
                                &ticket_nums[5], &ticket_nums[6]);
        
        if (read_count == 8) {
            for (int j = 0; j < 3; j++) { 
                for (int k = 0; k < 7; k++) { 
                    if (winning_nums[j] == ticket_nums[k]) {
                        is_winner = 1;
                        break;
                    }
                }
                if (is_winner) break;
            }

            if (is_winner) {
                printf("%s", set_line);
            }
        }
    }

    fclose(fp);
    return 0;
}
