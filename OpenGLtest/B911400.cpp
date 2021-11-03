#include "pch.h"
#include "B911400.h"
//spotlight ����
void B911400::initialize()
{
	glEnable(GL_LIGHTING);	//���� ON
	glEnable(GL_LIGHT3);	//LIGHT3 ON
	GLfloat light_position3[] = { 1.0f, 1.0f, 1.0f, 1.0f };	//���� ��ġ ����
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
	GLfloat light_ambient2[] = { 4.0f, 4.0f, 4.0f, 4.0f };	//ambient �� ����
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient2);
	GLfloat light_spot_direction[] = { -1.0f,-1.0f,-1.0f };	//���� ���� ����
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 1.0f); //cone�� �ޱ�
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 10.0f); //concentration 
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_spot_direction);
	glEnable(GL_COLOR_MATERIAL); //�⺻ ������ ���� ����
}
//�ռ� ���� 2�� ����
void B911400::destroy()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1); 
	glDisable(GL_LIGHT5);
}

//����
void	B911400::drawSphere()
{
	//�ʷϻ����� x�� �׸���
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_LOOP);	//�� �߱�
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(-10.0f, 0.0f, 0.0f);
	glEnd();

	//���������� y�� �׸���
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);	//�� �߱�
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, -10.0f, 0.0f);
	glEnd();

	//�Ķ������� z�� �׸���
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);	//�� �߱�
	glVertex3f(0.0f, 0.0f, 10.0f);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glEnd();



	//������ü�� front�� TRIANGLE_FAN���� �� �ﰢ���� ������ �׸���(�� ���� ����:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN ����
	glColor3f(0.0f, 0.0f, 0.6f);	//���� ����
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
	//������ü�� left�� TRIANGLE_FAN���� �� �ﰢ���� ������ �׸���(�� ���� ����:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN ����
	glColor3f(0.0f, 0.0f, 0.6f);	//���� ����
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	//������ü�� right�� TRIANGLE_FAN���� �� �ﰢ���� ������ �׸���(�� ���� ����:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN ����
	glColor3f(0.0f, 0.0f, 0.6f);	//���� ����
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
	//������ü�� top�� TRIANGLE_FAN���� �� �ﰢ���� ������ �׸���(�� ���� ����:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN ����
	glColor3f(0.0f, 0.0f, 0.6f);	//���� ����
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	//������ü�� bottom�� TRIANGLE_FAN���� �� �ﰢ���� ������ �׸���(�� ���� ����:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN ����
	glColor3f(0.0f, 0.0f, 0.6f);	//���� ����
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	//������ü�� back�� TRIANGLE_FAN���� �� �ﰢ���� ������ �׸���(�� ���� ����:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN ����
	glColor3f(0.0f, 0.0f, 0.6f);	//���� ����
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glEnd();
	
	//���� 2���� 1��° ���� ����
	glEnable(GL_LIGHTING);	//���� ON
	glEnable(GL_LIGHT1);	//LIGHT1
	GLfloat light_position[] = { 0.0f, 0.0f, 1.0f, 1.0f };	//���� ��ġ ����
	GLfloat light_ambient[] = { 5.0f, 5.0f, 5.0f, 5.0f };	//ambient�� ����
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	//���� 2���� 2��° ���� ����
	glEnable(GL_LIGHTING);	//���� ON
	glEnable(GL_LIGHT5);	//LIGHT5
	GLfloat light_position2[] = { 3.0, 3.0, 6.0, 1.0 }; //���� ��ġ ����
	GLfloat light_diffuse[] = { 5.0, 5.0, 5.0, 5.0 };	//diffuse�� ����
	GLfloat mat_diffuse[] = { 3.0,3.0,3.0,3.0 };	//material�� mat_diffuse�� ����
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT5, GL_POSITION, light_position2);

	//�⺻ ������ ���� ����
	glEnable(GL_COLOR_MATERIAL);
	
	//�ռ� ���� 2�� ����
	destroy();
	
	//spotlight ����
	initialize();

	return;
}

