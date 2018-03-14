#include "widget.h"
#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace rapidjson;

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	printf("Lu//a\"\n");
	Document document;

	Document::AllocatorType& allocator = document.GetAllocator();
	Value contact(kArrayType);
	Value contact2(kArrayType);
	Value root(kArrayType);
	contact.PushBack("Lu//a\"", allocator).PushBack("Mio", allocator).PushBack("", allocator);
	contact2.PushBack("Lu// a", allocator).PushBack("Mio", allocator).PushBack("", allocator);
	root.PushBack(contact, allocator);
	root.PushBack(contact2, allocator);

	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	root.Accept(writer);
	string reststring = buffer.GetString();
	cout << reststring << endl;



}

Widget::~Widget()
{

}
