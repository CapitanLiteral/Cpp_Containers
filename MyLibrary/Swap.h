


template<class TIPUS>
void swap(TIPUS& a, TIPUS& b)
{
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	TIPUS tmp;
	tmp = a;
	a = b;
	b = tmp;
}