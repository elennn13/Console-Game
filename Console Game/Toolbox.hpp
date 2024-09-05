#pragma once


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
	void place_text(unsigned x, unsigned y, const char* text);
	//����������� �������� ������ � delay ������ �� 0 ������ � ������� �� ������� � � �.
	void place_timer(unsigned x, unsigned y, unsigned delay, const char* text = "0");
}





