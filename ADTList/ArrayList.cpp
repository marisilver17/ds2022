#include "ArrayList.h"

void ArrayList::printList() const
{
	for (t_idx i = 0; i < size; i++)
		std::cout << data[i] << "\t";
	std::cout << '\b' << std::endl;
};

void ArrayList::makeEmpty()
{
	if (data != nullptr)
		delete [] data;
	data = nullptr;
	size = 0;
};

t_idx ArrayList::find(t_ele _val) const
{
	t_idx result = NIL;
	for (t_idx i = 0; i < size; i++)
		if (data[i] == _val)
		{
			result = i;
			break;
		}
	return result;
};

void ArrayList::insert(t_ele _val, t_idx _pos)
{
	if (_pos > size)
		_error_exit(1);
	t_ele *old_data = data;
	data = new t_ele[size + 1];
	for (t_idx i = 0; i < _pos; i++)
		data[i] = old_data[i];
	data[_pos] = _val;
	for (t_idx i = _pos + 1; i < size +1; i++)
		data[i] = old_data[i - 1]; 
	delete [] old_data;
	size++;
};

void ArrayList::remove(t_ele _val)
{
	t_idx i = find(_val);
	if (i == NIL)
		return;
	for (; i < size - 1; i++)
		data[i] = data[i + 1];
	size--;
	/// 这里从效率出发, 没有释放删除元素的空间, 仅通过 size 控制.
};

t_ele ArrayList::findKth(t_idx _pos) 
{
	if (_pos > size)
		_error_exit(1);
	return data[_pos];
};

ArrayList::~ArrayList()
{
	makeEmpty();
};

ArrayList::ArrayList(std::initializer_list<t_ele> _l)
{
	size = _l.size();
	data = new t_ele[size];
	t_idx i = 0;
	for (t_ele e : _l)
		data[i++] = e;
};

void ArrayList::_error_exit(t_err _err_code)
{
	switch (_err_code)
	{
	case 1:
		std::cerr << "The position is out of the range." << std::endl;
	default:
		makeEmpty();
		std::exit(-1);
	}
};
