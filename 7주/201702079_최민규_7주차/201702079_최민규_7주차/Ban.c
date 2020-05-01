#include "Ban.h"
#include "Student.h"

#define DEFAULT_CAPACITY 100

struct _Ban {
	int				_capacity;
	int				_size;
	Student**		_elements;
	GradeCounter*	_gradeCounter;
};

Boolean Ban_scoreIsValid(int aScore) {
	return (aScore >= 0 && aScore <= 100);
}

char	Ban_scoreToGrade(int aScore) {
	if (aScore >= 90) {
		return 'A';
	}
	else if (aScore >= 80) {
		return 'B';
	}
	else if (aScore >= 70) {
		return 'C';
	}
	else if (aScore >= 60) {
		return 'D';
	}
	else {
		return 'F';
	}
}

Ban* Ban_new(void) {
	Ban* _this = NewObject(Ban);

	_this->_capacity = DEFAULT_CAPACITY;
	_this->_size = 0;
	_this->_elements = NewVector(Student*, _this->_capacity);
	return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity) {
	Ban* _this = NewObject(Ban);

	_this->_capacity = givenCapacity;
	_this->_size = 0;
	_this->_elements = NewVector(Student*, _this->_capacity);
	return _this;
}

void Ban_delete(Ban* _this) {
	free(_this->_elements);
	free(_this);
}

int	Ban_capacity(Ban* _this) {
	return (_this->_capacity);
}

int	Ban_size(Ban* _this) {
	return (_this->_size);
}

Boolean Ban_isEmpty(Ban* _this) {
	return (_this->_size == 0);
}

Boolean Ban_isFull(Ban* _this) {
	return (_this->_size >= _this->_capacity);
}

Boolean Ban_add(Ban* _this, Student* aStudent) {
	// 성적을 배열에 저장
	if (Ban_isFull(_this)) {
		return FALSE; // 저장 공간이 부족
	}
	else {
		// 배열의 맨 마지막 위치에 넣는다.
		_this->_elements[_this->_size] = aStudent;
		_this->_size++;
		return TRUE;
	}
}

Student* Ban_elementAt(Ban* _this, int anOrder) {
	if (anOrder >= _this->_size) {
		// 주어진 위치에 원소가 존재하지 않는다
		return NULL;	// NULL로 존재하지 않음을 표시하기로 한다
	}
	else {
		// 원소가 정상적으로 존재한다
		return (_this->_elements[anOrder]);
	}
}

void Ban_sortStudentByScore(Ban* _this) {	// 성적순 정렬을 위한 공개 함수
	Ban_quickSort(_this);
}

void Ban_quickSort(Ban* _this) {	// Quick Sort를 위한 비공개 함수
	int size = _this->_size;

	// 정렬할 데이터는 _this->_elements[0]부터 _this->elements[size-1]까지 이다
	// 퀵 정렬을 실행한다
	if (size >= 2) {	// 개수가 2 이상이면
						// 최소값의 위치를 찾는다
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (Student_score(_this->_elements[i]) <
				Student_score(_this->_elements[minPosition])) {
				minPosition = i;
			}
		}
		// 최소값을 원소 구간의 맨 끝으로 옮긴다
		SWAP(Student*, _this->_elements[minPosition], _this->_elements[size - 1]);

		// 정렬을 시작한다
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}

void Ban_quickSortRecursively(Ban* _this, int left, int right) {
	if (left < right) {
		int mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid - 1);
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}

int Ban_partition(Ban* _this, int left, int right) {
	int pivot = left;
	int pivotScore = Student_score(_this->_elements[pivot]);
	int toLeft = right + 1;
	int toRight = left;

	do {
		do { toRight++; } while (Student_score(_this->_elements[toRight]) > pivotScore);
		do { toLeft--; } while (Student_score(_this->_elements[toLeft]) < pivotScore);
		if (toRight < toLeft) {
			SWAP(Student*, _this->_elements[toRight], _this->_elements[toLeft]);
		}
	} while (toRight < toLeft);
	SWAP(Student*, _this->_elements[pivot], _this->_elements[toLeft]);
	return toLeft;
}

int		Ban_minScore(Ban* _this) {
	// 최저점을 찾아서 return값으로 돌려준다.
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}

int		Ban_maxScore(Ban* _this) {
	// 최고점을 찾아서 return값으로 돌려준다.
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}

float	Ban_averageScore(Ban* _this) {
	// 평균을 계산하여 return값으로 돌려준다.
	float sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size - 1);
	float average = sumOfScores / (float)_this->_size;
	return average;
}

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right) {
	// 성적 합계를 계산하여 return 값으로 돌려준다.
	if (left > right) {
		return 0;
	}
	else {
		int score = Student_score(_this->_elements[left]);
		return (score + Ban_sumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right) {
	// 최고점을 찾아서 return 값으로 돌려준다.
	int maxOfLeftPart;
	int maxOfRightPart;
	int mid;
	int score;
	if (left == right) {
		score = Student_score(_this->_elements[left]);
		return score;
	}
	else {
		mid = (left + right) / 2;
		maxOfLeftPart = Ban_maxScoreRecursively(_this, left, mid);
		maxOfRightPart = Ban_maxScoreRecursively(_this, mid + 1, right);
		if (maxOfLeftPart >= maxOfRightPart) {
			return maxOfLeftPart;
		}
		else {
			return maxOfRightPart;
		}
	}
}

int Ban_minScoreRecursively(Ban* _this, int left, int right) {
	// 최저점을 찾아서 return 값으로 돌려준다.
	int score;
	if (left == right) {
		score = Student_score(_this->_elements[left]);
		return score;
	}
	else {
		if (Student_score(_this->_elements[left]) < Ban_minScoreRecursively(_this, left + 1, right)) {
			score = Student_score(_this->_elements[left]);
			return score;
		}
		else {
			return Ban_minScoreRecursively(_this, left + 1, right);
		}
	}
}

int Ban_numberOfStudentsAboveAverage(Ban* _this) {
	float	average = Ban_averageScore(_this);
	int		score;
	int		numberOfStudentsAboveAverage = 0;

	for (int i = 0; i < _this->_size; i++) {
		score = Student_score(_this->_elements[i]);
		if ((float)score >= average) {
			numberOfStudentsAboveAverage++;
		}
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter*	Ban_countGrades(Ban* _this) {
	char currentGrade;
	int score;
	GradeCounter* gradeCounter = GradeCounter_new();

	for (int i = 0; i < _this->_size; i++) {
		score = Student_score(_this->_elements[i]);
		currentGrade = Ban_scoreToGrade(score);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}