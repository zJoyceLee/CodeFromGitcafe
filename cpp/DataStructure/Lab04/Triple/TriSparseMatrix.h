#ifndef __TRI_SPARSE_MATRIX_H__
#define __TRI_SPARSE_MATRIX_H__

#include "Assistance.h"
#include "Triple.h"
#include <stdexcept>
#include <vector>

template<typename ElemType>
class TriSparseMatrix
{
protected:

	Triple<ElemType> *triElems;
	int maxSize;
	int rows, cols, num;

public:
	TriSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int size = DEFAULT_SIZE);
	~TriSparseMatrix();
    int GetRows() const;
    int GetCols() const;
    int GetNum() const;
	Status SetElem(int r, int c, const ElemType &v);
	Status GetElem(int r, int c, ElemType &v) const;
	TriSparseMatrix(const TriSparseMatrix<ElemType> &copy);
	TriSparseMatrix<ElemType> &operator =(const TriSparseMatrix<ElemType> &copy);
	TriSparseMatrix<ElemType> operator +(const TriSparseMatrix<ElemType> &rhs);
	void SimpleTranspose(TriSparseMatrix<ElemType> &b);
	void FastTranspose(TriSparseMatrix<ElemType> &b);
};


template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int r, int c, int size)

{
	if (r < 1 || c < 1)
		throw Error("行数或列数无效!");
	maxSize = size;
	rows = r;
	cols = c;
	num = 0;
	triElems = new Triple<ElemType>[maxSize];
}

template <class ElemType>
TriSparseMatrix<ElemType>::~TriSparseMatrix()

{
	if (triElems != NULL) delete []triElems;
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetRows() const

{
	return rows;
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetCols() const

{
	return cols;
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetNum() const

{
	return num;
}

template <class ElemType>
Status TriSparseMatrix<ElemType>::SetElem(int r, int c, const ElemType &v)


{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;

	int i, j;
	for (j = num - 1; j >= 0 &&
		(r < triElems[j].row || r == triElems[j].row && c < triElems[j].col); j--);

	if (j >= 0 && triElems[j].row == r && triElems[j].col == c)	{
		if (v == 0)	{
			for (i = j + 1; i < num; i++)
				triElems[i - 1] = triElems[i];
			num--;
		}
		else
			triElems[j].value = v;
		return SUCCESS;
	}
	else if (v != 0)	{
		if (num < maxSize)		{
			for (i = num - 1; i > j; i--)
				triElems[i + 1] = triElems[i];

			triElems[j + 1].row = r;
			triElems[j + 1].col = c;
			triElems[j + 1].value = v;
			num++;
			return SUCCESS;
		}
		else
			return OVER_FLOW;
	}
	return SUCCESS;
}

template <class ElemType>
Status TriSparseMatrix<ElemType>::GetElem(int r, int c, ElemType &v) const

{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;

	int j;


	for (j = num - 1; j >= 0 &&
		(r < triElems[j].row || r == triElems[j].row && c < triElems[j].col); j--);

	if (j >= 0 && triElems[j].row == r && triElems[j].col == c)
		v = triElems[j].value;
	else
		v = 0;
	return SUCCESS;
}

template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType> &copy)

{
	maxSize = copy.maxSize;
	triElems = new Triple<ElemType>[maxSize];
	rows = copy.rows;
	cols = copy.cols;
	num = copy.num;
	triElems = new Triple<ElemType>[maxSize];
	for (int i = 0; i < num; i++)
		triElems[i] = copy.triElems[i];
}

template <class ElemType>
TriSparseMatrix<ElemType> &TriSparseMatrix<ElemType>::operator =(const TriSparseMatrix<ElemType> &copy)
{
	if (&copy != this)	{
		maxSize = copy.maxSize;
		if (triElems != NULL) delete []triElems;
		triElems = new Triple<ElemType>[maxSize];
		rows = copy.rows;
		cols = copy.cols;
		num = copy.num;

		for (int i = 0; i < num; i++)
			triElems[i] = copy.triElems[i];
	}
	return *this;
}

template <typename ElemType>
TriSparseMatrix<ElemType> TriSparseMatrix<ElemType>::operator +(const TriSparseMatrix<ElemType> &rhs) {
//this.row == rhs.row && this.col == rhs.col
    if(!(this->GetRows() == rhs.GetRows() && this->GetCols() == rhs.GetCols())) {
        throw std::length_error("Matrix Plus requires that lhs's size == rhs's size!");
    }
//this->row == rhs.row && this->col == rhs.col do-->this->value + rhs.value ; others do nothing
    TriSparseMatrix<ElemType> ret(this->GetRows(), this->GetCols());
    for(int i = 0; i < this->num; ++i) {
        int lhs_value = this->triElems[i].value;
        int rhs_value;
        rhs.GetElem(this->triElems[i].row, this->triElems[i].col, rhs_value);
        int ret_value = lhs_value + rhs_value;
        if(ret_value != 0)
            ret.SetElem(this->triElems[i].row, this->triElems[i].col, ret_value);
    }
    for(int i = 0; i < rhs.num; ++i) {
        int rhs_value = rhs.triElems[i].value;
        int lhs_value;
        this->GetElem(rhs.triElems[i].row, rhs.triElems[i].col, lhs_value);
        int ret_value = lhs_value + rhs_value;
        if(ret_value != 0)
            ret.SetElem(rhs.triElems[i].row, rhs.triElems[i].col, ret_value);
    }

    return ret;
}


template<class ElemType>
void TriSparseMatrix<ElemType>::SimpleTranspose(TriSparseMatrix<ElemType> &b)
{
	b.rows = cols;
	b.cols = rows;
	b.num = num;
	b.maxSize = maxSize;
	delete []b.triElems;
	b.triElems = new Triple<ElemType>[b.maxSize];

	if (b.num > 0)	{
		int i = 0;
		for (int col = 0; col < cols; col++)
			for (int j = 0; j < num; j++)
				if (triElems[j].col == col)	{
					b.triElems[i].row = triElems[j].col;
					b.triElems[i].col = triElems[j].row;
					b.triElems[i].value = triElems[j].value;
					i++;
				}
	}
}

template<class ElemType>
void TriSparseMatrix<ElemType>::FastTranspose(TriSparseMatrix<ElemType> &b)
{
	b.rows = cols;
	b.cols = rows;
	b.num = num;
	b.maxSize = maxSize;
	delete []b.triElems;
	b.triElems = new Triple<ElemType>[b.maxSize];

	int *cNum = new int[cols + 1];
	int *cPos = new int[cols + 1];
	int col;
	int i;

	if (b.num > 0)	{
		for (col = 0; col < cols; col++) cNum[col] = 0;
		for (i = 0; i < num; i++)
			++cNum[triElems[i].col];
		cPos[0] = 0;
		for (col = 1; col < cols; col++)
			cPos[col] = cPos[col - 1] + cNum[col - 1];

		for (i = 0; i < num; i++){
			int j = cPos[triElems[i].col];

			b.triElems[j].row = triElems[i].col;
			b.triElems[j].col = triElems[i].row;
			b.triElems[j].value = triElems[i].value;
			++cPos[triElems[i].col];

		}
	}

	delete []cNum;
	delete []cPos;
}

#endif
