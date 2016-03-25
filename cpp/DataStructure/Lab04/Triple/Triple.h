#ifndef __TRIPLE_H__
#define __TRIPLE_H__

template<class ElemType>
struct Triple
{
	int row, col;
	ElemType value;

	Triple();
	Triple(int r, int c, ElemType v);
};

template<class ElemType>
Triple<ElemType>::Triple()
{
}

template<class ElemType>
Triple<ElemType>::Triple(int r, int c, ElemType v)
{
	row = r;
	col = c;
	value = v;
}

#endif

