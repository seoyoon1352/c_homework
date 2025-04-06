// splash.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

void draw_triangles(int height);

int main(void) {
    char date[11];     // yyyy-mm-dd -> 10 chars + null
    char name[100];

    // 입력
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%10s", date);

    printf("[당신의 이름을 입력하세요]: ");
    getchar(); // 버퍼에 남은 개행 문자 제거
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // 개행 제거

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기
#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif

    // 화면 지우기
    system(CLEAR);

    // 스플래시 화면 출력
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    draw_triangles(6); // 별 삼각형

    printf("                         [마그라테아 ver 0.1]                              \n");
    printf("           풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,\n");
    printf("         사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,\n");
    printf("           마그라테아에 오신걸 환영합니다.\n\n");

    draw_triangles(6); // 별 삼각형

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s\t\t\t\t   [실행 시간]: %4.4s년 %2.2s월 %2.2s일\n", name,
           date, date + 5, date + 8);
    printf("================================================================================\n");

    return 0;
}

// 왼쪽 정 삼각형과 오른쪽 역 삼각형을 함께 출력
void draw_triangles(int height) {
    for (int i = 1; i <= height; ++i) {
        // 왼쪽 삼각형
        for (int j = 0; j < i; ++j) {
            printf("*");
        }

        // 가운데 공백
        int space = 78 - (2 * i); // 전체 폭에서 별 2개 줄어듦
        for (int j = 0; j < space; ++j) {
            printf(" ");
        }

        // 오른쪽 삼각형 (역순)
        for (int j = 0; j < height - i + 1; ++j) {
            printf("*");
        }

        printf("\n");
    }
}
