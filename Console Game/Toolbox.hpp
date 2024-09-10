#pragma once

#include <iostream>

namespace tb {
	// ���������� ��������� ����� ������������� ����� �� 0 �� end �� ������������
	unsigned rand(unsigned end); 
	// ���������� ��������� ����� ������������� ����� ��begin �� end �� ������������
	unsigned rand(unsigned begin, unsigned end); 
	// ���������� true � ������������ � percent ��������� 
	bool chance(unsigned percent); 
	// ���������� ������ � ������� �� ���������� � � �
	void place_cursor(unsigned x, unsigned y);
	// ����������� ����� � ������� �� ������� � � � 

	template <typename ANY>
	void place_text(unsigned x, unsigned y, ANY text) {
		tb::place_cursor(x, y);
		std::cout << text;
	}
	// 
	
	void place_title(unsigned x, unsigned y, std::string text, unsigned width, char space = ' ');



	//����������� �������� ������ � delay ������ �� 0 ������ � ������� �� ������� � � �.
	void place_timer(unsigned x, unsigned y, unsigned delay, const char* text = "0");
}





