/**
 * @file   ArrayList.h
 * @author Wang Heyu <hywang@lemur>
 * @date   Mon Jul 11 17:17:07 2022
 * 
 * @brief 这是一个丑陋的演示版本, 如何用 Array 实现ADT List. 请勿用于
 *         任何实际应用, 对造成的包括并不限于社死等严重后果概不负责.
 *         本例子演示一个基于类的实现.
 * 
 */

#ifndef __CRAZYFISH_ARRAYLIST__
#define __CRAZYFISH_ARRAYLIST__

#include <iostream>
#include <initializer_list>
#include <cstdlib>

/// 元素的类型.
typedef double t_ele;

/// 元素下标的类型.
typedef int t_idx;

/// 出错代码类型.
typedef int t_err;

/// 代表不存在的下标位置.
#define NIL -1

class ArrayList
{
private:
	t_idx size = 0;				/**< List 的大小. */
	t_ele *data = nullptr;		/**< 存放数据的内存区域. */

	/** 
	 * 异常退出.
	 * 
	 * @param _err_code 出错代码.
	 *  1 : 越界错误.
	 * 
	 */
	void _error_exit(t_err _err_code);
public:
	/** 
	 * 默认构造函数.
	 * 
	 */
	ArrayList(){};

	/** 
	 * 初始化构造函数.
	 * 
	 * @param _l 初始化列表.
	 */
	ArrayList(std::initializer_list<t_ele> _l);

	/** 
	 * 析构函数.
	 * 
	 */
	~ArrayList();

	/** 
	 * 列出表内全部元素.
	 * 
	 */
	void printList() const;

	/** 
	 * 删除表内全部元素, 使之成为空表.
	 * 
	 */
	void makeEmpty();

	/** 
	 * 查找指定元素. 
	 * 
	 * @param _val 被查找的元素.  
	 * 
	 * @return 第一个找到的元素的位置, 如果没有找到, 返回 NIL.
	 */
	t_idx find(t_ele _val) const;
	
	/** 
	 * 在指定位置插入指定元素值. 原位置元素和一切后续元素依次后移.
	 * 
	 * @param _val 插入的元素.
	 * @param _pos 指定位置. 如果位置错误则报错. 
	 */
	void insert(t_ele _val, t_idx _pos);

	/** 
	 * 删除第一个指定元素值(如有), 一切后续元素(如有)依次前移. 
	 * 如果不存在该值元素, 则什么也不发生.
	 * 
	 * @param _val 指定元素值.
	 */
	void remove(t_ele _val);

	/** 
	 * 返回 List 的指定位置元素值.
	 * 
	 * @param _pos 指定位置.
	 * 
	 * @return 指定元素值.
	 */
	t_ele findKth(t_idx _pos);
};

#else
/// DO NOTHING.
#endif


