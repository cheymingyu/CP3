#include "Ban.h"

#define DEFAULT_CAPACITY 100

struct _Ban{
	int		_capacity;
	int		_size;
	int*	_elements;
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
	Ban* _this = NewObject(Ban);	// (Ban*)malloc(sizeof(Ban))

	_this->_capacity = DEFAULT_CAPACITY;	// 최대 학생 수 설정
	_this->_size = 0;						// 객체를 생성한 직후의 학생수는 0명
	_this->_elements = NewVector(int, _this->_capacity);	// 성적을 저장할 배열
	return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity) {
	Ban* _this = NewObject(Ban);	// (Ban*)malloc(sizeof(Ban))

	_this->_capacity = givenCapacity;	// 최대 학생 수 설정
	_this->_size = 0;					// 객체를 생성한 직후의 학생수는 0명
	_this->_elements = NewVector(int, _this->_capacity);	// 성적을 저장할 배열
	return _this;
}

void Ban_delete(Ban* _this) {
	free(_this->_elements);
	free(_this);
}

int		Ban_capacity(Ban* _this) {
	return (_this->_capacity);
}

int		Ban_size(Ban* _this) {
	return (_this->_size);
}

Boolean Ban_isEmpty(Ban* _this) {
	return (_this->_size == 0);
}

Boolean Ban_isFull(Ban* _this) {
	return (_this->_size >= _this->_capacity);
}

Boolean Ban_add(Ban* _this, int aScore) {
	// 성적을 배열에 저장
	if (Ban_isFull(_this)) {
		return FALSE; // 저장 공간이 부족
	}
	else {
		// 배열의 맨 마지막 위치에 넣는다.
		_this->_elements[_this->_size] = aScore;
		_this->_size ++;
		return TRUE;
	}
}

int		Ban_elementAt(Ban* _this, int anOrder) {
	if (anOrder >= _this->_size) {
		// 주어진 위치에 원소가 존재하지 않는다
		return -1;	// 음수로 존재하지 않음을 표시하기로 한다
	}
	else {
		// 원소가 정상적으로 존재한다
		return (_this->_elements[anOrder]);
	}
}

void	Ban_sortStudentByScore(Ban* _this) {
	int size = _this->_size;

	// 정렬할 데이터는 _this->_elements[0]부터 _this->elements[size-1]까지 이다
	// 퀵 정렬을 실행한다
	if (size >= 2) {	// 개수가 2 이상이면
		// 최소값의 위치를 찾는다
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (_this->_elements[i] < _this->_elements[minPosition]) {
				minPosition = i;
			}
		}
		// 최소값을 원소 구간의 맨 끝으로 옮긴다
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]);

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
	int pivotScore = _this->_elements[pivot];

	right++;
	do {
		do { left++; } while (_this->_elements[left] > pivotScore);
		do { right--; } while (_this->_elements[right] < pivotScore);
		if (left < right) {
			SWAP(int, _this->_elements[left], _this->_elements[right]);
		}
	} while (left < right);
	SWAP(int, _this->_elements[pivot], _this->_elements[right]);
	return right;
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
		return (_this->_elements[left] + Ban_sumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right) {
	// 최고점을 찾아서 return 값으로 돌려준다.
	if (left > right) {
		return 0;
	}
	else {
		int mid = Ban_partition(_this, left, right);
		Ban_maxScoreRecursively(_this, mid + 1, right);
		return _this->_elements[right];
	}
}

int Ban_minScoreRecursively(Ban* _this, int left, int right) {
	// 최저점을 찾아서 return 값으로 돌려준다.
	if (left > right) {
		return 0;
	}
	else {
		if (_this->_elements[left] < Ban_maxScoreRecursively(_this, left + 1, right)) {
			return _this->_elements[left];
		}
		else {
			return Ban_maxScoreRecursively(_this, left + 1, right);
		}
	}
}

int Ban_numberOfStudentsAboveAverage(Ban* _this) {
	float	average = Ban_averageScore(_this);
	int		numberOfStudentsAboveAverage = 0;

	for (int i = 0; i < _this->_size; i++) {
		if ((float)_this->_elements[i] >= average) {
			numberOfStudentsAboveAverage++;
		}
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter*	Ban_countGrades(Ban* _this) {
	char currentGrade;
	GradeCounter* gradeCounter = GradeCounter_new();

	for (int i = 0; i < _this->_size; i++) {
		currentGrade = Ban_scoreToGrade(_this->_elements[i]);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}