student0 = (90, 80)
student1 = (85, 75)
student2 = (90, 100)

students = [student0, student1, student2]

for i, student in enumerate(students) :
    total = student[0] + student[1]
    print("{0}번 학생의 총점은 {1}점이고, 평균은 {2:.1f}입니다."\
        .format(i+1, total, total / 2))