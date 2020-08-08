// =====================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// =====================================================================

#define STUDENT_ANSI "student.txt"          // 불러 읽을 파일명, ANSI 형식 사용
#define STUDENT_OUT  "student_new.txt"       // 입력할 파일의 파일명
#define WORD_SIZE    1024                    // 읽을 단어의 최대 크기
#define NUM_WORD     20                      // 학생들의 수

// =====================================================================

// swap 매크로 t는 tmp로 매크로를 호출할 때 필요한 tmp변수를 선언해야함
#define SWAP(x, y, t)  ((t)=(x)), ((x)=(y)), ((y)=(t))

// =====================================================================

typedef struct _student {
    int number;             // 학번
    char name[WORD_SIZE];   // 이름
    int mid;                // 중간
    int final;              // 기말
    int attendance;         // 출석률
    int total;           // 총점 * 100 (동점자 비교를 위해서 입력할 때 100으로 나누어  입력)
    int rank;               // 순위
} Student;

// =====================================================================

// 모든 학생의 총점을 계산
void calculate_total(Student students[]);
// "student(UTP-8)" 에서 값들을 불러옴
void get_grade(Student students[]);
// "student_new.txt" 로 파일 작성
void write_grade(Student students[]);
// 총점을 기준으로 정렬
void insertion_sort(Student student[], int n);

// =====================================================================

void insertion_sort(Student students[], int n) {
    Student tmp;

    for(int unsorted=1; unsorted<n; ++unsorted) {
        for(int to_insert=unsorted; to_insert>0; --to_insert) {
            // 총점에 대한 비교 총점이 더 크다면 swap
            if(students[to_insert].total > students[to_insert-1].total) {
                SWAP(students[to_insert], students[to_insert-1], tmp);
            }
            // 총점이 같다면 기말점수로 정렬 
            // double 끼리는 비교가 굉장히 까다롭기 때문에 정수형으로 계산하고 나중에 100으로 나누어 줌
            else if( students[to_insert].total == students[to_insert-1].total ) {
                if( students[to_insert].final > students[to_insert-1].final ) {
                    SWAP(students[to_insert], students[to_insert-1], tmp);
                }
            }
        }
    }
}

void calculate_total(Student students[]) {
    int total;

    // 나중에 100으로 나누어줌
    for(int i=0; i<NUM_WORD; ++i) {
        total = 0.0;
        // 기말 * 0.45 
        total += (students[i].mid) * 45;
        // 중간 * 0.45
        total += (students[i].final) * 45;
        // 출결
        total += (students[i].attendance) * 100;

        students[i].total = total;
    }
}

void get_grade(Student students[]) {
    char buf[WORD_SIZE];
    FILE* fp;

    // 파일을 읽음으로 읽고 
    if( (fp = fopen(STUDENT_ANSI, "r")) == NULL ) { 
        printf("file open error\n");
        return;   
    }

    // 학번 이름 ... 순위 버리기
    for(int i=0; i<8; ++i) fscanf(fp, "%s", buf);

    // 필요한 데이터 불러 읽기
    for(int i=0; i<NUM_WORD; ++i) {
        // get number
        fscanf(fp, "%d", &students[i].number);
        // get name
        fscanf(fp, "%s", students[i].name);
        // get mid
        fscanf(fp, "%d", &students[i].mid);
        // get final
        fscanf(fp, "%d", &students[i].final);
        // get attendance
        fscanf(fp, "%d", &students[i].attendance);
        fscanf(fp, "%s", buf);
        fscanf(fp, "%s", buf);
    }

    fclose(fp);
}

void write_grade(Student students[]) {
    FILE* fp = fopen(STUDENT_OUT, "w" );
    if(fp == NULL) {
        printf("write file open error\n");
        return;
    }

    // 형식에 맞추어 파일 입력
    fprintf(fp, "학번\t\t이름\t중간고사(45%%)\t기말고사(45%%)\t출결(10%%)\t총점\t\t순위\n");
    fprintf(fp, "============================================================================================\n");

    for(int i=0; i<NUM_WORD; ++i) {
        fprintf(fp, "%d\t%s\t%d\t\t%d\t\t%d\t\t%.2f\t\t%d\n",
            students[i].number, students[i].name, students[i].mid,
            students[i].final, students[i].attendance, students[i].total / 100.0,
            students[i].rank);
    }

    fclose(fp);
}

// =====================================================================

int main() {
    Student students[NUM_WORD];

    // stduents array에 파일에서 값을 불러들여와서 저장
    // UTF-8 형식의 파일을 사용할 것임
    get_grade(students);

    // 총점 계산
    calculate_total(students);

    // 정렬
    insertion_sort(students, NUM_WORD);
    // 정렬 된 순서대로 순위를 매겨줌
    for(int i=0; i<NUM_WORD; ++i) students[i].rank = i+1;
    
    // 정렬 된 students를 파일 입력
    write_grade(students);

    return 0;
}

// =====================================================================