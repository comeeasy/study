scores = {1: 88, 2: 30, 3: 61, 4: 55, 5: 95}

# scores is dictionary
for key in scores :
    if scores[key] < 60 :
        print("{0}번 학생은 {1}점으로 불합격입니다.".format(key, scores[key]))
    else :
        print("{0}번 학생은 {1}점으로 합격입니다.".format(key, scores[key]))
