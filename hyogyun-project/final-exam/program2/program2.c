// =====================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// =====================================================================

#define STUDENT_UTF "student(UTP-8).txt"
#define STUDENT_OUT "student_new.txt"
#define NUM_WORD    20
#define WORD_SIZE 10000

// =====================================================================

#define SWAP(x, y, t)  ((t)=(x)), ((x)=(y)), ((y)=(t))

// =====================================================================

typedef struct _student {
    int number;             // 학번
    char name[WORD_SIZE];   // 이름
    int mid;                // 중간
    int final;              // 기말
    int attendance;         // 출석률
    double total;           // 총점
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
            if(students[to_insert].total > students[to_insert-1].total)
                SWAP(students[to_insert], students[to_insert-1], tmp);
        }
    }
}

void calculate_total(Student students[]) {
    double total;

    for(int i=0; i<NUM_WORD; ++i) {
        total = 0.0;
        // 기말 * 0.45
        total += (students[i].mid) * 0.45;
        // 중간 * 0.45
        total += (students[i].final) * 0.45;
        // 출결
        total += (students[i].attendance);

        students[i].total = total;
    }
}

void get_grade(Student students[]) {
    char buf[WORD_SIZE];
    FILE* fp;

    // 파일을 읽음으로 읽고 
    if( (fp = fopen(STUDENT_UTF, "r")) == NULL ) { 
        printf("file open error\n");
        return;   
    }

    // 학번 이름 ... 순위 버리기
    for(int i=0; i<8; ++i) {
        fscanf(fp, "%s", buf);
        printf("%s\n", buf);
    }

    for(int i=0; i<NUM_WORD; ++i) {
        printf("i = %d\n", i);

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

        printf("%d %s %d %d %d\n", students[i].number, students[i].name, students[i].mid,
                    students[i].final, students[i].attendance);
    }

    fclose(fp);
}

void write_grade(Student students[]) {
    FILE* fp = fopen(STUDENT_OUT, "w" );
    if(fp == NULL) {
        printf("write file open error\n");
        return;
    }

    fprintf(fp, "학번\t\t이름\t중간고사(45%%)\t기말고사(45%%)\t출결(10%%)\t\t총점\t순위\n");
    fprintf(fp, "============================================================================================\n");

    for(int i=0; i<NUM_WORD; ++i) {
        fprintf(fp, "%d\t%s\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t%.2lf\t\t%d\n",
            students[i].number, students[i].name, students[i].mid,
            students[i].final, students[i].attendance, students[i].total,
            students[i].rank);
    }

    fclose(fp);
}

// =====================================================================

int main() {
    Student students[NUM_WORD];

    get_grade(students);
    printf("get_grade\n");

    calculate_total(students);
    printf("calculate_total\n");

    insertion_sort(students, NUM_WORD);
    for(int i=0; i<NUM_WORD; ++i) students[i].rank = i+1;
    printf("sorting\n");
    
    write_grade(students);
    printf("write\n");

    return 0;
}

// =====================================================================