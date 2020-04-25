#include "Ban.h"

#define DEFAULT_CAPACITY 100

typedef struct {
	int		_capacity;
	int		_size;
	int*	_elements;
} Ban;

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

	_this->_capacity = DEFAULT_CAPACITY;	// �ִ� �л� �� ����
	_this->_size = 0;						// ��ü�� ������ ������ �л����� 0��
	_this->_elements = NewVector(int, _this->_capacity);	// ������ ������ �迭
}

Ban* Ban_newWithCapacity(int givenCapacity) {
	Ban* _this = NewObject(Ban);	// (Ban*)malloc(sizeof(Ban))

	_this->_capacity = givenCapacity;	// �ִ� �л� �� ����
	_this->_size = 0;					// ��ü�� ������ ������ �л����� 0��
	_this->_elements = NewVector(int, _this->_capacity);	// ������ ������ �迭
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
	// ������ �迭�� ����
	if (Ban_isFull(_this)) {
		return FALSE; // ���� ������ ����
	}
	else {
		// �迭�� �� ������ ��ġ�� �ִ´�.
		_this->_elements[_this->_size] = aScore;
		_this->_size ++;
		return TRUE;
	}
}

int		Ban_elementAt(Ban* _this, int anOrder) {
	if (anOrder >= _this->_size) {
		// �־��� ��ġ�� ���Ұ� �������� �ʴ´�
		return -1;	// ������ �������� ������ ǥ���ϱ�� �Ѵ�
	}
	else {
		// ���Ұ� ���������� �����Ѵ�
		return (_this->_elements[anOrder]);
	}
}

void	Ban_sortStudentByScore(Ban* _this) {
	int size = _this->_size;

	// ������ �����ʹ� _this->_elements[0]���� _this->elements[size-1]���� �̴�
	// �� ������ �����Ѵ�
	if (size >= 2) {	// ������ 2 �̻��̸�
		// �ּҰ��� ��ġ�� ã�´�
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (_this->_elements[i] < _this->_elements[minPosition]) {
				minPosition = i;
			}
		}
		// �ּҰ��� ���� ������ �� ������ �ű��
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]);

		// ������ �����Ѵ�
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
	// �������� ã�Ƽ� return������ �����ش�.
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}

int		Ban_maxScore(Ban* _this) {
	// �ְ����� ã�Ƽ� return������ �����ش�.
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}

float	Ban_averageScore(Ban* _this) {
	// ����� ����Ͽ� return������ �����ش�.
	float sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size - 1);
	float average = sumOfScores / (float)_this->_size;
	return average;
}
GradeCounter*	Ban_countGrades(Ban* _this);