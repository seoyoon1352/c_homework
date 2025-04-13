#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6
#define INTRO_LEN 300

struct Candidate {
    char name[50];
    char birth[20];
    char gender;
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[30];
    char sub_skill[30];
    int topik;
    char mbti[10];
    char intro[INTRO_LEN];
};

void printBinary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

const char* getOrdinal(int n) {
    switch(n) {
        case 1: return "첫 번째";
        case 2: return "두 번째";
        case 3: return "세 번째";
        case 4: return "네 번째";
        case 5: return "다섯 번째";
        case 6: return "여섯 번째";
        default: return "";
    }
}

int calculateAge(const char *birth) {
    int birthYear, birthMonth, birthDay;
    sscanf(birth, "%d/%d/%d", &birthYear, &birthMonth, &birthDay);

    time_t t = time(NULL);
    struct tm *current = localtime(&t);

    int age = current->tm_year + 1900 - birthYear;
    if ((current->tm_mon + 1 < birthMonth) ||
        (current->tm_mon + 1 == birthMonth && current->tm_mday < birthDay)) {
        age--;
    }
    return age;
}

int main() {
    struct Candidate c[MAX];
    char teamName[50];
    int ch, idx = 0;

    printf("####################################\n");
    printf("팀 이름을 입력하세요: ");
    while ((ch = getchar()) != '\n' && idx < sizeof(teamName) - 1) {
        teamName[idx++] = (char)ch;
    }
    teamName[idx] = '\0';

    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", teamName);
    printf("####################################\n\n");

    for (int i = 0; i < MAX; i++) {
        printf("%s 후보자의 정보를 입력합니다.\n", getOrdinal(i + 1));
        printf("---------------------------------\n");

        printf("1. 성명: ");
        fgets(c[i].name, sizeof(c[i].name), stdin);
        c[i].name[strcspn(c[i].name, "\n")] = '\0';

        printf("2. 생일(YYYY/MM/DD 형식): ");
        fgets(c[i].birth, sizeof(c[i].birth), stdin);
        c[i].birth[strcspn(c[i].birth, "\n")] = '\0';

        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &c[i].gender);
        while (getchar() != '\n');

        printf("4. 메일 주소: ");
        fgets(c[i].email, sizeof(c[i].email), stdin);
        c[i].email[strcspn(c[i].email, "\n")] = '\0';

        printf("5. 국적: ");
        fgets(c[i].nationality, sizeof(c[i].nationality), stdin);
        c[i].nationality[strcspn(c[i].nationality, "\n")] = '\0';

        printf("6. BMI: ");
        scanf("%f", &c[i].bmi);
        while (getchar() != '\n');

        printf("7. 주 스킬: ");
        fgets(c[i].main_skill, sizeof(c[i].main_skill), stdin);
        c[i].main_skill[strcspn(c[i].main_skill, "\n")] = '\0';

        printf("8. 보조 스킬: ");
        fgets(c[i].sub_skill, sizeof(c[i].sub_skill), stdin);
        c[i].sub_skill[strcspn(c[i].sub_skill, "\n")] = '\0';

        printf("9. 한국어 등급(TOPIK): ");
        scanf("%d", &c[i].topik);
        while (getchar() != '\n');

        printf("10. MBTI: ");
        fgets(c[i].mbti, sizeof(c[i].mbti), stdin);
        c[i].mbti[strcspn(c[i].mbti, "\n")] = '\0';

        printf("11. 소개: ");
        fgets(c[i].intro, sizeof(c[i].intro), stdin);
        c[i].intro[strcspn(c[i].intro, "\n")] = '\0';

        printf("=================================\n");
    }

    printf("\n####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", teamName);
    printf("####################################\n");
    printf("===============================================================================================\n");
    printf("%-16s | %-10s | %-2s | %-24s | %-6s | %-5s | %-8s | %-10s | %-6s | %-6s | %-20s\n", 
           "이름(나이)", "생년월일", "성", "메일", "국적", "BMI", "주스킬", "보조스킬", "TOPIK", "MBTI", "소개");
    printf("===============================================================================================\n");

    for (int i = 0; i < MAX; i++) {
        int age = calculateAge(c[i].birth);
        printf("%-16s(%d) | %-10s | %-2c | %-24s | %-6s | %-5.1f | %-8s | %-10s | %-6d | %-6s | %-20s\n",
               c[i].name, age, c[i].birth, c[i].gender, c[i].email, c[i].nationality,
               c[i].bmi, c[i].main_skill, c[i].sub_skill, c[i].topik, c[i].mbti, c[i].intro);
    }

    return 0;
}
